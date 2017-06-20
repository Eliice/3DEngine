#pragma once

#include "Component\Component.h"
#include "DllExport.h"

#include "Service\servicelocator.h"

namespace physx {
	class PxRigidActor;
}


namespace component {

	class Collider : public Component {

	public:
		Collider() = default;
		ENGINE_DLL Collider(std::string colliderType,SceneNode* node);
		~Collider() = default;

		void FixedUpdate() override;
		void setActor(physx::PxRigidActor* actor);
		inline physx::PxRigidActor* GetActor() {return m_Colliders;}
		inline ShapeType getShape() { return m_type;}
	private:
		physx::PxRigidActor* m_Colliders = nullptr;
		ShapeType m_type;

	};
} 