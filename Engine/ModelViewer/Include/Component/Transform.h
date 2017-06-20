#pragma once

#include "Vector3.h"
#include "Mat4.h"
#include "Component.h"

namespace component
{
	class Transform : public Component
	{

	public:

		Transform(Transform *parent = nullptr);


		Transform(math::Vector3 const&, Transform *parent = nullptr);
		Transform(math::Vector3 const& translate, math::Vector3 const& rotate, Transform *parent = nullptr);
		Transform(math::Vector3 const& translate, math::Vector3 const& rotate, math::Vector3 const& scale, Transform *parent = nullptr);

		virtual ~Transform();

		inline math::Vector3 getTranslate() const { return m_Translate; }
		inline math::Vector3 getRotate() const { return m_Rotate; }
		inline math::Vector3 getScale() const { return m_Scale; }
		inline Transform* GetParent() { return m_Parent; }
		math::Mat4& GetWorld() { return m_World; }

		math::Vector3 getGlobalTranslation();
		math::Vector3 getGlobalRotation();

		void SetParent(Transform*);

		void Translate(math::Vector3 const&);
		void Rotate(math::Vector3 const&);
		ENGINE_DLL void Scale(math::Vector3 const&);

		std::string Serialize() override;
		void Deserialize(std::string& data) override;

		ENGINE_DLL void SetTranslate(math::Vector3 newTranslate);
		ENGINE_DLL void SetRotate(math::Vector3 newRotate);

		ENGINE_DLL void ApplyTransform();

	private:
		math::Vector3 m_Translate;
		math::Vector3 m_Rotate;
		math::Vector3 m_Scale;
		Transform* m_Parent;

		math::Mat4 m_World;


	};
}