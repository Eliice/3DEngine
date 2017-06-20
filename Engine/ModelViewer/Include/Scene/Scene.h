#pragma once

#include <string>
#include "Helpers\GlewHelper.h"
#include "Scene\SceneNode.h"
#include "Scene\Camera.h"
#include "Component\Mesh.h"
#include "Component\Transform.h"
#include "Component\BasicShader.h"
#include "Service\ServiceLocator.h"
#include "Scene\Skybox.h"

#include "DllExport.h"

class SceneNode;
class Camera;
class Skybox;

namespace physx {
	class PxScene;
	class PxControllerManager;
}

class Scene
{
public:
	ENGINE_DLL Scene(std::string name ="root", SceneNode* root=nullptr);
	~Scene();

	void Initialize();

	void AddNewNode(SceneNode* newNode, SceneNode* parentNode = nullptr);
	//void AddCamera();


	bool CheckName(std::string check);
	void setName(std::string new_name);
	std::string GetName() const { return m_name; }
	inline SceneNode* GetRoot() { return m_root; }
	inline Skybox* GetSkybox() { return m_Skybox; }

	ENGINE_DLL SceneNode* AddMeshNode(std::string const& meshName, SceneNode* parent = nullptr, std::string const& path = "");

	ENGINE_DLL SceneNode* AddCubeNode();
	ENGINE_DLL SceneNode* AddSphereNode();
	ENGINE_DLL SceneNode* AddCapsuleNode();
	physx::PxControllerManager* GetController() { return m_Controller; }

	ENGINE_DLL void SetActive(bool active);
	inline bool IsActive() const { return m_IsActive; }
	inline physx::PxScene* GetPxScene() { return m_PhysicScene; }
	SceneNode* AddModelTest() const;

	std::string Serialize();
	void Deserialize(std::string&);

	void Start();
	void Update();
	void FixedUpdate();
	void LateUpdate();
	ENGINE_DLL void Destroy();
	void Overlap();
private:
	SceneNode* m_root;
	physx::PxScene* m_PhysicScene;
	physx::PxControllerManager* m_Controller;

	Skybox* m_Skybox;

	std::string m_name;

	bool m_IsActive = true;
};

