/********************************************************************************
** Form generated from reading UI file 'exitdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXITDIALOG_H
#define UI_EXITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ExitDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonSave;
    QPushButton *buttonDontSave;
    QPushButton *buttonCancel;

    void setupUi(QDialog *ExitDialog)
    {
        if (ExitDialog->objectName().isEmpty())
            ExitDialog->setObjectName(QStringLiteral("ExitDialog"));
        ExitDialog->resize(384, 138);
        gridLayout = new QGridLayout(ExitDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ExitDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        buttonSave = new QPushButton(ExitDialog);
        buttonSave->setObjectName(QStringLiteral("buttonSave"));
        buttonSave->setFocusPolicy(Qt::StrongFocus);
        buttonSave->setAutoDefault(false);

        horizontalLayout->addWidget(buttonSave);

        buttonDontSave = new QPushButton(ExitDialog);
        buttonDontSave->setObjectName(QStringLiteral("buttonDontSave"));
        buttonDontSave->setAutoDefault(false);

        horizontalLayout->addWidget(buttonDontSave);

        buttonCancel = new QPushButton(ExitDialog);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setFocusPolicy(Qt::StrongFocus);
        buttonCancel->setAutoDefault(true);

        horizontalLayout->addWidget(buttonCancel);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 2);


        retranslateUi(ExitDialog);

        QMetaObject::connectSlotsByName(ExitDialog);
    } // setupUi

    void retranslateUi(QDialog *ExitDialog)
    {
        ExitDialog->setWindowTitle(QApplication::translate("ExitDialog", "Scene(s) Have Been Modified", Q_NULLPTR));
        label->setText(QApplication::translate("ExitDialog", "	\n"
"	Do you want to save the changes you made in the scenes ? \n"
"\n"
"	Your changes wil be lost if you don't save them.", Q_NULLPTR));
        buttonSave->setText(QApplication::translate("ExitDialog", "Save", Q_NULLPTR));
        buttonDontSave->setText(QApplication::translate("ExitDialog", "Don't Save", Q_NULLPTR));
        buttonCancel->setText(QApplication::translate("ExitDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExitDialog: public Ui_ExitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXITDIALOG_H
