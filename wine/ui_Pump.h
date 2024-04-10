/********************************************************************************
** Form generated from reading UI file 'Pump.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUMP_H
#define UI_PUMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pump
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QToolButton *toolButton_2;

    void setupUi(QWidget *Pump)
    {
        if (Pump->objectName().isEmpty())
            Pump->setObjectName(QString::fromUtf8("Pump"));
        Pump->resize(610, 50);
        horizontalLayoutWidget = new QWidget(Pump);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 421, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(horizontalLayoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setEnabled(true);
        horizontalSlider->setMinimum(12);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBothSides);
        horizontalSlider->setTickInterval(1);

        horizontalLayout->addWidget(horizontalSlider);

        horizontalLayoutWidget_2 = new QWidget(Pump);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(440, 10, 160, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        toolButton_2 = new QToolButton(horizontalLayoutWidget_2);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

        horizontalLayout_2->addWidget(toolButton_2);


        retranslateUi(Pump);

        QMetaObject::connectSlotsByName(Pump);
    } // setupUi

    void retranslateUi(QWidget *Pump)
    {
        Pump->setWindowTitle(QCoreApplication::translate("Pump", "Pump", nullptr));
        toolButton_2->setText(QCoreApplication::translate("Pump", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pump: public Ui_Pump {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUMP_H
