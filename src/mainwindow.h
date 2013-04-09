///////////////////////////////////////////////////////////////////////////////
//  MainWindow - main app window
//
//  Project: "LifeTime"  (life.timeacademy.ru)
//  Autor: Zimaev Igor (i.zimaev@timeacademy.ru)
///////////////////////////////////////////////////////////////////////////////
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "world.h"
#include "readingsui.h"

namespace Ui {
class MainWindow;
}

class TimeModel;
class LifeView;
class TimeView;
class QTreeWidgetItem;
class Readings;
class QTimer;

//
class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(bool pause READ pause WRITE setPause)

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_render();
    void on_sliderTime_sliderPressed();
    void on_sliderTime_valueChanged(int value);
    void on_sliderTime_sliderReleased();
    void on_btnLeap_clicked();
    void on_btnOn_clicked();
    void on_updateReadings(const Readings&);
    void on_loopEnd();

    void on_actionSettings_triggered();
    void on_actionRestart_triggered();
    void on_actionPlay_triggered();
    void on_actionPause_triggered();


    void on_actionInfo_triggered();

private:
    Ui::MainWindow* ui;
    TimeModel* m_timeModel;
    LifeView*  m_lifeView;
    TimeView*  m_timeView;
    bool       m_pause;
    bool       m_tmOn;
    bool       m_tmBlocked;
    bool       m_choosedObject;
    bool       m_choosedTime;
    QTimer*    m_timer;

    ReadingsUI m_readingsUI;

private:
    void start();
    void resizeEvent(QResizeEvent* e);

    bool pause() const;
    void setPause(const bool pause);

    void enableControls();
};

#endif // MAINWINDOW_H
