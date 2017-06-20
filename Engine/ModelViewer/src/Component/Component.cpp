#include "Component\Component.h"
#include "Scene\scenenode.h"



#include "Service\servicelocator.h"
namespace component
{
	Component::Component(std::string const& name)
	{
		m_Name = name;
	}


	Component::~Component()
	{
	}

	void Component::SetGameObject(SceneNode* gameObject)
	{
		if (gameObject == nullptr)
			return;

		m_GameObject = gameObject;
	}

	void Component::Start()
	{
	}

	void Component::Update()
	{
	}

	std::string Component::Serialize()
	{
		std::string data;
		data = "{\n component: \n name: " + m_Name + ",\n visible: " + std::to_string(m_visible) + "\n},\n";
		return data;
	}
	void Component::Deserialize(std::string& data)
	{
		
		std::string str;

		data.erase(0, data.find_first_of(":") + 2);
		data.erase(0, data.find_first_of(":") + 2);
		str = data.substr(0, data.find_first_of(","));

		m_Name = str;

		data.erase(0, data.find_first_of(":") + 2);
		str = data.substr(0, data.find_first_of(","));


		if (str == "1")
			m_visible = true;
		else
			m_visible = false;

	}
	void Component::FixedUpdate()
	{
	}
	void Component::LateUpdate()
	{
	}
	void Component::Destroy()
	{
		delete m_GameObject;
	}
	void Component::OverLap()
	{
	}
	void Component::SetName(std::string value)
	{
		m_Name = value;
	}
	void Component::SetVisible(bool visible)
	{
		m_visible = visible;
	}
}