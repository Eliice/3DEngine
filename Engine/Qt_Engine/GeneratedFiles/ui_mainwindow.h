/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qscenetree.h"
#include "sdlwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Scene;
    QAction *actionOpen_Scene;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionSave_Project;
    QAction *actionSave_Project_as;
    QAction *actionBuild_Settings;
    QAction *actionBuild_Run;
    QAction *actionExit;
    QAction *actionNew_Project;
    QAction *action_Undo;
    QAction *action_Redo;
    QAction *action_Cut;
    QAction *action_Copy;
    QAction *action_Past;
    QAction *actionDuplicate;
    QAction *action_Delete;
    QAction *action_Find;
    QAction *action_Select;
    QAction *action_Play;
    QAction *action_Pause;
    QAction *actionFolder;
    QAction *actionC_Scripts;
    QAction *actionOpen;
    QAction *actionDelete;
    QAction *actionCamera;
    QAction *actionCube;
    QAction *actionSphere;
    QAction *actionCapsule;
    QAction *actionPhysX;
    QAction *actionRHI;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QSceneTree *ListHierarchy;
    QTabWidget *Rendu;
    QWidget *Scene;
    QGridLayout *gridLayout_3;
    SDLWidget *openGLWidget;
    QWidget *Game;
    QTabWidget *Debug;
    QWidget *Project;
    QGridLayout *gridLayout_5;
    QTreeView *Arbo;
    QWidget *Console;
    QHBoxLayout *horizontalLayout_4;
    QTabWidget *Inspector;
    QWidget *tabWidgetPag2_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *InspectorLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *Rotate;
    QPushButton *Pick;
    QPushButton *Scale;
    QPushButton *Move;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Pause;
    QPushButton *Play;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAssets;
    QMenu *menu_Create;
    QMenu *menuGameObject;
    QMenu *menu3D_Object;
    QMenu *menuComponent;
    QMenu *menuWindow;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1078, 560);
        actionNew_Scene = new QAction(MainWindow);
        actionNew_Scene->setObjectName(QStringLiteral("actionNew_Scene"));
        actionOpen_Scene = new QAction(MainWindow);
        actionOpen_Scene->setObjectName(QStringLiteral("actionOpen_Scene"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionSave_Project = new QAction(MainWindow);
        actionSave_Project->setObjectName(QStringLiteral("actionSave_Project"));
        actionSave_Project_as = new QAction(MainWindow);
        actionSave_Project_as->setObjectName(QStringLiteral("actionSave_Project_as"));
        actionBuild_Settings = new QAction(MainWindow);
        actionBuild_Settings->setObjectName(QStringLiteral("actionBuild_Settings"));
        actionBuild_Run = new QAction(MainWindow);
        actionBuild_Run->setObjectName(QStringLiteral("actionBuild_Run"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionNew_Project = new QAction(MainWindow);
        actionNew_Project->setObjectName(QStringLiteral("actionNew_Project"));
        action_Undo = new QAction(MainWindow);
        action_Undo->setObjectName(QStringLiteral("action_Undo"));
        action_Redo = new QAction(MainWindow);
        action_Redo->setObjectName(QStringLiteral("action_Redo"));
        action_Cut = new QAction(MainWindow);
        action_Cut->setObjectName(QStringLiteral("action_Cut"));
        action_Copy = new QAction(MainWindow);
        action_Copy->setObjectName(QStringLiteral("action_Copy"));
        action_Past = new QAction(MainWindow);
        action_Past->setObjectName(QStringLiteral("action_Past"));
        actionDuplicate = new QAction(MainWindow);
        actionDuplicate->setObjectName(QStringLiteral("actionDuplicate"));
        action_Delete = new QAction(MainWindow);
        action_Delete->setObjectName(QStringLiteral("action_Delete"));
        action_Find = new QAction(MainWindow);
        action_Find->setObjectName(QStringLiteral("action_Find"));
        action_Select = new QAction(MainWindow);
        action_Select->setObjectName(QStringLiteral("action_Select"));
        action_Play = new QAction(MainWindow);
        action_Play->setObjectName(QStringLiteral("action_Play"));
        action_Pause = new QAction(MainWindow);
        action_Pause->setObjectName(QStringLiteral("action_Pause"));
        actionFolder = new QAction(MainWindow);
        actionFolder->setObjectName(QStringLiteral("actionFolder"));
        actionC_Scripts = new QAction(MainWindow);
        actionC_Scripts->setObjectName(QStringLiteral("actionC_Scripts"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionCamera = new QAction(MainWindow);
        actionCamera->setObjectName(QStringLiteral("actionCamera"));
        actionCube = new QAction(MainWindow);
        actionCube->setObjectName(QStringLiteral("actionCube"));
        actionSphere = new QAction(MainWindow);
        actionSphere->setObjectName(QStringLiteral("actionSphere"));
        actionCapsule = new QAction(MainWindow);
        actionCapsule->setObjectName(QStringLiteral("actionCapsule"));
        actionPhysX = new QAction(MainWindow);
        actionPhysX->setObjectName(QStringLiteral("actionPhysX"));
        actionRHI = new QAction(MainWindow);
        actionRHI->setObjectName(QStringLiteral("actionRHI"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        ListHierarchy = new QSceneTree(centralWidget);
        ListHierarchy->setObjectName(QStringLiteral("ListHierarchy"));

        horizontalLayout_5->addWidget(ListHierarchy);

        Rendu = new QTabWidget(centralWidget);
        Rendu->setObjectName(QStringLiteral("Rendu"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(186);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Rendu->sizePolicy().hasHeightForWidth());
        Rendu->setSizePolicy(sizePolicy);
        Scene = new QWidget();
        Scene->setObjectName(QStringLiteral("Scene"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Scene->sizePolicy().hasHeightForWidth());
        Scene->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(Scene);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        openGLWidget = new SDLWidget(Scene);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        gridLayout_3->addWidget(openGLWidget, 0, 0, 1, 1);

        Rendu->addTab(Scene, QString());
        Game = new QWidget();
        Game->setObjectName(QStringLiteral("Game"));
        sizePolicy1.setHeightForWidth(Game->sizePolicy().hasHeightForWidth());
        Game->setSizePolicy(sizePolicy1);
        Rendu->addTab(Game, QString());

        horizontalLayout_5->addWidget(Rendu);


        verticalLayout_2->addLayout(horizontalLayout_5);

        Debug = new QTabWidget(centralWidget);
        Debug->setObjectName(QStringLiteral("Debug"));
        sizePolicy1.setHeightForWidth(Debug->sizePolicy().hasHeightForWidth());
        Debug->setSizePolicy(sizePolicy1);
        Project = new QWidget();
        Project->setObjectName(QStringLiteral("Project"));
        sizePolicy1.setHeightForWidth(Project->sizePolicy().hasHeightForWidth());
        Project->setSizePolicy(sizePolicy1);
        gridLayout_5 = new QGridLayout(Project);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        Arbo = new QTreeView(Project);
        Arbo->setObjectName(QStringLiteral("Arbo"));

        gridLayout_5->addWidget(Arbo, 0, 0, 1, 1);

        Debug->addTab(Project, QString());
        Console = new QWidget();
        Console->setObjectName(QStringLiteral("Console"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Console->sizePolicy().hasHeightForWidth());
        Console->setSizePolicy(sizePolicy2);
        Debug->addTab(Console, QString());

        verticalLayout_2->addWidget(Debug);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_4->setContentsMargins(0, 0, 0, -1);
        Inspector = new QTabWidget(centralWidget);
        Inspector->setObjectName(QStringLiteral("Inspector"));
        sizePolicy1.setHeightForWidth(Inspector->sizePolicy().hasHeightForWidth());
        Inspector->setSizePolicy(sizePolicy1);
        tabWidgetPag2_2 = new QWidget();
        tabWidgetPag2_2->setObjectName(QStringLiteral("tabWidgetPag2_2"));
        tabWidgetPag2_2->setEnabled(true);
        sizePolicy1.setHeightForWidth(tabWidgetPag2_2->sizePolicy().hasHeightForWidth());
        tabWidgetPag2_2->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(tabWidgetPag2_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        InspectorLayout = new QVBoxLayout();
        InspectorLayout->setSpacing(0);
        InspectorLayout->setObjectName(QStringLiteral("InspectorLayout"));
        InspectorLayout->setSizeConstraint(QLayout::SetFixedSize);

        gridLayout_2->addLayout(InspectorLayout, 0, 0, 1, 1);

        Inspector->addTab(tabWidgetPag2_2, QString());

        horizontalLayout_4->addWidget(Inspector);


        gridLayout->addLayout(horizontalLayout_4, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Rotate = new QPushButton(centralWidget);
        Rotate->setObjectName(QStringLiteral("Rotate"));

        horizontalLayout->addWidget(Rotate);

        Pick = new QPushButton(centralWidget);
        Pick->setObjectName(QStringLiteral("Pick"));

        horizontalLayout->addWidget(Pick);

        Scale = new QPushButton(centralWidget);
        Scale->setObjectName(QStringLiteral("Scale"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Scale->sizePolicy().hasHeightForWidth());
        Scale->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(Scale);

        Move = new QPushButton(centralWidget);
        Move->setObjectName(QStringLiteral("Move"));
        sizePolicy3.setHeightForWidth(Move->sizePolicy().hasHeightForWidth());
        Move->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(Move);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(400, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        Pause = new QPushButton(centralWidget);
        Pause->setObjectName(QStringLiteral("Pause"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Pause->sizePolicy().hasHeightForWidth());
        Pause->setSizePolicy(sizePolicy4);

        horizontalLayout_2->addWidget(Pause);

        Play = new QPushButton(centralWidget);
        Play->setObjectName(QStringLiteral("Play"));

        horizontalLayout_2->addWidget(Play);

        horizontalSpacer = new QSpacerItem(113, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1078, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuAssets = new QMenu(menuBar);
        menuAssets->setObjectName(QStringLiteral("menuAssets"));
        menu_Create = new QMenu(menuAssets);
        menu_Create->setObjectName(QStringLiteral("menu_Create"));
        menuGameObject = new QMenu(menuBar);
        menuGameObject->setObjectName(QStringLiteral("menuGameObject"));
        menu3D_Object = new QMenu(menuGameObject);
        menu3D_Object->setObjectName(QStringLiteral("menu3D_Object"));
        menuComponent = new QMenu(menuBar);
        menuComponent->setObjectName(QStringLiteral("menuComponent"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuAssets->menuAction());
        menuBar->addAction(menuGameObject->menuAction());
        menuBar->addAction(menuComponent->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuFile->addAction(actionNew_Scene);
        menuFile->addAction(actionOpen_Scene);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionNew_Project);
        menuFile->addAction(actionSave_Project_as);
        menuFile->addSeparator();
        menuFile->addAction(actionBuild_Settings);
        menuFile->addAction(actionBuild_Run);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(action_Undo);
        menuEdit->addAction(action_Redo);
        menuEdit->addSeparator();
        menuEdit->addAction(action_Cut);
        menuEdit->addAction(action_Copy);
        menuEdit->addAction(action_Past);
        menuEdit->addSeparator();
        menuEdit->addAction(actionDuplicate);
        menuEdit->addAction(action_Delete);
        menuEdit->addSeparator();
        menuEdit->addAction(action_Find);
        menuEdit->addAction(action_Select);
        menuEdit->addSeparator();
        menuEdit->addAction(action_Play);
        menuEdit->addAction(action_Pause);
        menuAssets->addAction(menu_Create->menuAction());
        menuAssets->addAction(actionOpen);
        menuAssets->addAction(actionDelete);
        menu_Create->addAction(actionFolder);
        menu_Create->addAction(actionC_Scripts);
        menuGameObject->addAction(menu3D_Object->menuAction());
        menuGameObject->addAction(actionCamera);
        menu3D_Object->addAction(actionCube);
        menu3D_Object->addAction(actionSphere);
        menu3D_Object->addAction(actionCapsule);
        menuComponent->addAction(actionPhysX);
        menuWindow->addAction(actionRHI);

        retranslateUi(MainWindow);

        Rendu->setCurrentIndex(0);
        Debug->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Engine 2.0", Q_NULLPTR));
        actionNew_Scene->setText(QApplication::translate("MainWindow", "&New Scene", Q_NULLPTR));
        actionNew_Scene->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
        actionOpen_Scene->setText(QApplication::translate("MainWindow", "&Open Scene", Q_NULLPTR));
        actionOpen_Scene->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "&Save Scene", Q_NULLPTR));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        actionSave_as->setText(QApplication::translate("MainWindow", "&Save Scene as ...", Q_NULLPTR));
        actionSave_as->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", Q_NULLPTR));
        actionSave_Project->setText(QApplication::translate("MainWindow", "Save Project", Q_NULLPTR));
        actionSave_Project_as->setText(QApplication::translate("MainWindow", "Open Project ...", Q_NULLPTR));
        actionBuild_Settings->setText(QApplication::translate("MainWindow", "&Build Settings", Q_NULLPTR));
        actionBuild_Settings->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+B", Q_NULLPTR));
        actionBuild_Run->setText(QApplication::translate("MainWindow", "&Build && Run", Q_NULLPTR));
        actionBuild_Run->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionNew_Project->setText(QApplication::translate("MainWindow", "New Project ...", Q_NULLPTR));
        action_Undo->setText(QApplication::translate("MainWindow", "&Undo", Q_NULLPTR));
        action_Undo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", Q_NULLPTR));
        action_Redo->setText(QApplication::translate("MainWindow", "&Redo", Q_NULLPTR));
        action_Redo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", Q_NULLPTR));
        action_Cut->setText(QApplication::translate("MainWindow", "&Cut", Q_NULLPTR));
        action_Cut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", Q_NULLPTR));
        action_Copy->setText(QApplication::translate("MainWindow", "&Copy", Q_NULLPTR));
        action_Copy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
        action_Past->setText(QApplication::translate("MainWindow", "&Past", Q_NULLPTR));
        action_Past->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", Q_NULLPTR));
        actionDuplicate->setText(QApplication::translate("MainWindow", "&Duplicate", Q_NULLPTR));
        actionDuplicate->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", Q_NULLPTR));
        action_Delete->setText(QApplication::translate("MainWindow", "&Delete", Q_NULLPTR));
        action_Delete->setShortcut(QApplication::translate("MainWindow", "Shift+Del", Q_NULLPTR));
        action_Find->setText(QApplication::translate("MainWindow", "&Find", Q_NULLPTR));
        action_Find->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
        action_Select->setText(QApplication::translate("MainWindow", "&Select All", Q_NULLPTR));
        action_Select->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", Q_NULLPTR));
        action_Play->setText(QApplication::translate("MainWindow", "&Play", Q_NULLPTR));
        action_Play->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", Q_NULLPTR));
        action_Pause->setText(QApplication::translate("MainWindow", "&Pause", Q_NULLPTR));
        action_Pause->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+P", Q_NULLPTR));
        actionFolder->setText(QApplication::translate("MainWindow", "Folder", Q_NULLPTR));
        actionC_Scripts->setText(QApplication::translate("MainWindow", "C++ Scripts", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        actionCamera->setText(QApplication::translate("MainWindow", "&Camera", Q_NULLPTR));
        actionCube->setText(QApplication::translate("MainWindow", "&Cube", Q_NULLPTR));
        actionSphere->setText(QApplication::translate("MainWindow", "&Sphere", Q_NULLPTR));
        actionCapsule->setText(QApplication::translate("MainWindow", "&Capsule", Q_NULLPTR));
        actionPhysX->setText(QApplication::translate("MainWindow", "PhysX", Q_NULLPTR));
        actionRHI->setText(QApplication::translate("MainWindow", "RHI", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "    Hierarchie", Q_NULLPTR));
        Rendu->setTabText(Rendu->indexOf(Scene), QApplication::translate("MainWindow", "Scene", Q_NULLPTR));
        Rendu->setTabText(Rendu->indexOf(Game), QApplication::translate("MainWindow", "Game", Q_NULLPTR));
        Debug->setTabText(Debug->indexOf(Project), QApplication::translate("MainWindow", "Project", Q_NULLPTR));
        Debug->setTabText(Debug->indexOf(Console), QApplication::translate("MainWindow", "Console", Q_NULLPTR));
        Inspector->setTabText(Inspector->indexOf(tabWidgetPag2_2), QApplication::translate("MainWindow", "Inspector", Q_NULLPTR));
        Pick->setText(QString());
        Pause->setText(QApplication::translate("MainWindow", "Pause", Q_NULLPTR));
        Play->setText(QApplication::translate("MainWindow", "Play", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuAssets->setTitle(QApplication::translate("MainWindow", "Assets", Q_NULLPTR));
        menu_Create->setTitle(QApplication::translate("MainWindow", "&Create", Q_NULLPTR));
        menuGameObject->setTitle(QApplication::translate("MainWindow", "GameObject", Q_NULLPTR));
        menu3D_Object->setTitle(QApplication::translate("MainWindow", "3D Object", Q_NULLPTR));
        menuComponent->setTitle(QApplication::translate("MainWindow", "Component", Q_NULLPTR));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Engine 2.0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
