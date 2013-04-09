/********************************************************************************
** Form generated from reading UI file 'infoui.ui'
**
** Created: Tue 9. Apr 23:57:31 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOUI_H
#define UI_INFOUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InfoUI
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *InfoUI)
    {
        if (InfoUI->objectName().isEmpty())
            InfoUI->setObjectName(QString::fromUtf8("InfoUI"));
        InfoUI->resize(468, 215);
        label = new QLabel(InfoUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 461, 161));
        label->setTextFormat(Qt::AutoText);
        label->setWordWrap(true);
        pushButton = new QPushButton(InfoUI);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 180, 75, 23));

        retranslateUi(InfoUI);

        QMetaObject::connectSlotsByName(InfoUI);
    } // setupUi

    void retranslateUi(QDialog *InfoUI)
    {
        InfoUI->setWindowTitle(QApplication::translate("InfoUI", "Help and About", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InfoUI", "LifeTime - it is a model of the time travels based on Conway's Life algorythm. Here you can see how the past responds to intervention (grandfather paradox).\n"
"\n"
"How it works?\n"
"1. Switch on virtual time machine.\n"
"2. Choose the object to move it in the timeline (mouse left click on any object of world).\n"
"3. Choose the destination point in the past (use slider).\n"
"4. Send the object into the past (push \"Leap\").\n"
"5. See the alternative reality, its deviation, and final of time loop.\n"
"\n"
"Project homepage: life.timeacademy.ru\n"
"Questions, comments and suggestions: i.zimaev@timeacademy.ru", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("InfoUI", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InfoUI: public Ui_InfoUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOUI_H
