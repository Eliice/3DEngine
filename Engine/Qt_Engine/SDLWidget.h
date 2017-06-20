#pragma once
#include <QOpenGLWidget>
#include "system.h"

class Scene;
class SceneNode;
class QtSystem;

class SDLWidget :
	public QOpenGLWidget
{
	Q_OBJECT

public:
	SDLWidget(QWidget* parent = nullptr);
	virtual ~SDLWidget();

	void CreateScene(QString const& sceneName = "New Scene");

	virtual void initializeGL() override;
	virtual void paintGL() override;

	SceneNode* AddCubeNode();
	SceneNode* AddSphereNode();
	SceneNode* AddCapsuleNode();

	void SetScene(Scene* newScene);

	Scene* GetScene() const { return m_Scene; }

private:
	QtSystem* m_System;
	QTimer* m_Timer;

	Scene*		m_Scene;
};

