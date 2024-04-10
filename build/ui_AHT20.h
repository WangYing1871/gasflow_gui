/********************************************************************************
** Form generated from reading UI file 'AHT20.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AHT20_H
#define UI_AHT20_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AHT20
{
public:
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;

    void setupUi(QWidget *AHT20)
    {
        if (AHT20->objectName().isEmpty())
            AHT20->setObjectName(QString::fromUtf8("AHT20"));
        AHT20->setEnabled(true);
        AHT20->resize(270, 50);
        horizontalLayoutWidget_2 = new QWidget(AHT20);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 251, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        retranslateUi(AHT20);

        QMetaObject::connectSlotsByName(AHT20);
    } // setupUi

    void retranslateUi(QWidget *AHT20)
    {
        AHT20->setWindowTitle(QApplication::translate("AHT20", "AHT20", nullptr));
        label_2->setText(QApplication::translate("AHT20", "Hunidity", nullptr));
        pushButton_2->setText(QApplication::translate("AHT20", "Get", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AHT20: public Ui_AHT20 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AHT20_H
