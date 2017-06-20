/********************************************************************************
** Form generated from reading UI file 'collider.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLIDER_H
#define UI_COLLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Collider
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QFrame *line;

    void setupUi(QWidget *Collider)
    {
        if (Collider->objectName().isEmpty())
            Collider->setObjectName(QStringLiteral("Collider"));
        Collider->resize(360, 85);
        gridLayout = new QGridLayout(Collider);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Collider);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(30, 0, 108, -1);
        label_2 = new QLabel(Collider);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(Collider);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(Collider);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Collider);

        QMetaObject::connectSlotsByName(Collider);
    } // setupUi

    void retranslateUi(QWidget *Collider)
    {
        Collider->setWindowTitle(QApplication::translate("Collider", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Collider", "    Collider", Q_NULLPTR));
        label_2->setText(QApplication::translate("Collider", "Select collider", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Collider: public Ui_Collider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLIDER_H
