#include "Component\Collider.h"

#include "Service\PhysXWrapper.h"
#include "Component\Transform.h"
#include "Scene\SceneNode.h"

#include "Service\ServiceLocator.h"


namespace component {

	Collider::Collider(std::string colliderType,SceneNode* node)
		:Component("Collider")
	{
		m_GameObject = node;
		physx::PxMaterial* material = PHYSX->CreateMaterial(math::Vector3(0, 0, 0));
		if (colliderType == "Cube")
			m_type = ShapeType::BOX;

		else 
			m_type = ShapeType::CAPSULE;
		m_Colliders = PHYSX->CreateActor(material, false, m_type, m_GameObject->GetTransform()->getGlobalTranslation(), m_GameObject->GetTransform()->getGlobalRotation(), nullptr);
		m_GameObject->AddComponent(component::ComponentType::COLLIDER, this);
	}
	void Collider::FixedUpdate()
	{

		Transform* selfTrans = GetGameObject()->GetTransform();
		Transform* parent = selfTrans->GetParent();

		physx::PxTransform transform = m_Colliders->getGlobalPose();

		math::Vector3 newTranslat(transform.p.x, transform.p.y, transform.p.z);
		selfTrans->SetTranslate(newTranslat - parent->getGlobalTranslation());


		math::Vector3 newRotation(transform.q.x, transform.q.y, transform.q.z);
		selfTrans->SetRotate(newRotation /** parent->getGlobalRotation().conj()*/);
	}

	void Collider::setActor(physx::PxRigidActor * actor)
	{
		m_Colliders = actor;
	}

}