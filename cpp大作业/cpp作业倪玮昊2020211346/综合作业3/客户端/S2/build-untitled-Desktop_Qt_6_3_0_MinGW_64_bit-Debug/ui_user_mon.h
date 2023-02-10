/********************************************************************************
** Form generated from reading UI file 'user_mon.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_MON_H
#define UI_USER_MON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user_rec
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *user_rec)
    {
        if (user_rec->objectName().isEmpty())
            user_rec->setObjectName(QString::fromUtf8("user_rec"));
        user_rec->resize(349, 300);
        pushButton = new QPushButton(user_rec);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 40, 80, 18));
        pushButton_2 = new QPushButton(user_rec);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 80, 80, 18));
        lineEdit = new QLineEdit(user_rec);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 80, 113, 20));
        label = new QLabel(user_rec);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 80, 61, 16));
        textBrowser = new QTextBrowser(user_rec);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 130, 256, 151));

        retranslateUi(user_rec);

        QMetaObject::connectSlotsByName(user_rec);
    } // setupUi

    void retranslateUi(QWidget *user_rec)
    {
        user_rec->setWindowTitle(QCoreApplication::translate("user_rec", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("user_rec", "\346\237\245\350\257\242\344\275\231\351\242\235", nullptr));
        pushButton_2->setText(QCoreApplication::translate("user_rec", "\345\205\205\345\200\274", nullptr));
        label->setText(QCoreApplication::translate("user_rec", "\345\205\205\345\200\274\351\207\221\351\242\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user_rec: public Ui_user_rec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_MON_H
