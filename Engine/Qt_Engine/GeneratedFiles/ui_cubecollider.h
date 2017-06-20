/********************************************************************************
** Form generated from reading UI file 'cubecollider.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUBECOLLIDER_H
#define UI_CUBECOLLIDER_H

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

class Ui_CubeCollider
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QFrame *line;

    void setupUi(QWidget *CubeCollider)
    {
        if (CubeCollider->objectName().isEmpty())
            CubeCollider->setObjectName(QStringLiteral("CubeCollider"));
        CubeCollider->resize(320, 160);
        verticalLayout_2 = new QVBoxLayout(CubeCollider);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        checkBox = new QCheckBox(CubeCollider);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        checkBox->setFont(font);

        horizontalLayout_3->addWidget(checkBox);


        verticalLayout->addLayout(horizontalLayout_3);

        checkBox_2 = new QCheckBox(CubeCollider);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        label = new QLabel(CubeCollider);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(CubeCollider);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit = new QLineEdit(CubeCollider);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_4 = new QLabel(CubeCollider);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit_2 = new QLineEdit(CubeCollider);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        label_5 = new QLabel(CubeCollider);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        lineEdit_3 = new QLineEdit(CubeCollider);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(CubeCollider);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_7 = new QLabel(CubeCollider);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        lineEdit_5 = new QLineEdit(CubeCollider);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        horizontalLayout_2->addWidget(lineEdit_5);

        label_6 = new QLabel(CubeCollider);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        lineEdit_4 = new QLineEdit(CubeCollider);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_2->addWidget(lineEdit_4);

        label_8 = new QLabel(CubeCollider);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        lineEdit_6 = new QLineEdit(CubeCollider);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        horizontalLayout_2->addWidget(lineEdit_6);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        line = new QFrame(CubeCollider);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        retranslateUi(CubeCollider);

        QMetaObject::connectSlotsByName(CubeCollider);
    } // setupUi

    void retranslateUi(QWidget *CubeCollider)
    {
        CubeCollider->setWindowTitle(QApplication::translate("CubeCollider", "Form", Q_NULLPTR));
        checkBox->setText(QApplication::translate("CubeCollider", "Box Collider", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("CubeCollider", "Is Trigger", Q_NULLPTR));
        label->setText(QApplication::translate("CubeCollider", "Center", Q_NULLPTR));
        label_3->setText(QApplication::translate("CubeCollider", "X", Q_NULLPTR));
        label_4->setText(QApplication::translate("CubeCollider", "Y", Q_NULLPTR));
        label_5->setText(QApplication::translate("CubeCollider", "Z", Q_NULLPTR));
        label_2->setText(QApplication::translate("CubeCollider", "Size", Q_NULLPTR));
        label_7->setText(QApplication::translate("CubeCollider", "X", Q_NULLPTR));
        label_6->setText(QApplication::translate("CubeCollider", "Y", Q_NULLPTR));
        label_8->setText(QApplication::translate("CubeCollider", "Z", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CubeCollider: public Ui_CubeCollider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUBECOLLIDER_H
