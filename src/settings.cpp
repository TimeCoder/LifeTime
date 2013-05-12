#include "settings.h"
#include <QColor>

Settings::Settings()
  : m_settings("TimeAcademy", "LifeTime")
{
    worldRows = m_settings.value("worldCols", 100).toInt();
    worldCols = m_settings.value("worldRows", 100).toInt();
    desiredFPS = m_settings.value("desiredFPS", 20).toInt();
    initFilling = m_settings.value("initFilling", 30).toInt();

    colorWorld = QColor::fromRgb(92, 208, 7);
    colorGate = QColor::fromRgb(94, 146, 251);

    colorObjectChoose = QColor::fromRgb(202, 208, 7);
    colorObjectGhost = QColor::fromRgb(92, 208, 7, 100);
    colorObjectFinal = QColor::fromRgb(32, 248, 7, 100);
}


Settings::~Settings()
{
    m_settings.setValue("worldRows", worldCols);
    m_settings.setValue("worldCols", worldRows);
    m_settings.setValue("desiredFPS", desiredFPS);
    m_settings.setValue("initFilling", initFilling);
}


Settings& Settings::instance()
{
    static Settings _instance;
    return _instance;
}


