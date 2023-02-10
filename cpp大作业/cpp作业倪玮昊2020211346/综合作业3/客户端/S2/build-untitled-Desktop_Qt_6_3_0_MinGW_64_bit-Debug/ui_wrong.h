/********************************************************************************
** Form generated from reading UI file 'wrong.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRONG_H
#define UI_WRONG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wrong
{
public:
    QLabel *label;

    void setupUi(QWidget *wrong)
    {
        if (wrong->objectName().isEmpty())
            wrong->setObjectName(QString::fromUtf8("wrong"));
        wrong->resize(215, 118);
        label = new QLabel(wrong);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 201, 41));

        retranslateUi(wrong);

        QMetaObject::connectSlotsByName(wrong);
    } // setupUi

    void retranslateUi(QWidget *wrong)
    {
        wrong->setWindowTitle(QCoreApplication::translate("wrong", "Form", nullptr));
        label->setText(QCoreApplication::translate("wrong", "\350\277\236\346\216\245\346\226\255\345\274\200,\350\257\267\351\207\215\346\226\260\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wrong: public Ui_wrong {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRONG_H
