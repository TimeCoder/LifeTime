/********************************************************************************
** Form generated from reading UI file 'settingsui.ui'
**
** Created: Fri 26. Apr 23:51:23 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSUI_H
#define UI_SETTINGSUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SettingsUI
{
public:
    QSpinBox *spinWorldCols;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinWorldRows;
    QLabel *label_3;
    QSpinBox *spinDesiredFPS;
    QSpinBox *spinInitFilling;
    QLabel *label_4;
    QPushButton *pushOK;

    void setupUi(QDialog *SettingsUI)
    {
        if (SettingsUI->objectName().isEmpty())
            SettingsUI->setObjectName(QString::fromUtf8("SettingsUI"));
        SettingsUI->resize(273, 166);
        spinWorldCols = new QSpinBox(SettingsUI);
        spinWorldCols->setObjectName(QString::fromUtf8("spinWorldCols"));
        spinWorldCols->setGeometry(QRect(90, 10, 71, 22));
        spinWorldCols->setMinimum(50);
        spinWorldCols->setMaximum(1000);
        spinWorldCols->setSingleStep(50);
        label = new QLabel(SettingsUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 14, 61, 16));
        label_2 = new QLabel(SettingsUI);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(167, 16, 16, 16));
        spinWorldRows = new QSpinBox(SettingsUI);
        spinWorldRows->setObjectName(QString::fromUtf8("spinWorldRows"));
        spinWorldRows->setGeometry(QRect(180, 10, 71, 22));
        spinWorldRows->setMinimum(50);
        spinWorldRows->setMaximum(1000);
        spinWorldRows->setSingleStep(50);
        label_3 = new QLabel(SettingsUI);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(22, 53, 61, 16));
        spinDesiredFPS = new QSpinBox(SettingsUI);
        spinDesiredFPS->setObjectName(QString::fromUtf8("spinDesiredFPS"));
        spinDesiredFPS->setGeometry(QRect(90, 50, 71, 22));
        spinDesiredFPS->setMinimum(10);
        spinDesiredFPS->setMaximum(100);
        spinDesiredFPS->setSingleStep(10);
        spinInitFilling = new QSpinBox(SettingsUI);
        spinInitFilling->setObjectName(QString::fromUtf8("spinInitFilling"));
        spinInitFilling->setGeometry(QRect(90, 90, 71, 22));
        spinInitFilling->setMinimum(10);
        spinInitFilling->setMaximum(100);
        spinInitFilling->setSingleStep(10);
        spinInitFilling->setValue(30);
        label_4 = new QLabel(SettingsUI);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(14, 93, 71, 16));
        pushOK = new QPushButton(SettingsUI);
        pushOK->setObjectName(QString::fromUtf8("pushOK"));
        pushOK->setGeometry(QRect(187, 131, 75, 23));

        retranslateUi(SettingsUI);

        QMetaObject::connectSlotsByName(SettingsUI);
    } // setupUi

    void retranslateUi(QDialog *SettingsUI)
    {
        SettingsUI->setWindowTitle(QApplication::translate("SettingsUI", "Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SettingsUI", "World size:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SettingsUI", "x", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SettingsUI", "Desired FPS:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SettingsUI", "Init filling (%):", 0, QApplication::UnicodeUTF8));
        pushOK->setText(QApplication::translate("SettingsUI", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsUI: public Ui_SettingsUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSUI_H
