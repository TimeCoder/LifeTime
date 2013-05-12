#include <QSettings>
#include "settingsui.h"
#include "ui_settingsui.h"
#include "settings.h"

SettingsUI::SettingsUI(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::SettingsUI)
{
    ui->setupUi(this);

    ui->spinWorldCols->setValue(Settings::instance().worldCols);
    ui->spinWorldRows->setValue(Settings::instance().worldRows);
    ui->spinDesiredFPS->setValue(Settings::instance().desiredFPS);
    ui->spinInitFilling->setValue(Settings::instance().initFilling);
}

SettingsUI::~SettingsUI()
{
    delete ui;
}

void SettingsUI::on_pushOK_clicked()
{
    Settings::instance().worldCols = ui->spinWorldCols->value();
    Settings::instance().worldRows = ui->spinWorldRows->value();
    Settings::instance().desiredFPS = ui->spinDesiredFPS->value();
    Settings::instance().initFilling = ui->spinInitFilling->value();

    close();
}
