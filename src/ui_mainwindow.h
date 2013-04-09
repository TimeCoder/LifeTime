/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 10. Apr 02:35:19 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QSlider>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSettings;
    QAction *actionRestart;
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionInfo;
    QWidget *centralWidget;
    QGroupBox *groupBox_2;
    QSlider *sliderTime;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_1;
    QCommandLinkButton *btnLeap;
    QCommandLinkButton *btnOn;
    QLCDNumber *lcd2;
    QLCDNumber *lcd0;
    QLCDNumber *lcd1;
    QLabel *labelChooseObject;
    QLabel *labelChooseDate;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/res/settings.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon);
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QString::fromUtf8("actionRestart"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/res/restart.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestart->setIcon(icon1);
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        actionPlay->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/res/play.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon2);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/res/pause.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon3);
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/res/help.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(9, 3, 781, 181));
        groupBox_2->setMinimumSize(QSize(200, 50));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        sliderTime = new QSlider(groupBox_2);
        sliderTime->setObjectName(QString::fromUtf8("sliderTime"));
        sliderTime->setEnabled(false);
        sliderTime->setGeometry(QRect(10, 51, 581, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sliderTime->sizePolicy().hasHeightForWidth());
        sliderTime->setSizePolicy(sizePolicy1);
        sliderTime->setMinimum(1);
        sliderTime->setValue(99);
        sliderTime->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 80, 581, 91));
        verticalLayout_1 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_1->setSpacing(6);
        verticalLayout_1->setContentsMargins(11, 11, 11, 11);
        verticalLayout_1->setObjectName(QString::fromUtf8("verticalLayout_1"));
        verticalLayout_1->setContentsMargins(0, 0, 0, 0);
        btnLeap = new QCommandLinkButton(groupBox_2);
        btnLeap->setObjectName(QString::fromUtf8("btnLeap"));
        btnLeap->setEnabled(false);
        btnLeap->setGeometry(QRect(616, 100, 161, 40));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("res/jump.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnLeap->setIcon(icon5);
        btnOn = new QCommandLinkButton(groupBox_2);
        btnOn->setObjectName(QString::fromUtf8("btnOn"));
        btnOn->setEnabled(true);
        btnOn->setGeometry(QRect(616, 10, 161, 40));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("res/on.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnOn->setIcon(icon6);
        btnOn->setIconSize(QSize(20, 20));
        lcd2 = new QLCDNumber(groupBox_2);
        lcd2->setObjectName(QString::fromUtf8("lcd2"));
        lcd2->setGeometry(QRect(530, 16, 64, 31));
        lcd2->setFrameShape(QFrame::NoFrame);
        lcd2->setSegmentStyle(QLCDNumber::Flat);
        lcd0 = new QLCDNumber(groupBox_2);
        lcd0->setObjectName(QString::fromUtf8("lcd0"));
        lcd0->setGeometry(QRect(-40, 16, 64, 31));
        lcd0->setLayoutDirection(Qt::RightToLeft);
        lcd0->setFrameShape(QFrame::NoFrame);
        lcd0->setSegmentStyle(QLCDNumber::Flat);
        lcd1 = new QLCDNumber(groupBox_2);
        lcd1->setObjectName(QString::fromUtf8("lcd1"));
        lcd1->setGeometry(QRect(250, 16, 64, 31));
        QPalette palette;
        QBrush brush(QColor(0, 0, 106, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lcd1->setPalette(palette);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        lcd1->setFont(font);
        lcd1->setFrameShape(QFrame::NoFrame);
        lcd1->setSegmentStyle(QLCDNumber::Flat);
        labelChooseObject = new QLabel(groupBox_2);
        labelChooseObject->setObjectName(QString::fromUtf8("labelChooseObject"));
        labelChooseObject->setEnabled(false);
        labelChooseObject->setGeometry(QRect(650, 47, 91, 16));
        labelChooseObject->setFont(font);
        labelChooseDate = new QLabel(groupBox_2);
        labelChooseDate->setObjectName(QString::fromUtf8("labelChooseDate"));
        labelChooseDate->setEnabled(false);
        labelChooseDate->setGeometry(QRect(650, 63, 91, 16));
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 200, 581, 351));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(610, 200, 181, 351));
        treeWidget->header()->setVisible(false);
        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionPlay);
        toolBar->addAction(actionPause);
        toolBar->addSeparator();
        toolBar->addAction(actionSettings);
        toolBar->addAction(actionRestart);
        toolBar->addSeparator();
        toolBar->addAction(actionInfo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LifeTime 1.0", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSettings->setToolTip(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRestart->setText(QApplication::translate("MainWindow", "Restart", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRestart->setToolTip(QApplication::translate("MainWindow", "Restart", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPlay->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPlay->setToolTip(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPause->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPause->setToolTip(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionInfo->setText(QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Time Machine", 0, QApplication::UnicodeUTF8));
        btnLeap->setText(QApplication::translate("MainWindow", "Leap", 0, QApplication::UnicodeUTF8));
        btnOn->setText(QApplication::translate("MainWindow", "Power", 0, QApplication::UnicodeUTF8));
        labelChooseObject->setText(QApplication::translate("MainWindow", "- choose object", 0, QApplication::UnicodeUTF8));
        labelChooseDate->setText(QApplication::translate("MainWindow", "- choose time", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
