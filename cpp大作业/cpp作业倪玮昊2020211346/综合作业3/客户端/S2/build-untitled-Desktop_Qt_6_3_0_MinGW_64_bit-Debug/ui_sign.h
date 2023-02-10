/********************************************************************************
** Form generated from reading UI file 'sign.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_H
#define UI_SIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sign
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit_6;

    void setupUi(QWidget *sign)
    {
        if (sign->objectName().isEmpty())
            sign->setObjectName(QString::fromUtf8("sign"));
        sign->resize(400, 288);
        label_2 = new QLabel(sign);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 81, 16));
        label_3 = new QLabel(sign);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 80, 81, 16));
        label_4 = new QLabel(sign);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 130, 71, 16));
        label_5 = new QLabel(sign);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 180, 91, 16));
        label_6 = new QLabel(sign);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 220, 91, 16));
        label_7 = new QLabel(sign);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(290, 10, 111, 41));
        lineEdit = new QLineEdit(sign);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 20, 161, 20));
        lineEdit_2 = new QLineEdit(sign);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 80, 161, 20));
        lineEdit_3 = new QLineEdit(sign);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 130, 161, 20));
        lineEdit_4 = new QLineEdit(sign);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(110, 180, 161, 20));
        lineEdit_5 = new QLineEdit(sign);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(110, 220, 161, 20));
        pushButton = new QPushButton(sign);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 90, 80, 18));
        label = new QLabel(sign);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 260, 131, 16));
        lineEdit_6 = new QLineEdit(sign);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(110, 260, 161, 20));

        retranslateUi(sign);

        QMetaObject::connectSlotsByName(sign);
    } // setupUi

    void retranslateUi(QWidget *sign)
    {
        sign->setWindowTitle(QCoreApplication::translate("sign", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("sign", "\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("sign", "\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("sign", "\347\224\265\350\257\235\345\217\267", nullptr));
        label_5->setText(QCoreApplication::translate("sign", "\344\275\231\351\242\235", nullptr));
        label_6->setText(QCoreApplication::translate("sign", "\345\234\260\345\235\200", nullptr));
        label_7->setText(QCoreApplication::translate("sign", "\346\234\252\346\223\215\344\275\234", nullptr));
        pushButton->setText(QCoreApplication::translate("sign", "\346\263\250\345\206\214", nullptr));
        label->setText(QCoreApplication::translate("sign", "\345\247\223\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sign: public Ui_sign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_H
