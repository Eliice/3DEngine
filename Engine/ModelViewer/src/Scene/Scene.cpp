#include "Scene\Scene.h"
#include "Service\Tools.h"

#include "Component\Collider.h"

Scene::Scene(std::string name, SceneNode * root)
{
	if (root == nullptr)
		m_root = new SceneNode();
	else
		m_root = root;
	m_root->SetScene(this);
	m_name = name;

	m_Skybox = new Skybox("../ModelViewer/pisa.hdr");
	m_Skybox->Initialize();
	math::Vector3 gravity(0, -9.81, 0);
	m_PhysicScene = PHYSX->CreateScene(gravity);
	m_Controller = PHYSX->InitControler(m_PhysicScene);
}

Scene::~Scene()
{
	delete m_root;
	delete m_Skybox;

	m_root = nullptr;
	m_Skybox = nullptr;
}

void Scene::Initialize()
{
	m_root->Initialize();
	m_Skybox->Initialize();
}

void Scene::AddNewNode(SceneNode * newNode, SceneNode* parentNode)
{
	if (!newNode)
		return;

	if (m_root == nullptr)
		m_root = newNode;
	else if (parentNode == nullptr)
		m_root->AddChild(newNode);
	else
		parentNode->AddChild(newNode);

	newNode->SetCurrentScene(this);
}

//void Scene::AddCamera()
//{
//	m_Camera = new Camera(m_root);
//	m_root->AddChild(m_Camera);
//}

void Scene::Start()
{
	if (m_root != nullptr)
		m_root->Start();
}

void Scene::Update()
{
	if (m_root != nullptr)
		m_root->Update();
}

bool Scene::CheckName(std::string check)
{
	if (m_name == check)
		return true;
	else
		return false;
}

void Scene::setName(std::string new_name)
{
	m_name = new_name;
}

SceneNode* Scene::AddMeshNode(std::string const& meshName, SceneNode* parent, std::string const& path)
{
	SceneNode* parentNode;
	if (parent)
		parentNode = parent;
	else
		parentNode = m_root;

	SceneNode* node = new SceneNode(meshName, parentNode);
	AddNewNode(node, parentNode);
	component::Transform* transform = new component::Transform();

 	node->SetTransform(transform, node);
	node->CreateMesh(meshName, path);

	return node;
}

SceneNode * Scene::AddCubeNode()
{
	SceneNode* node = AddMeshNode("EngineCube");
	return node;
}

SceneNode* Scene::AddSphereNode()
{
	return AddMeshNode("EngineSphere");
}

SceneNode* Scene::AddCapsuleNode()
{
	SceneNode* node =  AddMeshNode("EngineCapsule");
	return node;
}

void Scene::SetActive(bool active)
{
	m_IsActive = active;
}

std::string Scene::Serialize()
{
	std::string data;
	data = "{\n scene\n name: " + m_name + ",\n {\n" + m_Skybox->Serialize() + SCENE_MANAGER->GetCamera()->Serialize() +  m_root->Serialize() + " },\n}";
	return data;
}

void Scene::Deserialize(std::string& data)
{
	std::string str;

	data.erase(0, data.find_first_of(":") + 2);
	str = data.substr(0, data.find_first_of(","));

	m_name = str;

	m_Skybox->Deserialize(data);
	SCENE_MANAGER->GetCamera()->Deserialize(data);
	m_root->Deserialize(data);
	
}

void Scene::FixedUpdate()
{
	if(m_root != nullptr)
		m_root->FixedUpdate();
}

void Scene::LateUpdate()
{
	if (m_root != nullptr)
		m_root->LateUpdate();
}

void Scene::Destroy()
{
	if (m_root != nullptr)
		m_root->Destroy();
}

void Scene::Overlap()
{
	m_root->OverlapCheck();
}
