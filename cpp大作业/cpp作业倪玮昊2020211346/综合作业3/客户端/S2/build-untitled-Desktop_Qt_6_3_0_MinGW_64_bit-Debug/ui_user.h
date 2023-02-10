/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *user)
    {
        if (user->objectName().isEmpty())
            user->setObjectName(QString::fromUtf8("user"));
        user->resize(343, 171);
        pushButton = new QPushButton(user);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 40, 80, 31));
        pushButton_5 = new QPushButton(user);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(200, 40, 80, 31));
        pushButton_6 = new QPushButton(user);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(200, 110, 80, 31));
        pushButton_2 = new QPushButton(user);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 110, 80, 31));
        label = new QLabel(user);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 10, 131, 16));

        retranslateUi(user);

        QMetaObject::connectSlotsByName(user);
    } // setupUi

    void retranslateUi(QWidget *user)
    {
        user->setWindowTitle(QCoreApplication::translate("user", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("user", "\345\277\253\351\200\222", nullptr));
        pushButton_5->setText(QCoreApplication::translate("user", "\344\275\231\351\242\235", nullptr));
        pushButton_6->setText(QCoreApplication::translate("user", "\351\200\200\345\207\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("user", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("user", "\350\257\267\351\200\211\346\213\251\345\212\237\350\203\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user: public Ui_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
