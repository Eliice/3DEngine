#pragma once
#include <string>

class SceneNode;

namespace component
{
	class Component
	{
	public:
		Component(std::string const& name);
		virtual ~Component();

		virtual SceneNode* GetGameObject() const { return m_GameObject; }
		virtual std::string GetName() const { return m_Name; }

		virtual void SetGameObject(SceneNode* gameObject);

		virtual std::string Serialize();


		virtual void Start();
		virtual void Update();
		virtual void FixedUpdate();
		virtual void LateUpdate();
		virtual void Destroy();
		virtual void OverLap();


		virtual void SetName(std::string value);
		virtual void SetVisible(bool visible);
		virtual void Deserialize(std::string& data);

		virtual inline void Visible() { m_visible = true; }
		virtual inline void Unvisible() { m_visible = false; }
		virtual inline bool IsVisible() { return m_visible; }

	protected:
		std::string m_Name;
		bool m_visible = true;
		SceneNode* m_GameObject = nullptr;
	};
}