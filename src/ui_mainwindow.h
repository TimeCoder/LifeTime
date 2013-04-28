/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 26. Apr 23:51:23 2013
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
#include <QtGui/QComboBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
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
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcd0;
    QLCDNumber *lcd1;
    QLCDNumber *lcd2;
    QSlider *sliderTime;
    QVBoxLayout *verticalLayout_1;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox;
    QCommandLinkButton *btnLeap;
    QCommandLinkButton *btnOn;
    QLabel *labelChooseObject;
    QLabel *labelChooseDate;
    QGroupBox *groupBox_2;
    QLabel *labelFlow;
    QComboBox *comboFlow;
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
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lcd0 = new QLCDNumber(centralWidget);
        lcd0->setObjectName(QString::fromUtf8("lcd0"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lcd0->sizePolicy().hasHeightForWidth());
        lcd0->setSizePolicy(sizePolicy1);
        lcd0->setMaximumSize(QSize(30, 25));
        lcd0->setFrameShape(QFrame::NoFrame);
        lcd0->setDigitCount(1);
        lcd0->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(lcd0);

        lcd1 = new QLCDNumber(centralWidget);
        lcd1->setObjectName(QString::fromUtf8("lcd1"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lcd1->sizePolicy().hasHeightForWidth());
        lcd1->setSizePolicy(sizePolicy2);
        lcd1->setMaximumSize(QSize(16777215, 30));
        QPalette palette;
        QBrush brush(QColor(0, 0, 106, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lcd1->setPalette(palette);
        lcd1->setFrameShape(QFrame::NoFrame);
        lcd1->setDigitCount(5);
        lcd1->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(lcd1);

        lcd2 = new QLCDNumber(centralWidget);
        lcd2->setObjectName(QString::fromUtf8("lcd2"));
        sizePolicy1.setHeightForWidth(lcd2->sizePolicy().hasHeightForWidth());
        lcd2->setSizePolicy(sizePolicy1);
        lcd2->setMaximumSize(QSize(16777215, 30));
        lcd2->setFrameShape(QFrame::NoFrame);
        lcd2->setDigitCount(5);
        lcd2->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(lcd2);


        verticalLayout->addLayout(horizontalLayout);

        sliderTime = new QSlider(centralWidget);
        sliderTime->setObjectName(QString::fromUtf8("sliderTime"));
        sliderTime->setEnabled(false);
        sizePolicy2.setHeightForWidth(sliderTime->sizePolicy().hasHeightForWidth());
        sliderTime->setSizePolicy(sizePolicy2);
        sliderTime->setMinimum(1);
        sliderTime->setValue(99);
        sliderTime->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(sliderTime);

        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setSpacing(6);
        verticalLayout_1->setObjectName(QString::fromUtf8("verticalLayout_1"));

        verticalLayout->addLayout(verticalLayout_1);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMinimumSize(QSize(180, 0));
        treeWidget->setMaximumSize(QSize(180, 16777215));
        treeWidget->header()->setVisible(false);

        gridLayout->addWidget(treeWidget, 2, 1, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(180, 150));
        groupBox->setMaximumSize(QSize(16777215, 150));
        btnLeap = new QCommandLinkButton(groupBox);
        btnLeap->setObjectName(QString::fromUtf8("btnLeap"));
        btnLeap->setEnabled(false);
        btnLeap->setGeometry(QRect(10, 98, 161, 40));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/res/jump.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnLeap->setIcon(icon5);
        btnOn = new QCommandLinkButton(groupBox);
        btnOn->setObjectName(QString::fromUtf8("btnOn"));
        btnOn->setEnabled(true);
        btnOn->setGeometry(QRect(10, 10, 161, 40));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/res/on.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnOn->setIcon(icon6);
        btnOn->setIconSize(QSize(20, 20));
        btnOn->setCheckable(false);
        btnOn->setDefault(false);
        labelChooseObject = new QLabel(groupBox);
        labelChooseObject->setObjectName(QString::fromUtf8("labelChooseObject"));
        labelChooseObject->setEnabled(false);
        labelChooseObject->setGeometry(QRect(44, 47, 91, 16));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        labelChooseObject->setFont(font);
        labelChooseDate = new QLabel(groupBox);
        labelChooseDate->setObjectName(QString::fromUtf8("labelChooseDate"));
        labelChooseDate->setEnabled(false);
        labelChooseDate->setGeometry(QRect(44, 63, 91, 16));

        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 40));
        labelFlow = new QLabel(groupBox_2);
        labelFlow->setObjectName(QString::fromUtf8("labelFlow"));
        labelFlow->setEnabled(false);
        labelFlow->setGeometry(QRect(16, 4, 31, 31));
        sizePolicy.setHeightForWidth(labelFlow->sizePolicy().hasHeightForWidth());
        labelFlow->setSizePolicy(sizePolicy);
        labelFlow->setMaximumSize(QSize(40, 16777215));
        comboFlow = new QComboBox(groupBox_2);
        comboFlow->setObjectName(QString::fromUtf8("comboFlow"));
        comboFlow->setEnabled(true);
        comboFlow->setGeometry(QRect(50, 10, 150, 20));
        comboFlow->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(groupBox_2, 3, 0, 1, 2);

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
        groupBox->setTitle(QString());
        btnLeap->setText(QApplication::translate("MainWindow", "Leap", 0, QApplication::UnicodeUTF8));
        btnOn->setText(QApplication::translate("MainWindow", "Begin", 0, QApplication::UnicodeUTF8));
        labelChooseObject->setText(QApplication::translate("MainWindow", "- choose object", 0, QApplication::UnicodeUTF8));
        labelChooseDate->setText(QApplication::translate("MainWindow", "- choose time", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        labelFlow->setText(QApplication::translate("MainWindow", "Flow:", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
