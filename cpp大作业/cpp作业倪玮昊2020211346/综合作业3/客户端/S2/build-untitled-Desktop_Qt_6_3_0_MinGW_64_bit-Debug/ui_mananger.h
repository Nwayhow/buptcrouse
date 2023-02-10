/********************************************************************************
** Form generated from reading UI file 'mananger.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANANGER_H
#define UI_MANANGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mananger
{
public:
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QWidget *mananger)
    {
        if (mananger->objectName().isEmpty())
            mananger->setObjectName(QString::fromUtf8("mananger"));
        mananger->resize(737, 288);
        comboBox = new QComboBox(mananger);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(290, 20, 62, 21));
        pushButton = new QPushButton(mananger);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 20, 91, 21));
        label = new QLabel(mananger);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 91, 16));
        lineEdit = new QLineEdit(mananger);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 20, 171, 20));
        lineEdit_2 = new QLineEdit(mananger);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 70, 151, 20));
        pushButton_2 = new QPushButton(mananger);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 70, 91, 21));
        label_2 = new QLabel(mananger);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 70, 171, 20));
        textBrowser = new QTextBrowser(mananger);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(500, 10, 221, 261));
        pushButton_4 = new QPushButton(mananger);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 240, 241, 31));
        pushButton_5 = new QPushButton(mananger);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 180, 241, 31));
        label_3 = new QLabel(mananger);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 120, 91, 16));
        lineEdit_3 = new QLineEdit(mananger);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(200, 120, 151, 20));
        lineEdit_4 = new QLineEdit(mananger);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(200, 150, 151, 20));
        label_4 = new QLabel(mananger);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 120, 101, 16));
        label_5 = new QLabel(mananger);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 150, 61, 16));
        pushButton_3 = new QPushButton(mananger);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(380, 130, 91, 21));
        pushButton_6 = new QPushButton(mananger);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(300, 240, 161, 31));
        pushButton_7 = new QPushButton(mananger);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(300, 180, 161, 31));

        retranslateUi(mananger);

        QMetaObject::connectSlotsByName(mananger);
    } // setupUi

    void retranslateUi(QWidget *mananger)
    {
        mananger->setWindowTitle(QCoreApplication::translate("mananger", "Form", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("mananger", "\346\224\266\344\273\266\344\272\272", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("mananger", "\346\227\266\351\227\264", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("mananger", "\345\257\204\344\273\266\344\272\272", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("mananger", "\345\277\253\351\200\222\345\215\225\345\217\267", nullptr));

        pushButton->setText(QCoreApplication::translate("mananger", "\346\237\245\350\257\242", nullptr));
        label->setText(QCoreApplication::translate("mananger", "\346\237\245\350\257\242\345\277\253\351\200\222", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mananger", "\346\237\245\350\257\242", nullptr));
        label_2->setText(QCoreApplication::translate("mananger", "\346\237\245\350\257\242\345\277\253\351\200\222\345\221\230\345\217\212\345\205\266\346\217\275\346\224\266\345\277\253\351\200\222", nullptr));
        pushButton_4->setText(QCoreApplication::translate("mananger", "\344\270\200\351\224\256\346\237\245\350\257\242\346\211\200\346\234\211\345\277\253\351\200\222\345\221\230\347\224\250\346\210\267\345\220\215\345\222\214\346\234\252\346\217\275\346\224\266\345\214\205\350\243\271\345\215\225\345\217\267", nullptr));
        pushButton_5->setText(QCoreApplication::translate("mananger", "\346\267\273\345\212\240\346\210\226\344\277\256\346\224\271\345\277\253\351\200\222\345\221\230", nullptr));
        label_3->setText(QCoreApplication::translate("mananger", "\345\247\224\346\264\276\345\277\253\351\200\222\345\221\230", nullptr));
        label_4->setText(QCoreApplication::translate("mananger", "\345\277\253\351\200\222\345\221\230\350\264\246\345\217\267", nullptr));
        label_5->setText(QCoreApplication::translate("mananger", "\350\256\242\345\215\225\345\217\267", nullptr));
        pushButton_3->setText(QCoreApplication::translate("mananger", "\345\210\206\351\205\215", nullptr));
        pushButton_6->setText(QCoreApplication::translate("mananger", "\351\200\200\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        pushButton_7->setText(QCoreApplication::translate("mananger", "\344\270\200\351\224\256\346\237\245\350\257\242\346\211\200\346\234\211\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mananger: public Ui_mananger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANANGER_H
