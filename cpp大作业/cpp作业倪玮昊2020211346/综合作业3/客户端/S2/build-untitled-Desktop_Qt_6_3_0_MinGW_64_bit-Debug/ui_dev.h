/********************************************************************************
** Form generated from reading UI file 'dev.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEV_H
#define UI_DEV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dev
{
public:
    QComboBox *comboBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *dev)
    {
        if (dev->objectName().isEmpty())
            dev->setObjectName(QString::fromUtf8("dev"));
        dev->resize(408, 300);
        comboBox = new QComboBox(dev);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(280, 0, 111, 22));
        label = new QLabel(dev);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 71, 16));
        lineEdit = new QLineEdit(dev);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 40, 191, 20));
        lineEdit_2 = new QLineEdit(dev);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 80, 191, 20));
        label_2 = new QLabel(dev);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 51, 16));
        pushButton = new QPushButton(dev);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 80, 91, 18));
        textBrowser = new QTextBrowser(dev);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 120, 261, 171));
        pushButton_2 = new QPushButton(dev);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 40, 91, 18));
        pushButton_3 = new QPushButton(dev);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 10, 91, 18));

        retranslateUi(dev);

        QMetaObject::connectSlotsByName(dev);
    } // setupUi

    void retranslateUi(QWidget *dev)
    {
        dev->setWindowTitle(QCoreApplication::translate("dev", "Form", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("dev", "\346\224\266\344\273\266\344\272\272", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("dev", "\346\227\266\351\227\264", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("dev", "\345\257\204\344\273\266\344\272\272", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("dev", "\345\277\253\351\200\222\345\215\225\345\217\267", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("dev", "\345\267\262\347\255\276\346\224\266", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("dev", "\346\234\252\347\241\256\350\256\244", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("dev", "\346\234\252\346\216\245\346\224\266", nullptr));

        label->setText(QCoreApplication::translate("dev", "\346\220\234\347\264\242\345\277\253\351\200\222", nullptr));
        label_2->setText(QCoreApplication::translate("dev", "\347\241\256\350\256\244\345\277\253\351\200\222", nullptr));
        pushButton->setText(QCoreApplication::translate("dev", "\347\241\256\350\256\244\346\217\275\346\224\266", nullptr));
        pushButton_2->setText(QCoreApplication::translate("dev", "\346\220\234\347\264\242", nullptr));
        pushButton_3->setText(QCoreApplication::translate("dev", "\351\200\200\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dev: public Ui_dev {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEV_H
