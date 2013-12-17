#include "infoui.h"
#include "ui_infoui.h"

InfoUI::InfoUI(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::InfoUI)
{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::clicked,
            this, &InfoUI::close);
}

InfoUI::~InfoUI()
{
    delete ui;
}
