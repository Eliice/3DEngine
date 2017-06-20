#include "Service\servicelocator.h"
#include <qtimer.h>
#include <qdebug.h>
#include "SDLWidget.h"
#include "Helpers\SDLHelper.h"
#include "QtSystem.h"
#include "Scene\Scene.h"
#include "Scene\SceneNode.h"
#undef main


SDLWidget::SDLWidget(QWidget* parent)
	: QOpenGLWidget(parent)
{
	m_System = new QtSystem();
	m_Timer = new QTimer();
	m_Timer->connect(m_Timer, SIGNAL(timeout()), this, SLOT(update()));
	m_Timer->start(1000 / 60);
}


SDLWidget::~SDLWidget()
{
	SCENE_MANAGER->RemoveAllScenes();
	m_Scene->Destroy();
	m_Timer->stop();

	delete m_System;
	delete m_Timer;

	m_Scene = nullptr;
}

void SDLWidget::CreateScene(QString const& sceneName)
{
	SCENE_MANAGER->RemoveAllScenes();
	m_Scene->Destroy();
	m_Scene = SCENE_MANAGER->AddScene(sceneName.toStdString(), true);
}

void SDLWidget::initializeGL()
{
	m_System->Initialize();
	m_Scene = SCENE_MANAGER->GetScene("DefaultScene");
}

void SDLWidget::paintGL()
{
	RENDERER->RenderLoop();
}

SceneNode* SDLWidget::AddCubeNode()
{
	return m_Scene->AddCubeNode();
}

SceneNode* SDLWidget::AddSphereNode()
{
	return m_Scene->AddSphereNode();
}

SceneNode* SDLWidget::AddCapsuleNode()
{
	return m_Scene->AddCapsuleNode();
}

void SDLWidget::SetScene(Scene* newScene)
{
	if (!newScene)
		return;

	m_Scene->Destroy();
	m_Scene = newScene;
}