/********************************************************************************
** Form generated from reading UI file 'spherecollider.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPHERECOLLIDER_H
#define UI_SPHERECOLLIDER_H

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

class Ui_SphereCollider
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
    QSpacerItem *horizontalSpacer_2;
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
    QFrame *line;

    void setupUi(QWidget *SphereCollider)
    {
        if (SphereCollider->objectName().isEmpty())
            SphereCollider->setObjectName(QStringLiteral("SphereCollider"));
        SphereCollider->resize(320, 139);
        verticalLayout_2 = new QVBoxLayout(SphereCollider);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        checkBox = new QCheckBox(SphereCollider);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        checkBox->setFont(font);

        horizontalLayout_3->addWidget(checkBox);


        verticalLayout->addLayout(horizontalLayout_3);

        checkBox_2 = new QCheckBox(SphereCollider);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        label = new QLabel(SphereCollider);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(SphereCollider);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(SphereCollider);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_3 = new QLabel(SphereCollider);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(SphereCollider);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        label_4 = new QLabel(SphereCollider);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit_3 = new QLineEdit(SphereCollider);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(SphereCollider);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer = new QSpacerItem(120, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lineEdit_4 = new QLineEdit(SphereCollider);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_2->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        line = new QFrame(SphereCollider);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        retranslateUi(SphereCollider);

        QMetaObject::connectSlotsByName(SphereCollider);
    } // setupUi

    void retranslateUi(QWidget *SphereCollider)
    {
        SphereCollider->setWindowTitle(QApplication::translate("SphereCollider", "Form", Q_NULLPTR));
        checkBox->setText(QApplication::translate("SphereCollider", "Sphere Collider", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("SphereCollider", "Is Trigger", Q_NULLPTR));
        label->setText(QApplication::translate("SphereCollider", "Center", Q_NULLPTR));
        label_2->setText(QApplication::translate("SphereCollider", "X", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("SphereCollider", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("SphereCollider", "Y", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("SphereCollider", "0", Q_NULLPTR));
        label_4->setText(QApplication::translate("SphereCollider", "Z", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("SphereCollider", "0", Q_NULLPTR));
        label_5->setText(QApplication::translate("SphereCollider", "Radius", Q_NULLPTR));
        lineEdit_4->setText(QApplication::translate("SphereCollider", "0.5", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SphereCollider: public Ui_SphereCollider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPHERECOLLIDER_H
