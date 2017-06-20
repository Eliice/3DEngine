/********************************************************************************
** Form generated from reading UI file 'capsulecollider.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPSULECOLLIDER_H
#define UI_CAPSULECOLLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CapsuleCollider
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_5;
    QFrame *line;

    void setupUi(QWidget *CapsuleCollider)
    {
        if (CapsuleCollider->objectName().isEmpty())
            CapsuleCollider->setObjectName(QStringLiteral("CapsuleCollider"));
        CapsuleCollider->resize(320, 170);
        verticalLayout_2 = new QVBoxLayout(CapsuleCollider);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        checkBox = new QCheckBox(CapsuleCollider);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        checkBox->setFont(font);

        horizontalLayout_5->addWidget(checkBox);


        verticalLayout->addLayout(horizontalLayout_5);

        checkBox_2 = new QCheckBox(CapsuleCollider);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        label = new QLabel(CapsuleCollider);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_2 = new QLabel(CapsuleCollider);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(CapsuleCollider);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_3 = new QLabel(CapsuleCollider);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(CapsuleCollider);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        label_4 = new QLabel(CapsuleCollider);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit_3 = new QLineEdit(CapsuleCollider);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(CapsuleCollider);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lineEdit_4 = new QLineEdit(CapsuleCollider);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_2->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(CapsuleCollider);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        lineEdit_5 = new QLineEdit(CapsuleCollider);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        horizontalLayout_3->addWidget(lineEdit_5);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        line = new QFrame(CapsuleCollider);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        retranslateUi(CapsuleCollider);

        QMetaObject::connectSlotsByName(CapsuleCollider);
    } // setupUi

    void retranslateUi(QWidget *CapsuleCollider)
    {
        CapsuleCollider->setWindowTitle(QApplication::translate("CapsuleCollider", "Form", Q_NULLPTR));
        checkBox->setText(QApplication::translate("CapsuleCollider", "Capsule Collider", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("CapsuleCollider", "Is Trigger", Q_NULLPTR));
        label->setText(QApplication::translate("CapsuleCollider", "Center", Q_NULLPTR));
        label_2->setText(QApplication::translate("CapsuleCollider", "X", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("CapsuleCollider", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("CapsuleCollider", "Y", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("CapsuleCollider", "0", Q_NULLPTR));
        label_4->setText(QApplication::translate("CapsuleCollider", "Z", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("CapsuleCollider", "0", Q_NULLPTR));
        label_5->setText(QApplication::translate("CapsuleCollider", "Radius", Q_NULLPTR));
        lineEdit_4->setText(QApplication::translate("CapsuleCollider", "0.5", Q_NULLPTR));
        label_6->setText(QApplication::translate("CapsuleCollider", "Height", Q_NULLPTR));
        lineEdit_5->setText(QApplication::translate("CapsuleCollider", "2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CapsuleCollider: public Ui_CapsuleCollider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPSULECOLLIDER_H
