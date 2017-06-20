#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVector>
#include <QListWidgetItem>

#include "qboxlayout.h"

//#include "Service\servicelocator.h"
//#include "Scene\Scene.h"

#include "QtSystem.h"
#include "exitdialog.h"
#include "transform.h"
#include "position.h"
#include "addcomponentfont.h"
#include "cubecollider.h"
#include "spherecollider.h"
#include "capsulecollider.h"
#include "collider.h"

class System;
class QSceneNode;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();

	Scene* GetScene() { return SCENE_MANAGER->GetScene(currentSceneName); }
	std::string GetSceneName() { return currentSceneName; }
	std::string GetProjectName() { return currentProject.toStdString(); }

	Ui::MainWindow*     ui;

signals:
	void contextMenuRequested(QPoint& point);

public slots:
	void OpenComponent();
	void Save();
	void ShowMenu();

private slots:

    void on_actionNew_Scene_triggered();

    void on_actionExit_triggered();

    void on_actionCube_triggered();
    void on_actionSphere_triggered();
    void on_actionCapsule_triggered();

    void on_ListHierarchy_clicked(QListWidgetItem* item);
	void SelectCollider();
	void on_actionCamera_triggered();

    void on_actionSave_triggered();
    void on_actionSave_as_triggered();
    void on_actionOpen_Scene_triggered();
    void on_actionNew_Project_triggered();
    void on_actionFolder_triggered();
    void on_actionC_Scripts_triggered();
	
    void on_Play_clicked();
    void on_Pause_clicked();

    void on_ListHierarchy_clicked(const QModelIndex &index);
	void mousePressEvent(QMouseEvent* e);

private:


	void InitArbo();
	void InitRepository();

	void AddItem(SceneNode* node);

	void UpdatePosition(SceneNode* object);
	void RemoveItemOfLayout(QLayout* l);
	void ResetObjectNb();

	void Initialize();
	void Shutdown();

	QtSystem*			m_QtSystem;
	QTimer*				m_Timer;
    
	QString				m_CurrentName;
	std::string			currentSceneName;
	QString				currentProject = "NewProject";

    Transform*          Transformdialog;
    ExitDialog*         Exitdialog;
    Position*           Positiondialog;
    CubeCollider*       CubeColliderdialog;
    SphereCollider*     SphereColliderdialog;
    CapsuleCollider*    CapsuleColliderdialog;
    Collider*           Colliderdialog;

    AddComponentFont*   Component;

    

	

    int					cubeNb = 0;
    int					sphereNb = 0;
    int					capsuleNb = 0;
    int					cameraNb = 0;

	bool				isPressed = true;
};

#endif // MAINWINDOW_H
