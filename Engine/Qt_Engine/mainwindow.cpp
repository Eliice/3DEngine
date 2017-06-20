#include <QGroupBox>
#include <qfiledialog.h>
#include <QRadioButton>
#include <QTabWidget>
#include <qdirmodel.h>
#include <QFileSystemModel>
#include <QTimer>
#include <qevent.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "System.h"
#include "QSceneNode.h"

MainWindow::MainWindow() :
    QMainWindow(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	Initialize();

	Exitdialog = new ExitDialog(this);
	Exitdialog->hide();
	
	currentSceneName = "DefaultScene";

    connect(Component->GetPushButton(), SIGNAL(clicked()), this, SLOT(OpenComponent()));
	connect(Exitdialog->GetSaveButton(), SIGNAL(clicked()), this, SLOT(Save()));
	connect(this, SIGNAL(contextMenuRequested(const QPoint&)), this, SLOT(ShowMenu()));
}

MainWindow::~MainWindow()
{
    delete ui;

	Shutdown();

    delete Exitdialog;
}

void MainWindow::on_actionNew_Scene_triggered()
{
	ui->ListHierarchy->clear();
	RemoveItemOfLayout(ui->InspectorLayout);
	ResetObjectNb();
}

void MainWindow::Save()
{
	Scene* scene = ui->openGLWidget->GetScene();
	SERIALIZER->Save(scene, "../../../../Documents/" + currentProject.toStdString() + "/Scenes/" + currentSceneName + ".json");
}

void MainWindow::ShowMenu()
{
	///create menu clic droit
}

void MainWindow::on_actionExit_triggered()
{ 
    Exitdialog->show();
}

void MainWindow::on_actionCube_triggered()
{
	SceneNode* cube = ui->openGLWidget->AddCubeNode();
	m_CurrentName = "Cube";

	if (cubeNb > 0)
		m_CurrentName += " " + QString::number(cubeNb);

	AddItem(cube);

	cubeNb++;
	UpdatePosition(cube);


}

void MainWindow::on_actionSphere_triggered()
{
	SceneNode* sphere = ui->openGLWidget->AddSphereNode();
    
	m_CurrentName = "Sphere";

	if (cubeNb > 0)
		m_CurrentName += " " + QString::number(sphereNb);
    
	AddItem(sphere);

    sphereNb++;
	UpdatePosition(sphere);
}

void MainWindow::on_actionCapsule_triggered()
{
	SceneNode* capsule = ui->openGLWidget->AddCapsuleNode();
	m_CurrentName = "Capsule";

    if ( capsuleNb != 0)
		m_CurrentName += " " + QString::number(capsuleNb);

	AddItem(capsule);

    capsuleNb++;
	UpdatePosition(capsule);
}

void MainWindow::on_ListHierarchy_clicked(QListWidgetItem* item)
{
	RemoveItemOfLayout(ui->InspectorLayout);
	ui->ListHierarchy->LoadActiveNode();
}

void MainWindow::on_actionCamera_triggered()
{
    if ( cameraNb != 0)
    {
        m_CurrentName = "Camera " + QString::number(cameraNb);
        ui->ListHierarchy->addItem(m_CurrentName);
    }
    else
    {
        m_CurrentName = "Camera ";
        ui->ListHierarchy->addItem(m_CurrentName);
    }
    cameraNb++;
}

void MainWindow::AddItem(SceneNode* node)
{
	if (!node)
		return;

	QSceneNode* newNode = new QSceneNode(m_CurrentName, node);

	ui->ListHierarchy->AddNode(newNode);

	ui->InspectorLayout->addWidget(Transformdialog, -1, Qt::AlignTop);
	//Transformdialog->GetTransformText(ui->ListHierarchy->currentItem()->text());
	ui->InspectorLayout->addWidget(Positiondialog, -1, Qt::AlignTop);
	//ui->InspectorLayout->addWidget(Component, -1, Qt::AlignTop);
	ui->InspectorLayout->addWidget(Colliderdialog, -1, Qt::AlignTop);

	Transformdialog->setLayout(ui->InspectorLayout);
	Positiondialog->setLayout(ui->InspectorLayout);
	Colliderdialog->setLayout(ui->InspectorLayout);
	//Component->setLayout(ui->InspectorLayout);

	newNode->AddComponent(Transformdialog);
	newNode->AddComponent(Positiondialog);
	newNode->AddComponent(Colliderdialog);
	//newNode->AddComponent(Component);
}

