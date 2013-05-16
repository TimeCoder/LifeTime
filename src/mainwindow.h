//
// This file is part of the LifeTime project
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE in the top directory of
// the source code.
//
// Copyright 2013      Igor Zimaev   <i.zimaev@timeacademy.ru>
//

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
    
public:
    void on_render();
    void on_sliderTime_sliderPressed();
    void on_sliderTime_valueChanged(int value);
    void on_sliderTime_sliderReleased();
    void on_btnLeap_clicked();
    void on_btnOn_clicked();
    void on_updateReadings(const Readings&);
    void on_loopEnd();

    void showSettingsDialog();
    void showInfoDialog();
    void restartSimulation();
    void playSimulation();
    void pauseSimulation();

protected:
    void resizeEvent(QResizeEvent* e);

private:
    void start();
    bool pause() const;
    void setPause(const bool pause);
    void enableControls();

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

};

#endif // MAINWINDOW_H
