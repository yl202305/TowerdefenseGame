/********************************************************************************
** Form generated from reading UI file 'StartForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTFORM_H
#define UI_STARTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartForm
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *StartForm)
    {
        if (StartForm->objectName().isEmpty())
            StartForm->setObjectName(QString::fromUtf8("StartForm"));
        StartForm->resize(986, 582);
        StartForm->setStyleSheet(QString::fromUtf8("image: url(:/image/background.png);"));
        pushButton = new QPushButton(StartForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 110, 151, 61));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 127);"));
        pushButton_2 = new QPushButton(StartForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 20, 151, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 127);"));
        pushButton_3 = new QPushButton(StartForm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(700, 60, 131, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 127);"));

        retranslateUi(StartForm);

        QMetaObject::connectSlotsByName(StartForm);
    } // setupUi

    void retranslateUi(QWidget *StartForm)
    {
        StartForm->setWindowTitle(QApplication::translate("StartForm", "Form", nullptr));
        pushButton->setText(QApplication::translate("StartForm", "\347\254\254\344\270\200\345\205\263", nullptr));
        pushButton_2->setText(QApplication::translate("StartForm", "\347\254\254\344\272\214\345\205\263", nullptr));
        pushButton_3->setText(QApplication::translate("StartForm", "\347\254\254\344\270\211\345\205\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartForm: public Ui_StartForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTFORM_H
