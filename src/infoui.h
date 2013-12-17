//
// This file is part of the LifeTime project
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE in the top directory of
// the source code.
//
// Copyright 2013      Igor Zimaev       <i.zimaev@timeacademy.ru>
// Copyright 2013      Illya Kovalevskyy <illya.kovalevskyy@gmail.com>
//

//  InfoUI - help and about window

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

private:
  Ui::InfoUI *ui;
};

#endif // INFOUI_H
