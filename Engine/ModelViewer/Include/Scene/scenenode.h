#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "Component\ComponentType.h"
#include "DllExport.h"

class Scene;

namespace component
{
	class Transform;
	class Component;
}

namespace math
{
	struct Vector3;
}
class SceneNode
{
public:
	
	SceneNode(std::string name = "root" , SceneNode* parent = nullptr);
	~SceneNode();

	virtual void Initialize();
	void SetParent(SceneNode* parent);
	void AddChild(SceneNode* node);


	void CreateMesh(std::string const& name, std::string const& path);

	void AddComponent(component::ComponentType type, component::Component* new_component);
	inline std::vector<component::Component*> GetComponents(component::ComponentType type) { return m_components[type]; }
	void UpdateChildren();
	void SetTransform(component::Transform* newTransform, SceneNode* gameObject);
	void Move(math::Vector3);

	inline std::vector<SceneNode*> GetChildren() { return m_Children; }
	inline component::Transform* GetTransform() { return m_Transform; }

	void SetCurrentScene(Scene* newScene);
	inline Scene* GetCurrentScene() const { return m_CurrectScene; }

	inline bool IsVisible() const { return m_Visible; }
	inline Scene* GetScene() { return m_Scene; }
	void SetScene(Scene* scene);
	void Hide();
	void Show();

	void SetName(std::string value);

	virtual std::string Serialize();
	virtual void Deserialize(std::string& data);


	void Start();
	void Update();
	void FixedUpdate();
	void LateUpdate();
	ENGINE_DLL void Destroy();
	void OverlapCheck();

protected:
	Scene* m_CurrectScene = nullptr;

	std::string m_name;
	SceneNode* m_Parent;
	Scene* m_Scene;
	size_t m_nodeNb;

	component::Transform* m_Transform = nullptr;
	std::unordered_map<component::ComponentType, std::vector<component::Component*>> m_components;
	std::vector<SceneNode*> m_Children;

	bool m_Visible = true;
};

