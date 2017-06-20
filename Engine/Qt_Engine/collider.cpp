#include "collider.h"
#include "ui_collider.h"
#include "QSceneNode.h"
#include "Component\Collider.h"
#include "Scene\scenenode.h"
#include "Service\servicelocator.h"


Collider::Collider(QWidget *parent) :
    QComponentWidget("Collider", parent),
    ui(new Ui::Collider)
{
    ui->setupUi(this);
	ui->comboBox->addItem("-----");
	ui->comboBox->addItem("Cube");
	ui->comboBox->addItem("Capsule");
}





Collider::~Collider()
{
    delete ui;
}

void Collider::Initialize()
{
}

void Collider::SetUsed(bool isColliderSet)
{
	m_colliderSet = isColliderSet;
}

void Collider::UpdateBox()
{
	SceneNode* node = m_GameObject->GetNode();
	try
	{
		std::vector<component::Component*> compo = node->GetComponents(component::ComponentType::COLLIDER);
		ShapeType colliderType = dynamic_cast<component::Collider*>(compo[0])->getShape();
		switch (colliderType)
		{
		case ShapeType::BOX:
		{
			ui->comboBox->setCurrentIndex(1);
			break;
		}
		case ShapeType::CAPSULE:
		{
			ui->comboBox->setCurrentIndex(2);
			break;
		}
			default:
			{
				ui->comboBox->setCurrentIndex(0);
				break;
			}
		}
	}
	catch (const std::exception&)
	{
		ui->comboBox->setCurrentIndex(0);
	}
	
}


void Collider::on_comboBox_activated(const QString &arg1)
{
	if (!m_colliderSet)
	{
		std::string test = arg1.toStdString();
		if (test == "-----")
		{
			return;
		}
		else
		{
			component::Collider* collider = new component::Collider(test, m_GameObject->GetNode());
			m_colliderSet = true;
		}
	}
}
