#include "Component\Transform.h"

#include "Vector3.h"
#include "Service\ServiceLocator.h"
#include "Component\Collider.h"
namespace component
{
	Transform::Transform(Transform *Tparent)
		: Transform(math::Vector3(), math::Vector3(), math::Vector3(1,1,1), Tparent)
	{
	}

	Transform::Transform(math::Vector3 const & translate, Transform * parent)
		: Transform(translate, math::Vector3(), math::Vector3(1,1,1), parent)
	{
	}

	Transform::Transform(math::Vector3 const & translate, math::Vector3 const & rotate, Transform * parent)
		: Transform(translate, rotate, math::Vector3(1,1,1), parent)
	{
	}

	Transform::Transform(math::Vector3 const & translate, math::Vector3 const & rotate, math::Vector3 const & scale, Transform *parent)
		: Component("Transform")
	{
		m_Parent = parent;
		m_Translate = translate;
		m_Rotate = rotate;
		m_Scale = scale;
		Unvisible();
	}

	Transform::~Transform()
	{
		m_Parent = nullptr;
	}

	math::Vector3 Transform::getGlobalTranslation()
	{
		if (m_Parent != nullptr)
		{
			return m_Translate + m_Parent->getGlobalTranslation();
		}
		else
			return m_Translate;
	}

	auto Transform::getGlobalRotation() -> math::Vector3
	{
		if (m_Parent != nullptr)
		{
			return m_Rotate * m_Parent->getGlobalRotation();
		}
		else
			return m_Rotate;
	}

	void Transform::SetParent(Transform *Tparent)
	{
		m_Parent = Tparent;
	}

	void Transform::Translate(math::Vector3 const& translat)
	{
		m_Translate += translat;
		
		ApplyTransform();
	}

	void Transform::Rotate(math::Vector3 const& rotate)
	{
		m_Rotate += rotate;
		ApplyTransform();
	}

	void Transform::Scale(math::Vector3 const& scale)
	{
		m_Scale = scale;
	}

	void Transform::ApplyTransform()
	{
		math::Mat4 matrix;

		if (m_Parent != nullptr)
			m_World = m_Parent->GetWorld();
		else
			m_World = matrix.Identity;

		m_World *= matrix.MatrixTranslation(m_Translate);
		m_World *= matrix.MatrixRotateY(m_Rotate.y) * matrix.MatrixRotateX(m_Rotate.x) * matrix.MatrixRotateZ(m_Rotate.z);
		m_World *= matrix.MatrixScale(m_Scale);

		SceneNode* node = GetGameObject();
		std::vector<component::Component*> colliders = node->GetComponents(component::ComponentType::COLLIDER);
		int index = 0;
		size_t size = colliders.size();
		for (index; index < size; ++index)
		{
			component::Collider* collider = dynamic_cast<component::Collider*>(colliders[index]);
			if (collider != nullptr)
			{
				physx::PxRigidActor* actor = dynamic_cast<physx::PxRigidActor*>(collider->GetActor());
				if (actor != nullptr)
				{

					//physx::PxTransform newTransform = PHYSX->ToPxTransform(getGlobalTranslation(), getGlobalRotation());
					physx::PxQuat rotationHolder = physx::PxQuat(physx::PxIdentity);
					math::Vector3 gTranslation = getGlobalTranslation();
					physx::PxVec3 translation(gTranslation.x, gTranslation.y, gTranslation.z);
					physx::PxTransform newTransform = physx::PxTransform(translation, rotationHolder);
					actor->setGlobalPose(newTransform);
				}
			}
			
		}
	}

	std::string Transform::Serialize()
	{
		std::string data;
		data = "\t\t {\n \t\t\t component: \n \t\t\t { \n \t\t\t\t name: " + m_Name + ",\n \t\t\t\t { \n \t\t\t\t\t visible: " + std::to_string(m_visible) + ",\n";
		data += "\n \t\t\t\t\t Translate: " + m_Translate.Serialize();
		data += " \t\t\t\t\t Rotation: " + m_Rotate.Serialize();
		data += " \t\t\t\t\t Scale: " + m_Scale.Serialize();
		data += " \t\t\t\t\t World: " + m_World.Serialize();
		data += "\t\t\t\t },\n \t\t\t },\n \t\t },\n";
		return data;
	}
	void Transform::Deserialize(std::string& data)
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

		data.erase(0, data.find_first_of(":") + 2);
		Translate(*m_Translate.Deserialize(data));

		data.erase(0, data.find_first_of(":") + 2);
		Rotate(*m_Rotate.Deserialize(data));

		data.erase(0, data.find_first_of(":") + 2);
		Scale(*m_Scale.Deserialize(data));

		data.erase(0, data.find_first_of(":") + 2);
		m_World = *m_World.Deserialize(data);

		ApplyTransform();
	}
	void Transform::SetTranslate(math::Vector3 newTranslate)
	{
		m_Translate = newTranslate;
		ApplyTransform();
	}
	void Transform::SetRotate(math::Vector3 newRotate)
	{
		m_Rotate = newRotate;
		ApplyTransform();
	}
}