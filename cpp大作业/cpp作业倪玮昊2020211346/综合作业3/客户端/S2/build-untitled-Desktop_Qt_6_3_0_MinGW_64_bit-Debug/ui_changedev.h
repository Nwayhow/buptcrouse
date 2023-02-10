/********************************************************************************
** Form generated from reading UI file 'changedev.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEDEV_H
#define UI_CHANGEDEV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changedev
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *changedev)
    {
        if (changedev->objectName().isEmpty())
            changedev->setObjectName(QString::fromUtf8("changedev"));
        changedev->resize(428, 300);
        label_2 = new QLabel(changedev);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 51, 16));
        label_3 = new QLabel(changedev);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 80, 40, 12));
        label_4 = new QLabel(changedev);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 120, 40, 12));
        label_5 = new QLabel(changedev);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 160, 51, 16));
        label_6 = new QLabel(changedev);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 200, 40, 12));
        lineEdit_2 = new QLineEdit(changedev);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 40, 171, 20));
        lineEdit_3 = new QLineEdit(changedev);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 80, 171, 20));
        lineEdit_4 = new QLineEdit(changedev);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(110, 120, 171, 20));
        lineEdit_5 = new QLineEdit(changedev);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(110, 160, 171, 20));
        lineEdit_6 = new QLineEdit(changedev);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(110, 200, 171, 20));
        label_7 = new QLabel(changedev);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(330, 10, 61, 31));
        pushButton = new QPushButton(changedev);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 50, 80, 31));
        pushButton_2 = new QPushButton(changedev);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 100, 80, 31));

        retranslateUi(changedev);

        QMetaObject::connectSlotsByName(changedev);
    } // setupUi

    void retranslateUi(QWidget *changedev)
    {
        changedev->setWindowTitle(QCoreApplication::translate("changedev", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("changedev", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("changedev", "\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("changedev", "\345\247\223\345\220\215", nullptr));
        label_5->setText(QCoreApplication::translate("changedev", "\347\224\265\350\257\235", nullptr));
        label_6->setText(QCoreApplication::translate("changedev", "\344\275\231\351\242\235", nullptr));
        label_7->setText(QCoreApplication::translate("changedev", "\346\234\252\346\223\215\344\275\234", nullptr));
        pushButton->setText(QCoreApplication::translate("changedev", "\345\210\240\351\231\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("changedev", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changedev: public Ui_changedev {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEDEV_H
