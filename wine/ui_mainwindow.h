/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow_gui
{
public:
    QAction *action_connect;
    QAction *action_disconnect;
    QAction *action_exit;
    QAction *action_run;
    QAction *action_serial;
    QAction *actionBMP280;
    QAction *actionAHT20;
    QAction *actionPump;
    QAction *action_Valve;
    QAction *action_MCF;
    QAction *actionmonitor;
    QAction *action_About;
    QAction *action_About_Qt;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_5;
    QComboBox *comboBox_5;
    QSpinBox *spinBox_4;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_11;
    QLabel *label_12;
    QTextEdit *textEdit_3;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_3;
    QLabel *label_5;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit;
    QGroupBox *groupBox_6;
    QLabel *label_19;
    QComboBox *comboBox_12;
    QPushButton *pushButton_2;
    QLabel *label_20;
    QComboBox *comboBox_13;
    QLabel *label_21;
    QSpinBox *spinBox_7;
    QToolButton *toolButton_5;
    QMenuBar *menubar;
    QMenu *menu_Device;
    QMenu *menu_Mode;
    QMenu *menu_debug;
    QMenu *menu_Option;
    QMenu *menu_Help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainwindow_gui)
    {
        if (mainwindow_gui->objectName().isEmpty())
            mainwindow_gui->setObjectName(QString::fromUtf8("mainwindow_gui"));
        mainwindow_gui->resize(770, 860);
        mainwindow_gui->setDocumentMode(false);
        mainwindow_gui->setDockNestingEnabled(false);
        mainwindow_gui->setUnifiedTitleAndToolBarOnMac(false);
        action_connect = new QAction(mainwindow_gui);
        action_connect->setObjectName(QString::fromUtf8("action_connect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_connect->setIcon(icon);
        action_disconnect = new QAction(mainwindow_gui);
        action_disconnect->setObjectName(QString::fromUtf8("action_disconnect"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_disconnect->setIcon(icon1);
        action_exit = new QAction(mainwindow_gui);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/exit.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon2);
        action_run = new QAction(mainwindow_gui);
        action_run->setObjectName(QString::fromUtf8("action_run"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("images/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_run->setIcon(icon3);
        action_serial = new QAction(mainwindow_gui);
        action_serial->setObjectName(QString::fromUtf8("action_serial"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_serial->setIcon(icon4);
        actionBMP280 = new QAction(mainwindow_gui);
        actionBMP280->setObjectName(QString::fromUtf8("actionBMP280"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("images/temperature.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBMP280->setIcon(icon5);
        actionAHT20 = new QAction(mainwindow_gui);
        actionAHT20->setObjectName(QString::fromUtf8("actionAHT20"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("images/humidity.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAHT20->setIcon(icon6);
        actionPump = new QAction(mainwindow_gui);
        actionPump->setObjectName(QString::fromUtf8("actionPump"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("images/pump.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPump->setIcon(icon7);
        action_Valve = new QAction(mainwindow_gui);
        action_Valve->setObjectName(QString::fromUtf8("action_Valve"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("images/vs.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Valve->setIcon(icon8);
        action_MCF = new QAction(mainwindow_gui);
        action_MCF->setObjectName(QString::fromUtf8("action_MCF"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("images/flowmeter.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_MCF->setIcon(icon9);
        actionmonitor = new QAction(mainwindow_gui);
        actionmonitor->setObjectName(QString::fromUtf8("actionmonitor"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("images/monitor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionmonitor->setIcon(icon10);
        action_About = new QAction(mainwindow_gui);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        action_About_Qt = new QAction(mainwindow_gui);
        action_About_Qt->setObjectName(QString::fromUtf8("action_About_Qt"));
        centralwidget = new QWidget(mainwindow_gui);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 90, 751, 261));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(gridLayoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayoutWidget_3 = new QWidget(groupBox_3);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 30, 351, 91));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBox_5 = new QComboBox(gridLayoutWidget_3);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        gridLayout_5->addWidget(comboBox_5, 1, 1, 1, 1);

        spinBox_4 = new QSpinBox(gridLayoutWidget_3);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));

        gridLayout_5->addWidget(spinBox_4, 0, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_5->addWidget(label_10, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 3, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_5->addWidget(label_12, 2, 0, 1, 1);

        textEdit_3 = new QTextEdit(groupBox_3);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(10, 120, 351, 131));

        gridLayout->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(gridLayoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayoutWidget_2 = new QWidget(groupBox_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 30, 351, 91));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        comboBox_3 = new QComboBox(gridLayoutWidget_2);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        gridLayout_3->addWidget(comboBox_3, 1, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        spinBox_2 = new QSpinBox(gridLayoutWidget_2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        gridLayout_3->addWidget(spinBox_2, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 3, 0, 1, 1);

        textEdit_2 = new QTextEdit(groupBox_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 120, 351, 131));

        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 360, 751, 451));
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 10, 751, 71));
        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(160, 30, 30, 29));
        comboBox_12 = new QComboBox(groupBox_6);
        comboBox_12->setObjectName(QString::fromUtf8("comboBox_12"));
        comboBox_12->setGeometry(QRect(200, 30, 211, 29));
        pushButton_2 = new QPushButton(groupBox_6);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 30, 71, 29));
        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 30, 41, 29));
        comboBox_13 = new QComboBox(groupBox_6);
        comboBox_13->addItem(QString());
        comboBox_13->addItem(QString());
        comboBox_13->setObjectName(QString::fromUtf8("comboBox_13"));
        comboBox_13->setGeometry(QRect(60, 30, 91, 29));
        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(490, 30, 105, 29));
        spinBox_7 = new QSpinBox(groupBox_6);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setGeometry(QRect(600, 30, 111, 29));
        toolButton_5 = new QToolButton(groupBox_6);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setGeometry(QRect(720, 30, 29, 29));
        toolButton_5->setIcon(icon1);
        mainwindow_gui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainwindow_gui);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 770, 22));
        menu_Device = new QMenu(menubar);
        menu_Device->setObjectName(QString::fromUtf8("menu_Device"));
        menu_Mode = new QMenu(menubar);
        menu_Mode->setObjectName(QString::fromUtf8("menu_Mode"));
        menu_debug = new QMenu(menu_Mode);
        menu_debug->setObjectName(QString::fromUtf8("menu_debug"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("images/test.png"), QSize(), QIcon::Normal, QIcon::Off);
        menu_debug->setIcon(icon11);
        menu_Option = new QMenu(menubar);
        menu_Option->setObjectName(QString::fromUtf8("menu_Option"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        mainwindow_gui->setMenuBar(menubar);
        statusbar = new QStatusBar(mainwindow_gui);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainwindow_gui->setStatusBar(statusbar);

        menubar->addAction(menu_Device->menuAction());
        menubar->addAction(menu_Mode->menuAction());
        menubar->addAction(menu_Option->menuAction());
        menubar->addAction(menu_Help->menuAction());
        menu_Device->addAction(action_connect);
        menu_Device->addAction(action_disconnect);
        menu_Device->addSeparator();
        menu_Device->addAction(action_exit);
        menu_Mode->addAction(menu_debug->menuAction());
        menu_Mode->addAction(action_run);
        menu_Mode->addSeparator();
        menu_Mode->addAction(actionmonitor);
        menu_debug->addAction(actionBMP280);
        menu_debug->addAction(actionAHT20);
        menu_debug->addAction(actionPump);
        menu_debug->addAction(action_Valve);
        menu_debug->addAction(action_MCF);
        menu_Option->addAction(action_serial);
        menu_Help->addAction(action_About);
        menu_Help->addAction(action_About_Qt);

        retranslateUi(mainwindow_gui);

        QMetaObject::connectSlotsByName(mainwindow_gui);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindow_gui)
    {
        mainwindow_gui->setWindowTitle(QCoreApplication::translate("mainwindow_gui", "Gas", nullptr));
        action_connect->setText(QCoreApplication::translate("mainwindow_gui", "&connect", nullptr));
#if QT_CONFIG(statustip)
        action_connect->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        action_disconnect->setText(QCoreApplication::translate("mainwindow_gui", "&disconnect", nullptr));
#if QT_CONFIG(statustip)
        action_disconnect->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        action_exit->setText(QCoreApplication::translate("mainwindow_gui", "&exit", nullptr));
#if QT_CONFIG(statustip)
        action_exit->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        action_run->setText(QCoreApplication::translate("mainwindow_gui", "&run", nullptr));
#if QT_CONFIG(statustip)
        action_run->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        action_serial->setText(QCoreApplication::translate("mainwindow_gui", "&Serial", nullptr));
#if QT_CONFIG(statustip)
        action_serial->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        actionBMP280->setText(QCoreApplication::translate("mainwindow_gui", "&BMP280", nullptr));
#if QT_CONFIG(statustip)
        actionBMP280->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        actionAHT20->setText(QCoreApplication::translate("mainwindow_gui", "&AHT20", nullptr));
#if QT_CONFIG(statustip)
        actionAHT20->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        actionPump->setText(QCoreApplication::translate("mainwindow_gui", "&Pump", nullptr));
#if QT_CONFIG(statustip)
        actionPump->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        action_Valve->setText(QCoreApplication::translate("mainwindow_gui", "&Valve", nullptr));
#if QT_CONFIG(statustip)
        action_Valve->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        action_MCF->setText(QCoreApplication::translate("mainwindow_gui", "&MCF", nullptr));
        actionmonitor->setText(QCoreApplication::translate("mainwindow_gui", "monitor", nullptr));
        action_About->setText(QCoreApplication::translate("mainwindow_gui", "&About", nullptr));
        action_About_Qt->setText(QCoreApplication::translate("mainwindow_gui", "&About Qt", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("mainwindow_gui", "Write", nullptr));
        label_10->setText(QCoreApplication::translate("mainwindow_gui", "Count", nullptr));
        label_11->setText(QCoreApplication::translate("mainwindow_gui", "Start Addr", nullptr));
        label_12->setText(QCoreApplication::translate("mainwindow_gui", "Input", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("mainwindow_gui", "Read", nullptr));
        label_5->setText(QCoreApplication::translate("mainwindow_gui", "Count", nullptr));
        label_4->setText(QCoreApplication::translate("mainwindow_gui", "Start Addr", nullptr));
        label_6->setText(QCoreApplication::translate("mainwindow_gui", "Result", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("mainwindow_gui", "Connect", nullptr));
        label_19->setText(QCoreApplication::translate("mainwindow_gui", "Port", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mainwindow_gui", "&Browser...", nullptr));
        label_20->setText(QCoreApplication::translate("mainwindow_gui", "Mode", nullptr));
        comboBox_13->setItemText(0, QCoreApplication::translate("mainwindow_gui", "RTU", nullptr));
        comboBox_13->setItemText(1, QCoreApplication::translate("mainwindow_gui", "TCP", nullptr));

        label_21->setText(QCoreApplication::translate("mainwindow_gui", "Server Address", nullptr));
        toolButton_5->setText(QCoreApplication::translate("mainwindow_gui", "...", nullptr));
        menu_Device->setTitle(QCoreApplication::translate("mainwindow_gui", "&Device", nullptr));
        menu_Mode->setTitle(QCoreApplication::translate("mainwindow_gui", "&Mode", nullptr));
        menu_debug->setTitle(QCoreApplication::translate("mainwindow_gui", "&debug", nullptr));
        menu_Option->setTitle(QCoreApplication::translate("mainwindow_gui", "&Tools", nullptr));
        menu_Help->setTitle(QCoreApplication::translate("mainwindow_gui", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow_gui: public Ui_mainwindow_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
