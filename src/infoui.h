///////////////////////////////////////////////////////////////////////////////
//  InfoUI - help and about window
//
//  Project: "LifeTime"
//  Autor: Zimaev Igor (i.zimaev@timeacademy.ru)
///////////////////////////////////////////////////////////////////////////////
#ifndef INFOUI_H
#define INFOUI_H

#include <QDialog>

namespace Ui {
  class InfoUI;
}

class InfoUI : public QDialog
{
  Q_OBJECT
  
public:
  explicit InfoUI(QWidget *parent = 0);
  ~InfoUI();
  
private slots:
    void on_pushButton_clicked();

private:
  Ui::InfoUI *ui;
};

#endif // INFOUI_H
