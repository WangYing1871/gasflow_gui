/********************************************************************************
** Form generated from reading UI file 'Valve.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALVE_H
#define UI_VALVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Valve
{
public:
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;

    void setupUi(QWidget *Valve)
    {
        if (Valve->objectName().isEmpty())
            Valve->setObjectName(QString::fromUtf8("Valve"));
        Valve->resize(270, 50);
        horizontalLayoutWidget_3 = new QWidget(Valve);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 10, 251, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton_4 = new QRadioButton(horizontalLayoutWidget_3);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        horizontalLayout_3->addWidget(radioButton_4);

        radioButton_3 = new QRadioButton(horizontalLayoutWidget_3);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        horizontalLayout_3->addWidget(radioButton_3);


        retranslateUi(Valve);

        QMetaObject::connectSlotsByName(Valve);
    } // setupUi

    void retranslateUi(QWidget *Valve)
    {
        Valve->setWindowTitle(QApplication::translate("Valve", "Valve", nullptr));
        radioButton_4->setText(QApplication::translate("Valve", "ON", nullptr));
        radioButton_3->setText(QApplication::translate("Valve", "OFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Valve: public Ui_Valve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALVE_H
