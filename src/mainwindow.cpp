#include <QTimer>
#include <QResizeEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timemodel.h"
#include "lifeview.h"
#include "timeview.h"
#include "settings.h"
#include "settingsui.h"
#include "infoui.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  m_pause(false),
  m_tmOn(false),
  m_tmBlocked(false),
  m_choosedObject(false),
  m_choosedTime(false)
{
    m_timeModel = new TimeModel();
    m_timeView  = new TimeView(this);
    m_lifeView  = new LifeView(this);

    //
    // setup UI
    //
    ui->setupUi(this);
    ui->verticalLayout_1->addWidget(m_timeView);
    ui->verticalLayout_2->addWidget(m_lifeView);

    m_readingsUI.init(ui->treeWidget);

    ui->comboFlow->addItem("r0 - trunk");
    ui->comboFlow->addItem("r1 - branch");
    ui->comboFlow->setCurrentIndex(0);

    //
    // Setup timer
    //
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::on_render);

    //
    // bind models and views
    //
    connect(m_timeModel, &TimeModel::worldChanged,
            m_lifeView,  &LifeView::renderNewWorld);

    connect(m_timeModel, &TimeModel::timeChanged,
            m_timeView,  &TimeView::renderNewFlow);

    connect(m_timeModel, &TimeModel::readingsUpdated,
            this,        &MainWindow::on_updateReadings);

    connect(m_timeModel, &TimeModel::loopFinished,
            this,        &MainWindow::on_loopEnd);

    connect(m_lifeView,  &LifeView::cellActivated,
            m_timeModel, &TimeModel::chooseObject);

    connect(ui->comboFlow, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            m_timeModel,   &TimeModel::switchFlow);

    // run
    start();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete m_lifeView;
    delete m_timeView;
    delete m_timeModel;
}


void MainWindow::resizeEvent(QResizeEvent* e)
{
    m_timeView->setMaximumHeight(e->size().height() * 0.2);
    m_lifeView->setMaximumHeight(e->size().height() * 0.8);
}


void MainWindow::start()
{
    m_timeModel->bigBan(Settings::instance().worldRows,
                        Settings::instance().worldCols,
                        Settings::instance().worldRows *
                        Settings::instance().worldCols *
                        (double)Settings::instance().initFilling/100.f);

    if (m_timer->isActive()) m_timer->stop();
    m_timer->start(1.0 / Settings::instance().desiredFPS * 1000);

    m_pause = false;
    m_tmOn = false;
    m_tmBlocked = false;
    m_choosedObject = false;
    m_choosedTime = false;

    enableControls();
}


bool MainWindow::pause() const
{
    return m_pause;
}


void MainWindow::setPause(const bool pause)
{
    m_pause = pause;
}


void MainWindow::on_render()
{
    if (!m_pause && !m_tmOn)
    {
        m_timeModel->next();

        ui->lcd1->display(m_timeModel->curTime());
        ui->lcd2->display(m_timeModel->maxTime());
    }
}


void MainWindow::enableControls()
{
    ui->sliderTime->setEnabled(m_tmOn && m_choosedObject);
    ui->labelChooseObject->setEnabled(m_tmOn && !m_choosedObject);
    ui->labelChooseDate->setEnabled(m_tmOn && m_choosedObject && !m_choosedTime);

    m_lifeView->fixObject(!m_tmOn);

    ui->btnOn->setEnabled(!m_tmOn && !m_tmBlocked && !m_choosedTime);
    ui->btnLeap->setEnabled(m_tmOn && m_choosedTime);

    ui->labelFlow->setEnabled(m_tmBlocked);
    ui->comboFlow->setEnabled(m_tmBlocked);
}


void MainWindow::on_btnOn_clicked()
{
    ui->sliderTime->setMaximum(m_timeModel->curTime());
    ui->sliderTime->setValue(m_timeModel->curTime());
    m_tmOn = true;

    enableControls();
}


void MainWindow::on_sliderTime_sliderPressed()
{
    enableControls();
}


void MainWindow::on_sliderTime_valueChanged(int value)
{
    m_timeModel->showPast(value);
    ui->lcd1->display(value);    
}


void MainWindow::on_sliderTime_sliderReleased()
{
    m_choosedTime = true;
    enableControls();
}


void MainWindow::on_btnLeap_clicked()
{
    m_timeModel->gotoPast(ui->sliderTime->value());
    m_tmOn = false;
    enableControls();
}


void MainWindow::on_updateReadings(const Readings& readings)
{
    m_choosedObject = (readings.objectSizeAbs > 0);
    m_readingsUI.update(readings);
    enableControls();
}


void MainWindow::on_loopEnd()
{
    // only one travel in past!
    m_tmBlocked = true;
    pauseSimulation();
}


void MainWindow::showSettingsDialog()
{
    bool wasPause = m_pause;
    if (!m_pause) pauseSimulation();
    SettingsUI dlg;
    dlg.exec();
    if (!wasPause) playSimulation();
}


void MainWindow::restartSimulation()
{
    start();
}


void MainWindow::playSimulation()
{
    m_pause = false;
    ui->actionPlay->setEnabled(false);
    ui->actionPause->setEnabled(true);
}


void MainWindow::pauseSimulation()
{
    m_pause = true;
    ui->actionPause->setEnabled(false);
    ui->actionPlay->setEnabled(true);
}


void MainWindow::showInfoDialog()
{
    bool wasPause = m_pause;
    if (!m_pause) pauseSimulation();
    InfoUI dlg;
    dlg.exec();
    if (!wasPause) playSimulation();
}


