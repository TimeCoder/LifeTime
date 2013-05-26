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
struct Readings;
class QTimer;

//
class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(bool pause READ pause WRITE setPause)

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
protected slots:
    void renderNext();
    void timeMachineOn();
    void timeMachineReady();
    void timeMachineLock();

    void showPast(int time);
    void timeLeap();

    void updateReadings(const Readings&);

    void showSettingsDialog();
    void showInfoDialog();
    void restartSimulation();
    void playSimulation();
    void pauseSimulation();

    void enableControls();

protected:
    void resizeEvent(QResizeEvent* e);

private:
    void start();
    bool pause() const;
    void setPause(const bool pause);


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
