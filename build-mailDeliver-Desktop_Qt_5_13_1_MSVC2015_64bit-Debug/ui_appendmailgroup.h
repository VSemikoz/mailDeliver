/********************************************************************************
** Form generated from reading UI file 'appendmailgroup.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPENDMAILGROUP_H
#define UI_APPENDMAILGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AppendMailGroup
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *cancelButton;
    QPushButton *appendMailButton;
    QLineEdit *groupNameLineEdit;
    QPlainTextEdit *mailListPlainTextEdit;
    QLabel *invalidInputLabel;

    void setupUi(QDialog *AppendMailGroup)
    {
        if (AppendMailGroup->objectName().isEmpty())
            AppendMailGroup->setObjectName(QString::fromUtf8("AppendMailGroup"));
        AppendMailGroup->resize(587, 266);
        AppendMailGroup->setMinimumSize(QSize(587, 266));
        AppendMailGroup->setMaximumSize(QSize(587, 266));
        label = new QLabel(AppendMailGroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 151, 16));
        label_2 = new QLabel(AppendMailGroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 331, 16));
        cancelButton = new QPushButton(AppendMailGroup);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(500, 220, 75, 23));
        appendMailButton = new QPushButton(AppendMailGroup);
        appendMailButton->setObjectName(QString::fromUtf8("appendMailButton"));
        appendMailButton->setGeometry(QRect(410, 220, 75, 23));
        groupNameLineEdit = new QLineEdit(AppendMailGroup);
        groupNameLineEdit->setObjectName(QString::fromUtf8("groupNameLineEdit"));
        groupNameLineEdit->setGeometry(QRect(10, 30, 251, 20));
        mailListPlainTextEdit = new QPlainTextEdit(AppendMailGroup);
        mailListPlainTextEdit->setObjectName(QString::fromUtf8("mailListPlainTextEdit"));
        mailListPlainTextEdit->setGeometry(QRect(10, 90, 371, 151));
        invalidInputLabel = new QLabel(AppendMailGroup);
        invalidInputLabel->setObjectName(QString::fromUtf8("invalidInputLabel"));
        invalidInputLabel->setGeometry(QRect(110, 10, 451, 16));

        retranslateUi(AppendMailGroup);

        QMetaObject::connectSlotsByName(AppendMailGroup);
    } // setupUi

    void retranslateUi(QDialog *AppendMailGroup)
    {
        AppendMailGroup->setWindowTitle(QCoreApplication::translate("AppendMailGroup", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AppendMailGroup", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("AppendMailGroup", "Email \320\260\320\264\321\200\320\265\321\201\320\260 \320\263\321\200\321\203\320\277\320\277\321\213, \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\214 \320\267\320\260\320\277\321\217\321\202\320\260\321\217 \320\270\320\273\320\270 \320\267\320\275\320\260\320\272 \320\277\321\200\320\276\320\261\320\265\320\273\320\260", nullptr));
        cancelButton->setText(QCoreApplication::translate("AppendMailGroup", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        appendMailButton->setText(QCoreApplication::translate("AppendMailGroup", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        invalidInputLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AppendMailGroup: public Ui_AppendMailGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPENDMAILGROUP_H
