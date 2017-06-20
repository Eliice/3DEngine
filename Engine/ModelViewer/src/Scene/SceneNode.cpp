#include "Scene\SceneNode.h"
#include "Component\Component.h"
#include "Component\Transform.h"
#include "Component\Mesh.h"
#include "Service\ServiceLocator.h"

#include "Component\Collider.h"
SceneNode::SceneNode(std::string name, SceneNode* parent)
{
	m_Parent = parent;
	m_name = name;
	m_Transform = new component::Transform();
	m_components = std::unordered_map<component::ComponentType, std::vector<component::Component*>>();
	m_Children = std::vector<SceneNode*>();
	if (m_Parent != nullptr)
	{
		SetScene(m_Parent->GetScene());
	}
}


SceneNode::~SceneNode()
{
	std::unordered_map<component::ComponentType, std::vector<component::Component*>>::iterator iter = m_components.begin();
	std::unordered_map<component::ComponentType, std::vector<component::Component*>>::iterator end = m_components.end();

	while (iter != end)
	{
		std::vector<component::Component*> components = iter->second;
		for (int i = 0; i < components.size(); i++)
			delete components[i];

		components.clear();
		++iter;
	}

	m_components.clear();

	for (int index = 0; index < m_Children.size(); ++index)
		delete m_Children[index];

	m_Children.clear();
	m_Parent = nullptr;
}

void SceneNode::Initialize()
{
	m_Transform->SetGameObject(this);
	if (m_Parent && m_Transform->GetParent() == nullptr)
		m_Transform->SetParent(m_Parent->GetTransform());

	for (SceneNode* node : m_Children)
		node->Initialize();
}

void SceneNode::SetParent(SceneNode* parent)
{
	if (parent == nullptr)
		return;

	m_Parent = parent;
}

void SceneNode::AddChild(SceneNode* node)
{
	if (node == nullptr)
		return;
	m_Children.push_back(node);
}

void SceneNode::CreateMesh(std::string const& name, std::string const& path)
{
	component::Mesh* mesh = new component::Mesh(this, name, path);

	component::Transform* transform = GetTransform();
	
	if (transform)
		transform->ApplyTransform();

	AddComponent(component::ComponentType::MESH, mesh);
}

void SceneNode::AddComponent(component::ComponentType type, component::Component * new_component)
{
		m_components[type].push_back(new_component);
		if (type == component::ComponentType::COLLIDER)
		{
			component::Collider* collider = dynamic_cast<component::Collider*>(new_component);
			PHYSX->AddToScene(m_Scene->GetPxScene(), collider->GetActor());
		}
}

void SceneNode::Start()
{
	int index = 0;
	for (int i = 0; i < component::ComponentType::COUNT; ++i)
	{
		size_t size = m_components[(component::ComponentType)i].size();
		for(index; index < size ; ++ index)
		{
			component::Component* compo = m_components[(component::ComponentType)i][index];
			compo->Start();
		}
	}
	index = 0;
	size_t size = m_Children.size();
	for (index ;  index < size ; ++ index)
	{
		SceneNode* child = m_Children[index];
		child->Start();
	}
}

void SceneNode::Update()
{
	std::unordered_map<component::ComponentType, std::vector<component::Component*>>::iterator start = m_components.begin();
	std::unordered_map<component::ComponentType, std::vector<component::Component*>>::iterator end = m_components.end();
	int index = 0;
	size_t size = 0;
	for (; start != end; ++start)
	{
		size = start->second.size();
		for(index; index < size; ++index)
		{
			component::Component* comp = start->second[index];
			if(comp->IsVisible())
				comp->Update();
		}
	}

	UpdateChildren();
}

void SceneNode::UpdateChildren()
{
	int index = 0;
	int size = 0;
	for (index; index < size; ++index)
	{
		m_Children[index]->Update();
	}
}

void SceneNode::SetTransform(component::Transform * newTransform, SceneNode* gameobject)
{
	m_Transform = newTransform;
	m_Transform->SetGameObject(gameobject);
	if (m_Transform->GetParent() == nullptr)
		m_Transform->SetParent(m_Parent->GetTransform());
}

void SceneNode::Move(math::Vector3 moveVec)
{
	m_Transform->Translate(moveVec);
}

void SceneNode::SetCurrentScene(Scene* newScene)
{
	if (!newScene)
		return;

	m_CurrectScene = newScene;
}

