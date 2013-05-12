///////////////////////////////////////////////////////////////////////////////
//  SettingsUI - view of global app settings
//
//  Project: "LifeTime"
//  Autor: Igor Zimaev  (i.zimaev@timeacademy.ru)
///////////////////////////////////////////////////////////////////////////////
#ifndef SETTINGSUI_H
#define SETTINGSUI_H
#include <QDialog>

namespace Ui {
  class SettingsUI;
}


class SettingsUI : public QDialog
{
  Q_OBJECT
  
public:
  explicit SettingsUI(QWidget *parent = 0);
  ~SettingsUI();
  
private slots:
  void on_pushOK_clicked();

private:
  Ui::SettingsUI *ui;

};

#endif // SETTINGSUI_H
