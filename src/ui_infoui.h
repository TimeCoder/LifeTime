/********************************************************************************
** Form generated from reading UI file 'infoui.ui'
**
** Created: Fri 26. Apr 23:51:23 2013
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
        label->setText(QApplication::translate("InfoUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">LifeTime - it is a model of the time travels based on Conway's Life algorythm. Here you can see how the past responds to intervention (grandfather paradox).</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">How it works?</span></p>\n"
"<p s"
                        "tyle=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">1. Push &quot;Begin&quot; (switch on virtual time machine).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">2. Choose the object to move it in the timeline (mouse left click on any object of world).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">3. Choose the destination point in the past (use slider).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">4. Send the object into the past (push &quot;Leap&quot;).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bloc"
                        "k-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">5. See the alternative reality, its deviation, and final of time loop.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Questions, comments and suggestions: i.zimaev@timeacademy.ru</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("InfoUI", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InfoUI: public Ui_InfoUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOUI_H