void MainWindow::UpdatePosition(SceneNode * object)
{
	component::Transform* position = object->GetTransform();
	Positiondialog->SetPosition(position->getTranslate(), position->getRotate(), position->getScale());
}

void MainWindow::RemoveItemOfLayout(QLayout* l)
{
	QLayoutItem* item;
	while (item = l->takeAt(0))
	{
		QWidget* widget = item->widget();

		if (item->layout())
			RemoveItemOfLayout(item->layout());
	}
}

void MainWindow::ResetObjectNb()
{
	cubeNb = 0;
	sphereNb = 0;
	capsuleNb = 0;
	cameraNb = 0;
}

void MainWindow::Initialize()
{
	m_QtSystem = new QtSystem();

	Transformdialog = new Transform();
	Positiondialog = new Position();
	Component = new AddComponentFont();
	Colliderdialog = new Collider();

	CubeColliderdialog = new CubeCollider();
	CapsuleColliderdialog = new CapsuleCollider();
	SphereColliderdialog = new SphereCollider();

	InitRepository();
	InitArbo();
	ui->InspectorLayout->setDirection(QBoxLayout::TopToBottom);

	ui->InspectorLayout->setSpacing(0);
	ui->InspectorLayout->setContentsMargins(0,0,0,0);
	
	ui->InspectorLayout->setContentsMargins(0, 0, 0, 0);

	connect(ui->ListHierarchy, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_ListHierarchy_clicked(QListWidgetItem*)));
}

void MainWindow::OpenComponent()
{
	QSceneNode* node = ui->ListHierarchy->GetSelectedNode();

	ui->InspectorLayout->removeWidget(Component);
	//Component->unsetLayoutDirection();
	//ui->InspectorLayout->replaceWidget(Component, Colliderdialog);

	ui->InspectorLayout->addWidget(Colliderdialog, -1, Qt::AlignBottom);
	Colliderdialog->setLayout(ui->InspectorLayout);

	node->AddComponent(Colliderdialog);
}

void MainWindow::InitArbo()
{
	QFileSystemModel* model = new QFileSystemModel();
	model->setRootPath(QDir::currentPath());

	ui->Arbo->setModel(model);
	ui->Arbo->setRootIndex(model->index("../../../../Documents/" + currentProject));
}

void MainWindow::InitRepository()
{
	QDir* dir = new QDir();
	dir->setPath("../../../../Documents/");
	
	dir->mkdir(currentProject);
	dir->mkdir(currentProject + "/Scenes");
	dir->mkdir(currentProject + "/Scripts");
}

void MainWindow::Shutdown()
{
	delete Transformdialog;
	delete Positiondialog;
	delete Component;

	delete CubeColliderdialog;
	delete CapsuleColliderdialog;
	delete SphereColliderdialog;
}

void MainWindow::SelectCollider()
{
    if(ui->ListHierarchy->currentItem()->text().contains("Cube"))
    {
        ui->InspectorLayout->removeWidget(CubeColliderdialog);
        ui->InspectorLayout->removeWidget(SphereColliderdialog);
        ui->InspectorLayout->removeWidget(CapsuleColliderdialog);

        ui->InspectorLayout->addWidget(CubeColliderdialog);
    }

    if(ui->ListHierarchy->currentItem()->text().contains("Sphere"))
    {
        ui->InspectorLayout->removeWidget(SphereColliderdialog);
        ui->InspectorLayout->removeWidget(CubeColliderdialog);
        ui->InspectorLayout->removeWidget(CapsuleColliderdialog);

        ui->InspectorLayout->addWidget(SphereColliderdialog);
    }

    if(ui->ListHierarchy->currentItem()->text().contains("Capsule"))
    {
        ui->InspectorLayout->removeWidget(CapsuleColliderdialog);
        ui->InspectorLayout->removeWidget(CubeColliderdialog);
        ui->InspectorLayout->removeWidget(SphereColliderdialog);

        ui->InspectorLayout->addWidget(CapsuleColliderdialog);
    }
}

