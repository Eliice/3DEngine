#include "QSceneNode.h"
#include "QComponentWidget.h"
#include "Scene\SceneNode.h"
#include "Component\Transform.h"

QSceneNode::QSceneNode(QString const& name, SceneNode* node)
	: QListWidgetItem(name, nullptr, 1000)
{
	m_Node = node;
	m_Name = name;
}


QSceneNode::~QSceneNode()
{
	m_Components.clear();
	m_Node = nullptr;
}

void QSceneNode::AddComponent(QComponentWidget* newComponent)
{
	if (!newComponent)
		return;

	newComponent->SetGameObject(this);
	m_Components.push_back(newComponent);
	m_ComponentCount = m_Components.size();

	newComponent->Initialize();
}

void QSceneNode::ShowComponents() const
{
	for (int i = 0; i < m_ComponentCount; i++)
	{
		QComponentWidget* component = m_Components[i];
		QMap<QString, QString> data = m_ComponentData[component->GetName()];
		component->LoadValues(data);
		component->show();
	}
}

void QSceneNode::HideComponents()
{
	for (int i = 0; i < m_ComponentCount; i++)
	{
		QComponentWidget* component = m_Components[i];
		m_ComponentData[component->GetName()] = component->GetValues();
		component->hide();
	}
}

void QSceneNode::SetNodePosition(math::Vector3 const& position, math::Vector3 const& rotation, math::Vector3 const& scale)
{
	component::Transform* transform = m_Node->GetTransform();

	transform->SetTranslate(position);
	transform->SetRotate(rotation);
	transform->Scale(scale);

	transform->ApplyTransform();
}

void QSceneNode::SetName(QString const& name)
{
	m_Name = name;
}