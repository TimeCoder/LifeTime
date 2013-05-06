///////////////////////////////////////////////////////////////////////////////
//  Settings - app global settings
//
//  Project: "LifeTime"
//  Autor: Igor Zimaev  (i.zimaev@timeacademy.ru)
///////////////////////////////////////////////////////////////////////////////
#ifndef SETTINGS_H
#define SETTINGS_H
#include <QSettings>
#include <QColor>

class Settings
{
public:
    int worldRows;
    int worldCols;
    int desiredFPS;
    int initFilling;
    QColor colorWorld;
    QColor colorGate;
    QColor colorObjectChoose;
    QColor colorObjectGhost;
    QColor colorObjectFinal;

    static Settings& instance();

private:
    Settings();
    Settings(const Settings&);
    ~Settings();
    void operator=(const Settings&);

    QSettings m_settings;
};

#endif // SETTINGS_H
