/********************************************************************************
** Form generated from reading UI file 'setting_modbus.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_MODBUS_H
#define UI_SETTING_MODBUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_modbus_setting
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpinBox *timeoutSpinner;
    QLabel *label;
    QPushButton *applyButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QComboBox *parityCombo;
    QLabel *label_3;
    QComboBox *baudCombo;
    QLabel *label_4;
    QComboBox *dataBitsCombo;
    QLabel *label_5;
    QComboBox *stopBitsCombo;
    QLabel *label_6;
    QSpinBox *retriesSpinner;

    void setupUi(QDialog *modbus_setting)
    {
        if (modbus_setting->objectName().isEmpty())
            modbus_setting->setObjectName(QString::fromUtf8("modbus_setting"));
        modbus_setting->resize(242, 281);
        gridLayout = new QGridLayout(modbus_setting);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 43, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        timeoutSpinner = new QSpinBox(modbus_setting);
        timeoutSpinner->setObjectName(QString::fromUtf8("timeoutSpinner"));
        timeoutSpinner->setAccelerated(true);
        timeoutSpinner->setMinimum(-1);
        timeoutSpinner->setMaximum(5000);
        timeoutSpinner->setSingleStep(20);
        timeoutSpinner->setValue(200);

        gridLayout->addWidget(timeoutSpinner, 1, 1, 1, 1);

        label = new QLabel(modbus_setting);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        applyButton = new QPushButton(modbus_setting);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        gridLayout->addWidget(applyButton, 4, 1, 1, 1);

        groupBox = new QGroupBox(modbus_setting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        parityCombo = new QComboBox(groupBox);
        parityCombo->addItem(QString());
        parityCombo->addItem(QString());
        parityCombo->addItem(QString());
        parityCombo->addItem(QString());
        parityCombo->addItem(QString());
        parityCombo->setObjectName(QString::fromUtf8("parityCombo"));

        gridLayout_2->addWidget(parityCombo, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        baudCombo = new QComboBox(groupBox);
        baudCombo->addItem(QString());
        baudCombo->addItem(QString());
        baudCombo->addItem(QString());
        baudCombo->addItem(QString());
        baudCombo->addItem(QString());
        baudCombo->addItem(QString());
        baudCombo->addItem(QString());
        baudCombo->addItem(QString());
        baudCombo->setObjectName(QString::fromUtf8("baudCombo"));
        baudCombo->setMaxVisibleItems(10);

        gridLayout_2->addWidget(baudCombo, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        dataBitsCombo = new QComboBox(groupBox);
        dataBitsCombo->addItem(QString());
        dataBitsCombo->addItem(QString());
        dataBitsCombo->addItem(QString());
        dataBitsCombo->addItem(QString());
        dataBitsCombo->setObjectName(QString::fromUtf8("dataBitsCombo"));

        gridLayout_2->addWidget(dataBitsCombo, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 3, 0, 1, 1);

        stopBitsCombo = new QComboBox(groupBox);
        stopBitsCombo->addItem(QString());
        stopBitsCombo->addItem(QString());
        stopBitsCombo->addItem(QString());
        stopBitsCombo->setObjectName(QString::fromUtf8("stopBitsCombo"));

        gridLayout_2->addWidget(stopBitsCombo, 3, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        label_6 = new QLabel(modbus_setting);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        retriesSpinner = new QSpinBox(modbus_setting);
        retriesSpinner->setObjectName(QString::fromUtf8("retriesSpinner"));
        retriesSpinner->setValue(1);

        gridLayout->addWidget(retriesSpinner, 2, 1, 1, 1);


        retranslateUi(modbus_setting);

        dataBitsCombo->setCurrentIndex(3);
        stopBitsCombo->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(modbus_setting);
    } // setupUi

    void retranslateUi(QDialog *modbus_setting)
    {
        modbus_setting->setWindowTitle(QApplication::translate("modbus_setting", "Modbus Settings", nullptr));
        timeoutSpinner->setSuffix(QApplication::translate("modbus_setting", " ms", nullptr));
        label->setText(QApplication::translate("modbus_setting", "Response Timeout:", nullptr));
        applyButton->setText(QApplication::translate("modbus_setting", "Apply", nullptr));
        groupBox->setTitle(QApplication::translate("modbus_setting", "Serial Parameters", nullptr));
        label_2->setText(QApplication::translate("modbus_setting", "Parity:", nullptr));
        parityCombo->setItemText(0, QApplication::translate("modbus_setting", "No", nullptr));
        parityCombo->setItemText(1, QApplication::translate("modbus_setting", "Even", nullptr));
        parityCombo->setItemText(2, QApplication::translate("modbus_setting", "Odd", nullptr));
        parityCombo->setItemText(3, QApplication::translate("modbus_setting", "Space", nullptr));
        parityCombo->setItemText(4, QApplication::translate("modbus_setting", "Mark", nullptr));

        label_3->setText(QApplication::translate("modbus_setting", "Baud Rate:", nullptr));
        baudCombo->setItemText(0, QApplication::translate("modbus_setting", "1200", nullptr));
        baudCombo->setItemText(1, QApplication::translate("modbus_setting", "2400", nullptr));
        baudCombo->setItemText(2, QApplication::translate("modbus_setting", "4800", nullptr));
        baudCombo->setItemText(3, QApplication::translate("modbus_setting", "9600", nullptr));
        baudCombo->setItemText(4, QApplication::translate("modbus_setting", "19200", nullptr));
        baudCombo->setItemText(5, QApplication::translate("modbus_setting", "38400", nullptr));
        baudCombo->setItemText(6, QApplication::translate("modbus_setting", "57600", nullptr));
        baudCombo->setItemText(7, QApplication::translate("modbus_setting", "115200", nullptr));

        baudCombo->setCurrentText(QApplication::translate("modbus_setting", "19200", nullptr));
        label_4->setText(QApplication::translate("modbus_setting", "Data Bits:", nullptr));
        dataBitsCombo->setItemText(0, QApplication::translate("modbus_setting", "5", nullptr));
        dataBitsCombo->setItemText(1, QApplication::translate("modbus_setting", "6", nullptr));
        dataBitsCombo->setItemText(2, QApplication::translate("modbus_setting", "7", nullptr));
        dataBitsCombo->setItemText(3, QApplication::translate("modbus_setting", "8", nullptr));

        dataBitsCombo->setCurrentText(QApplication::translate("modbus_setting", "8", nullptr));
        label_5->setText(QApplication::translate("modbus_setting", "Stop Bits:", nullptr));
        stopBitsCombo->setItemText(0, QApplication::translate("modbus_setting", "1", nullptr));
        stopBitsCombo->setItemText(1, QApplication::translate("modbus_setting", "3", nullptr));
        stopBitsCombo->setItemText(2, QApplication::translate("modbus_setting", "2", nullptr));

        stopBitsCombo->setCurrentText(QApplication::translate("modbus_setting", "2", nullptr));
        label_6->setText(QApplication::translate("modbus_setting", "Number of retries:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modbus_setting: public Ui_modbus_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_MODBUS_H