void MainWindow::on_actionSave_triggered()
{
	Scene* scene = ui->openGLWidget->GetScene();

	SERIALIZER->Save(scene, "../../../../Documents/" + currentProject.toStdString() + "/Scenes/" + currentSceneName + ".json");
}

void MainWindow::on_actionSave_as_triggered()
{
	QString filename = QFileDialog::getSaveFileName(this, "Save file", "../../../../Documents/" + currentProject + "/Scenes/" + currentProject, "*.json");
	Scene* scene = ui->openGLWidget->GetScene();

	if ( filename != nullptr)
		SERIALIZER->Save(scene, filename.toStdString());
}

void MainWindow::on_actionOpen_Scene_triggered()
{
	QString filename = QFileDialog::getOpenFileName(this, "Open file", "../../../../Documents/" + currentProject + "/Scenes/" + currentProject, "*.json");

	if (filename != nullptr)
	{
		Scene* newScene = SERIALIZER->Deserialize(filename.toStdString());
		ui->openGLWidget->SetScene(newScene);
	}
}

void MainWindow::on_actionNew_Project_triggered()
{
	QString filename = QFileDialog::getSaveFileName(this, "New Project", "../../../../Documents/");
	QDir dir = QDir::root();
	
	if (filename != nullptr)
	{
		dir.mkdir(filename);
		dir.mkdir(filename + "/Scenes/");
		dir.mkdir(filename + "/Scripts/");
		currentProject = filename;
	}
}

void MainWindow::on_actionFolder_triggered()
{
	QString filename = QFileDialog::getSaveFileName(this, "New Directory", "../../../../Documents/" + currentProject);
	QDir dir = QDir::root();

	if ( filename != nullptr)
		dir.mkdir(filename);
}

void MainWindow::on_actionC_Scripts_triggered()
{
	QString filename = QFileDialog::getSaveFileName(this, "New Directory", "../../../../Documents/" + currentProject + "/Scripts/");
	QFile h(filename + ".h");
	QFile cpp(filename + ".cpp");

	if (h.open(QIODevice::ReadWrite))
	{
		filename = h.readAll();
		h.close();
	}
	
	if (cpp.open(QIODevice::ReadWrite))
	{
		filename = cpp.readAll();
		cpp.close();
	}
}

void MainWindow::on_Play_clicked()
{
	QFile file("../ModelViewer/Saves/autosave.json");
	Scene* scene = ui->openGLWidget->GetScene();

	if (isPressed == true)
	{
		SERIALIZER->Save(scene, "../ModelViewer/Saves/autosave.json");
		m_QtSystem->StartSimulation();
		ui->Play->setText("Stop");
		isPressed = false;
	}
	else
	{
		scene->Destroy();
		SCENE_MANAGER->GetScene(currentSceneName)->GetRoot()->Destroy();
		m_QtSystem->StopSimulation();
		scene = SERIALIZER->Deserialize("../ModelViewer/Saves/autosave.json");
		file.remove();
		ui->Play->setText("Play");
		isPressed = true;
	}
}

void MainWindow::on_Pause_clicked()
{
    if( isPressed == true)
        m_QtSystem->StopSimulation();
}

void MainWindow::on_ListHierarchy_clicked(const QModelIndex &index)
{

}

void MainWindow::mousePressEvent(QMouseEvent* e)
{
	if (e->button() == Qt::RightButton)
		emit contextMenuRequested(e->pos());

	QWidget::mousePressEvent(e);
}