void SceneNode::SetName(std::string value)
{
	m_name = value;
}

std::string SceneNode::Serialize()
{
	std::string data;

	m_nodeNb = m_Children.size();
	data = "\n \t node:\n\t {\n\t\t name: " + m_name + ",\n \t\t nodeNb: " + std::to_string(m_nodeNb) + ",\n" + m_Transform->Serialize() + "\t },";
	int index = 0;
	size_t size = m_Children.size();
	for(index; index < size ; ++ index)
	{
		SceneNode* child = m_Children[index];
		data += child->Serialize();
	}

	return data;
}

void SceneNode::Deserialize(std::string& data)
{
	std::string str;

	Scene* current = SCENE_MANAGER->GetScene("test");
	SceneNode* model = new SceneNode();

	data.erase(0, data.find_first_of(":") + 2);
	data.erase(0, data.find_first_of(":") + 2);
	str = data.substr(0, data.find_first_of(","));

	m_name = str;

	data.erase(0, data.find_first_of(":") + 2);
	str = data.substr(0, data.find_first_of(","));

	m_nodeNb = std::stoi(str);

	if (m_name != "root")
	{
		model = current->AddMeshNode(m_name);
		model->SetTransform(m_Transform, model);
	}
	m_Transform->Deserialize(data);

	while (m_nodeNb > 0)
	{
		SceneNode* node = new SceneNode();
		node->Deserialize(data);
		m_nodeNb--;
		m_Children.push_back(node);
	}
}

void SceneNode::FixedUpdate()
{
	int index = 0;
	size_t size = 0;
	for (int i = 0; i < component::ComponentType::COUNT; ++i)
	{
		index = 0;
		size = m_components[(component::ComponentType)i].size();
		for (index; index < size; ++ index)
		{
			component::Component* compo = m_components[(component::ComponentType)i][index];
			switch ((component::ComponentType)i)
			{
			case component::ComponentType::MESH:
			{
				component::Mesh* mesh = dynamic_cast<component::Mesh*>(compo);
				mesh->FixedUpdate();
				break;
			}
			case component::ComponentType::TEXTURE:
			{
				break;
			}
			case component::ComponentType::COLLIDER:
			{
				component::Collider* collider = dynamic_cast<component::Collider*>(compo);
				collider->FixedUpdate();
				break;
			}
				
			default:
				break;
			}
		}
	}
	index = 0;
	size = m_Children.size();
	for(index; index < size; ++ index)
	{
		SceneNode * child = m_Children[index];
		child->FixedUpdate();
	}
}

void SceneNode::LateUpdate()
{
	int index = 0;
	size_t size = 0;
	for (int i = 0; i < component::ComponentType::COUNT; ++i)
	{
		size = m_components[(component::ComponentType)i].size();
		for(index; index < size; ++ index)
		{
			component::Component* compo = m_components[(component::ComponentType)i][index];
			compo->LateUpdate();
		}
	}
	index = 0;
	size = m_Children.size();
	for (index ; index < size; ++ index)
	{
		SceneNode* child = m_Children[index];
		child->LateUpdate();
	}
}

void SceneNode::Destroy()
{
	size_t size = 0;
	int index = 0;
	for (int i = 0; i < component::ComponentType::COUNT; ++i)
	{
		size = m_components[(component::ComponentType)i].size();
		for(index ; index < size ; ++ index)
		{
			component::Component* compo = m_components[(component::ComponentType)i][index];
			compo->Destroy();
			//delete compo;
		}
	}
	index = 0;
	size = m_Children.size();
	for(index; index < size; ++ index)
	{
		SceneNode* child = m_Children[index];
		child->Destroy();
	}
}

void SceneNode::OverlapCheck()
{
	int i = 0;
	std::vector<component::Component*> colliders = GetComponents(component::ComponentType::COLLIDER);
	size_t collidercomponentSize = colliders.size();
	for (i; i < collidercomponentSize; ++i)
	{
		component::Collider* collider = dynamic_cast<component::Collider*>(colliders[i]);
		/*if (*/PHYSX->Overlaps(collider);/*)
		{

		}*/
	}
}

void SceneNode::SetScene(Scene * scene)
{
	m_Scene = scene;
}

void SceneNode::Hide()
{
	m_Visible = false;
}

void SceneNode::Show()
{
	m_Visible = true;
}