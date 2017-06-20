/********************************************************************************
** Form generated from reading UI file 'transform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORM_H
#define UI_TRANSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Transform
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit;
    QCheckBox *checkBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *line;

    void setupUi(QWidget *Transform)
    {
        if (Transform->objectName().isEmpty())
            Transform->setObjectName(QStringLiteral("Transform"));
        Transform->resize(330, 108);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Transform->sizePolicy().hasHeightForWidth());
        Transform->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Transform);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox = new QCheckBox(Transform);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setCheckable(true);
        checkBox->setChecked(true);

        horizontalLayout->addWidget(checkBox);

        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        lineEdit = new QLineEdit(Transform);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        checkBox_2 = new QCheckBox(Transform);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout->addWidget(checkBox_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(Transform);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(44, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        comboBox = new QComboBox(Transform);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(76, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(Transform);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(24, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(Transform);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(Transform);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(Transform);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_3);

        line = new QFrame(Transform);
        line->setObjectName(QStringLiteral("line"));
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(Transform);

        QMetaObject::connectSlotsByName(Transform);
    } // setupUi

    void retranslateUi(QWidget *Transform)
    {
        Transform->setWindowTitle(QApplication::translate("Transform", "Form", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Transform", "    Visible", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("Transform", "   Static", Q_NULLPTR));
        label->setText(QApplication::translate("Transform", "Tag", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Transform", "Untagged", Q_NULLPTR)
         << QApplication::translate("Transform", "MainCamera", Q_NULLPTR)
         << QApplication::translate("Transform", "Player", Q_NULLPTR)
         << QApplication::translate("Transform", "GameController", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Transform", "Prefabs", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Transform", "Select", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Transform", "Revert", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Transform", "Apply", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Transform: public Ui_Transform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORM_H
