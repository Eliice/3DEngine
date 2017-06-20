#pragma once
#include "Service.h"

#include <PxPhysicsAPI.h>
#include <foundation\PxFoundation.h>
#include <cooking\PxCooking.h>
#include <extensions\PxExtensionsAPI.h>
#include <characterkinematic\PxCharacter.h>


#include <Vector3.h>

#pragma comment(lib, "PhysX3DEBUG_x64.lib")
#pragma comment(lib, "PhysX3CommonDEBUG_x64.lib")
#pragma comment(lib, "PxFoundationDEBUG_x64.lib")
#pragma comment(lib, "PhysX3ExtensionsDEBUG.lib")
#pragma comment(lib, "PhysX3CookingDEBUG_x64.lib")
#pragma comment(lib, "PhysX3CharacterKinematicDEBUG_x64.lib")

namespace math {
	struct Vector3;
	struct Vector4;
}

namespace component
{
	class Mesh;
	class Collider;
}

class Scene;
class SceneNode;

class ErrorCallback : public physx::PxErrorCallback
{
public:
	ErrorCallback() = default;
        ~ErrorCallback() = default ;

        virtual void reportError(physx::PxErrorCode::Enum code, const char* message, const char* file, int line);
};

enum ShapeType
{
	CAPSULE,
	BOX,
	TRIANGLEMESH,
};

class HitResult
{
public:
	SceneNode* nodeHit;
	math::Vector3 hitLocation;
	math::Vector3 hitNormal;
	float hitDistance;
};

namespace tools
{
	namespace service
	{

		class PhysXWrapper :	public Service
		{
		public:

			PhysXWrapper();
			~PhysXWrapper();

			void Initialize();
			void Shutdown();
			physx::PxScene* CreateScene(math::Vector3 Gravity);
			physx::PxControllerManager* InitControler(physx::PxScene*);
			physx::PxMaterial* CreateMaterial(math::Vector3 const parameter); // parameter is : static friction, dynamic friction and output (restitution)
			physx::PxRigidActor* CreateActor(physx::PxMaterial* material, bool isStatic, ShapeType type, math::Vector3 translation, math::Vector3 rotation, component::Mesh* mesh = nullptr);
			physx::PxController* CreateCharacterControler(Scene* scene);
			void ResizeControler(physx::PxController*, float height = NULL, float radius = NULL);
			void Movecontroler(physx::PxController* toMove, math::Vector3 displacementVector, float elapsedTime);
			void AddToScene(physx::PxScene* scene, physx::PxActor*);
			void RemoveFromScene(physx::PxScene* scene, physx::PxActor* actor);
			void PhysicLoop();
			HitResult* RayCast(component::Collider* origineEntity, math::Vector3 direction ,uint32_t maxHit, uint32_t maxDist); ///TODO: have to be opti
			void Overlaps(component::Collider* collider);
			void EnablePhyscDebug(physx::PxScene*);
			physx::PxTransform ToPxTransform(math::Vector3 translation, math::Vector3 rotation);

			
		private:
			
			physx::PxFoundation* m_PxFoundation = nullptr;

			bool m_RecordMemoryAllocations = true;
			physx::PxPhysics* m_Physics = nullptr;
			physx::PxCudaContextManager* m_CudaManager = nullptr;
			physx::PxCooking* m_Cooking = nullptr;
			physx::PxCpuDispatcher* m_CpuDispatcher = nullptr;
			

			physx::PxShape* CreateBox(physx::PxMaterial* material,  physx::PxRigidActor* actor);
			physx::PxShape* CreateCapsule(physx::PxMaterial* material,  physx::PxRigidActor* actor);
			physx::PxTriangleMeshGeometry* CreateMesh(component::Mesh* mesh);
			void SwitchShape(physx::PxRigidActor* actor, physx::PxMaterial* material, ShapeType type, component::Mesh* mesh = nullptr);

			physx::PxDefaultAllocator* m_DefaultAllocator = nullptr;
			ErrorCallback* m_ErrorCallBack = nullptr;

			SceneNode* findNodeByActor(physx::PxActor* actor);
		};

	}
}

