/********************************************************************************
** Form generated from reading UI file 'addcomponentfont.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMPONENTFONT_H
#define UI_ADDCOMPONENTFONT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddComponentFont
{
public:
    QGridLayout *gridLayout;
    QPushButton *AddComponent;

    void setupUi(QWidget *AddComponentFont)
    {
        if (AddComponentFont->objectName().isEmpty())
            AddComponentFont->setObjectName(QStringLiteral("AddComponentFont"));
        AddComponentFont->resize(320, 41);
        gridLayout = new QGridLayout(AddComponentFont);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        AddComponent = new QPushButton(AddComponentFont);
        AddComponent->setObjectName(QStringLiteral("AddComponent"));

        gridLayout->addWidget(AddComponent, 0, 0, 1, 1);


        retranslateUi(AddComponentFont);

        QMetaObject::connectSlotsByName(AddComponentFont);
    } // setupUi

    void retranslateUi(QWidget *AddComponentFont)
    {
        AddComponentFont->setWindowTitle(QApplication::translate("AddComponentFont", "Form", Q_NULLPTR));
        AddComponent->setText(QApplication::translate("AddComponentFont", "Add Component", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddComponentFont: public Ui_AddComponentFont {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMPONENTFONT_H
