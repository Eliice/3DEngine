/********************************************************************************
** Form generated from reading UI file 'position.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITION_H
#define UI_POSITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Position
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *Transform;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Position_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *PosX;
    QLineEdit *Xpos;
    QLabel *PosY;
    QLineEdit *Ypos;
    QLabel *PosZ;
    QLineEdit *Zpos;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Rotation;
    QSpacerItem *horizontalSpacer_2;
    QLabel *PosX_2;
    QLineEdit *Xrotation;
    QLabel *PosX_5;
    QLineEdit *Yrotation;
    QLabel *PosX_8;
    QLineEdit *Zrotation;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Scale;
    QSpacerItem *horizontalSpacer_3;
    QLabel *PosX_3;
    QLineEdit *Xscale;
    QLabel *PosX_6;
    QLineEdit *Yscale;
    QLabel *PosX_9;
    QLineEdit *Zscale;
    QFrame *line;

    void setupUi(QWidget *Position)
    {
        if (Position->objectName().isEmpty())
            Position->setObjectName(QStringLiteral("Position"));
        Position->resize(320, 126);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Position->sizePolicy().hasHeightForWidth());
        Position->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Position);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Transform = new QLabel(Position);
        Transform->setObjectName(QStringLiteral("Transform"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        font.setStrikeOut(false);
        Transform->setFont(font);

        horizontalLayout->addWidget(Transform);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Position_2 = new QLabel(Position);
        Position_2->setObjectName(QStringLiteral("Position_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Position_2->sizePolicy().hasHeightForWidth());
        Position_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(Position_2);

        horizontalSpacer_4 = new QSpacerItem(7, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        PosX = new QLabel(Position);
        PosX->setObjectName(QStringLiteral("PosX"));
        sizePolicy1.setHeightForWidth(PosX->sizePolicy().hasHeightForWidth());
        PosX->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        PosX->setFont(font1);

        horizontalLayout_2->addWidget(PosX);

        Xpos = new QLineEdit(Position);
        Xpos->setObjectName(QStringLiteral("Xpos"));
        sizePolicy.setHeightForWidth(Xpos->sizePolicy().hasHeightForWidth());
        Xpos->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Xpos);

        PosY = new QLabel(Position);
        PosY->setObjectName(QStringLiteral("PosY"));
        sizePolicy1.setHeightForWidth(PosY->sizePolicy().hasHeightForWidth());
        PosY->setSizePolicy(sizePolicy1);
        PosY->setFont(font1);

        horizontalLayout_2->addWidget(PosY);

        Ypos = new QLineEdit(Position);
        Ypos->setObjectName(QStringLiteral("Ypos"));
        sizePolicy.setHeightForWidth(Ypos->sizePolicy().hasHeightForWidth());
        Ypos->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Ypos);

        PosZ = new QLabel(Position);
        PosZ->setObjectName(QStringLiteral("PosZ"));
        sizePolicy1.setHeightForWidth(PosZ->sizePolicy().hasHeightForWidth());
        PosZ->setSizePolicy(sizePolicy1);
        PosZ->setFont(font1);

        horizontalLayout_2->addWidget(PosZ);

        Zpos = new QLineEdit(Position);
        Zpos->setObjectName(QStringLiteral("Zpos"));
        sizePolicy.setHeightForWidth(Zpos->sizePolicy().hasHeightForWidth());
        Zpos->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Zpos);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Rotation = new QLabel(Position);
        Rotation->setObjectName(QStringLiteral("Rotation"));
        sizePolicy1.setHeightForWidth(Rotation->sizePolicy().hasHeightForWidth());
        Rotation->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(Rotation);

        horizontalSpacer_2 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        PosX_2 = new QLabel(Position);
        PosX_2->setObjectName(QStringLiteral("PosX_2"));
        sizePolicy1.setHeightForWidth(PosX_2->sizePolicy().hasHeightForWidth());
        PosX_2->setSizePolicy(sizePolicy1);
        PosX_2->setFont(font1);

        horizontalLayout_3->addWidget(PosX_2);

        Xrotation = new QLineEdit(Position);
        Xrotation->setObjectName(QStringLiteral("Xrotation"));
        sizePolicy.setHeightForWidth(Xrotation->sizePolicy().hasHeightForWidth());
        Xrotation->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(Xrotation);

        PosX_5 = new QLabel(Position);
        PosX_5->setObjectName(QStringLiteral("PosX_5"));
        sizePolicy1.setHeightForWidth(PosX_5->sizePolicy().hasHeightForWidth());
        PosX_5->setSizePolicy(sizePolicy1);
        PosX_5->setFont(font1);

        horizontalLayout_3->addWidget(PosX_5);

        Yrotation = new QLineEdit(Position);
        Yrotation->setObjectName(QStringLiteral("Yrotation"));
        sizePolicy.setHeightForWidth(Yrotation->sizePolicy().hasHeightForWidth());
        Yrotation->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(Yrotation);

        PosX_8 = new QLabel(Position);
        PosX_8->setObjectName(QStringLiteral("PosX_8"));
        sizePolicy1.setHeightForWidth(PosX_8->sizePolicy().hasHeightForWidth());
        PosX_8->setSizePolicy(sizePolicy1);
        PosX_8->setFont(font1);

        horizontalLayout_3->addWidget(PosX_8);

        Zrotation = new QLineEdit(Position);
        Zrotation->setObjectName(QStringLiteral("Zrotation"));
        sizePolicy.setHeightForWidth(Zrotation->sizePolicy().hasHeightForWidth());
        Zrotation->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(Zrotation);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        Scale = new QLabel(Position);
        Scale->setObjectName(QStringLiteral("Scale"));
        sizePolicy1.setHeightForWidth(Scale->sizePolicy().hasHeightForWidth());
        Scale->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(Scale);

        horizontalSpacer_3 = new QSpacerItem(19, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        PosX_3 = new QLabel(Position);
        PosX_3->setObjectName(QStringLiteral("PosX_3"));
        sizePolicy1.setHeightForWidth(PosX_3->sizePolicy().hasHeightForWidth());
        PosX_3->setSizePolicy(sizePolicy1);
        PosX_3->setFont(font1);

        horizontalLayout_4->addWidget(PosX_3);

        Xscale = new QLineEdit(Position);
        Xscale->setObjectName(QStringLiteral("Xscale"));
        sizePolicy.setHeightForWidth(Xscale->sizePolicy().hasHeightForWidth());
        Xscale->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(Xscale);

        PosX_6 = new QLabel(Position);
        PosX_6->setObjectName(QStringLiteral("PosX_6"));
        sizePolicy1.setHeightForWidth(PosX_6->sizePolicy().hasHeightForWidth());
        PosX_6->setSizePolicy(sizePolicy1);
        PosX_6->setFont(font1);

        horizontalLayout_4->addWidget(PosX_6);

        Yscale = new QLineEdit(Position);
        Yscale->setObjectName(QStringLiteral("Yscale"));
        sizePolicy.setHeightForWidth(Yscale->sizePolicy().hasHeightForWidth());
        Yscale->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(Yscale);

        PosX_9 = new QLabel(Position);
        PosX_9->setObjectName(QStringLiteral("PosX_9"));
        sizePolicy1.setHeightForWidth(PosX_9->sizePolicy().hasHeightForWidth());
        PosX_9->setSizePolicy(sizePolicy1);
        PosX_9->setFont(font1);

        horizontalLayout_4->addWidget(PosX_9);

        Zscale = new QLineEdit(Position);
        Zscale->setObjectName(QStringLiteral("Zscale"));
        sizePolicy.setHeightForWidth(Zscale->sizePolicy().hasHeightForWidth());
        Zscale->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(Zscale);


        verticalLayout->addLayout(horizontalLayout_4);

        line = new QFrame(Position);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(Position);

        QMetaObject::connectSlotsByName(Position);
    } // setupUi

    void retranslateUi(QWidget *Position)
    {
        Position->setWindowTitle(QApplication::translate("Position", "Form", Q_NULLPTR));
        Transform->setText(QApplication::translate("Position", "           Transform", Q_NULLPTR));
        Position_2->setText(QApplication::translate("Position", "Position", Q_NULLPTR));
        PosX->setText(QApplication::translate("Position", "X", Q_NULLPTR));
        Xpos->setText(QString());
        PosY->setText(QApplication::translate("Position", "Y", Q_NULLPTR));
        Ypos->setText(QString());
        PosZ->setText(QApplication::translate("Position", "Z", Q_NULLPTR));
        Zpos->setText(QString());
        Rotation->setText(QApplication::translate("Position", "Rotation", Q_NULLPTR));
        PosX_2->setText(QApplication::translate("Position", "X", Q_NULLPTR));
        Xrotation->setText(QString());
        PosX_5->setText(QApplication::translate("Position", "Y", Q_NULLPTR));
        Yrotation->setText(QString());
        PosX_8->setText(QApplication::translate("Position", "Z", Q_NULLPTR));
        Zrotation->setText(QString());
        Scale->setText(QApplication::translate("Position", "Scale", Q_NULLPTR));
        PosX_3->setText(QApplication::translate("Position", "X", Q_NULLPTR));
        Xscale->setText(QString());
        PosX_6->setText(QApplication::translate("Position", "Y", Q_NULLPTR));
        Yscale->setText(QString());
        PosX_9->setText(QApplication::translate("Position", "Z", Q_NULLPTR));
        Zscale->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Position: public Ui_Position {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITION_H
