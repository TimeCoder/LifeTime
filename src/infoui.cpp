#include "infoui.h"
#include "ui_infoui.h"

InfoUI::InfoUI(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::InfoUI)
{
  ui->setupUi(this);
}

InfoUI::~InfoUI()
{
  delete ui;
}

void InfoUI::on_pushButton_clicked()
{
    close();
}
