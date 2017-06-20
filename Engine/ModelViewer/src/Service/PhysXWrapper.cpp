#include "Service\PhysXWrapper.h"


#include <geometry\PxGeometry.h>
#include <map>
#include "Service\Tools.h"
#include "Service\ServiceLocator.h"
#include "Vector3.h"
#include "Component\Mesh.h"
#include "Component\Collider.h"
#include "Scene\Scene.h"

void ErrorCallback::reportError(physx::PxErrorCode::Enum code, const char * message, const char * file, int line)
{
	const char* errorCode = NULL;

	switch (code)
	{
	case physx::PxErrorCode::eINVALID_PARAMETER:
		errorCode = "invalid parameter";
		break;
	case physx::PxErrorCode::eINVALID_OPERATION:
		errorCode = "invalid operation";
		break;
	case physx::PxErrorCode::eOUT_OF_MEMORY:
		errorCode = "out of memory";
		break;
	case physx::PxErrorCode::eDEBUG_INFO:
		errorCode = "info";
		break;
	case physx::PxErrorCode::eDEBUG_WARNING:
		errorCode = "warning";
		break;
	default:
		errorCode = "unknown error";
		break;
	}
	LOGGER->Debuglog(file, tools::service::ERRORM);
	LOGGER->Debuglog(std::to_string(line), tools::service::ERRORM);
	LOGGER->Debuglog(errorCode, tools::service::ERRORM);
	LOGGER->Debuglog(message, tools::service::ERRORM);
}


SceneNode* RecurciveSearch(SceneNode* node, physx::PxActor* actor)
{
	std::vector<component::Component*> collider = node->GetComponents(component::ComponentType::COLLIDER);
	int i = 0;
	size_t size = collider.size();
	for (i; i < size;++i)
	{
		component::Collider* colider = dynamic_cast<component::Collider*>(collider[i]);
		if (colider->GetActor() == actor)
			return node;
	}
	if (node->GetChildren().size() == 0 )
		return nullptr;
	i = 0;
	std::vector<SceneNode*> nodes = node->GetChildren();
	size = nodes.size();
	for (i; i < size ; ++i )
	{
		SceneNode* testReturn = RecurciveSearch(nodes[i], actor);
		if (testReturn != nullptr)
		{
			return testReturn;
		}
	}
	return nullptr;
}


namespace tools
{
	namespace service
	{

		PhysXWrapper::PhysXWrapper()
		{
			Initialize();
		}

		PhysXWrapper::~PhysXWrapper()
		{
		}

		auto PhysXWrapper::Initialize() -> void
		{
			SetName("PhysxWrapper");
			LOGGER->Debuglog("Initializing PhysX...", LogLevel::INFO);

			m_DefaultAllocator = new physx::PxDefaultAllocator();
			m_ErrorCallBack = new ErrorCallback();
			m_PxFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, *m_DefaultAllocator,
				*m_ErrorCallBack);
			ERROR_MANAGER->CheckPointer(m_PxFoundation);

			m_Physics = PxCreatePhysics(PX_PHYSICS_VERSION, *m_PxFoundation, physx::PxTolerancesScale(),
				m_RecordMemoryAllocations, nullptr);
			ERROR_MANAGER->CheckPointer(m_Physics);

			LOGGER->Debuglog("PhysX core Initialized", LogLevel::INFO);

			m_Cooking = PxCreateCooking(PX_PHYSICS_VERSION, *m_PxFoundation,
				physx::PxCookingParams(physx::PxTolerancesScale()));
			ERROR_MANAGER->CheckPointer(m_Cooking);

			m_CpuDispatcher = physx::PxDefaultCpuDispatcherCreate(2);
			if (!m_CpuDispatcher)
			{
				LOGGER->Debuglog("Creating cpu dispatcher failed !", FATAL);
				ERROR_MANAGER->Fatal();
			}
#ifdef PX_WINDOWS
			physx::PxCudaContextManagerDesc cudaDescriptor;
			m_CudaManager = PxCreateCudaContextManager(*m_PxFoundation, cudaDescriptor);
			ERROR_MANAGER->CheckPointer(m_CudaManager);
			std::string logInit = "GPU acceleration activated on Device: ";
			logInit += m_CudaManager->getDeviceName();
			LOGGER->Debuglog(logInit, LogLevel::INFO);
			logInit = "Driver version: ";
			logInit += m_CudaManager->getDriverVersion();
			LOGGER->Debuglog(logInit, LogLevel::INFO);
			logInit = "Memory: ";
			logInit += m_CudaManager->getDeviceTotalMemBytes();
			LOGGER->Debuglog(logInit, LogLevel::INFO);
			logInit = "SM unit count: ";
			logInit += m_CudaManager->getMultiprocessorCount();
			LOGGER->Debuglog(logInit, LogLevel::INFO);
			logInit = "SM clock frequency: ";
			logInit += m_CudaManager->getClockRate();
			LOGGER->Debuglog(logInit, LogLevel::INFO);
#endif // PX_WINDOWS

		}

		auto PhysXWrapper::Shutdown() -> void
		{
			LOGGER->Debuglog("Shuttind Down PhysX...", LogLevel::INFO);
			m_Cooking->release();
			m_CpuDispatcher = nullptr;
			m_CudaManager->release();
			m_Physics->release();
			m_PxFoundation->release();
			LOGGER->Debuglog("PhysX Shutted down", LogLevel::INFO);
		}

		auto PhysXWrapper::CreateScene(math::Vector3 gravity) -> physx::PxScene *
		{
			physx::PxScene* pxScene = nullptr;
			physx::PxSceneDesc sceneDescriptor(m_Physics->getTolerancesScale());
			sceneDescriptor.gravity = physx::PxVec3(gravity.x, gravity.y, gravity.z);
			physx::PxSimulationFilterShader gDefaultFilterShader = physx::PxDefaultSimulationFilterShader;

			sceneDescriptor.filterShader = gDefaultFilterShader;
			sceneDescriptor.broadPhaseType = physx::PxBroadPhaseType::eSAP;
			sceneDescriptor.frictionType = physx::PxFrictionType::ePATCH;
			sceneDescriptor.cpuDispatcher = m_CpuDispatcher;
			if (m_CudaManager)
			{
				physx::PxGpuDispatcher* GpuDispatcher = m_CudaManager->getGpuDispatcher();
				sceneDescriptor.gpuDispatcher = GpuDispatcher;
				sceneDescriptor.flags |= physx::PxSceneFlag::eENABLE_GPU_DYNAMICS;
				sceneDescriptor.broadPhaseType = physx::PxBroadPhaseType::eGPU;
				LOGGER->Debuglog("Rigide body GPU accelerated enable on created scene", tools::service::LogLevel::INFO);
			}
			else
			{
				LOGGER->Debuglog("Rigide body GPU accelerated invalide", tools::service::LogLevel::INFO);
			}
			ERROR_MANAGER->CheckBool(sceneDescriptor.isValid());
			pxScene = m_Physics->createScene(sceneDescriptor);
			ERROR_MANAGER->CheckPointer(pxScene);

			return pxScene;
		}

		auto PhysXWrapper::InitControler(physx::PxScene *scene) -> physx::PxControllerManager *
		{
			physx::PxControllerManager* manager = PxCreateControllerManager(*scene);
			return manager;
		}

		auto PhysXWrapper::CreateMaterial(math::Vector3 const parameter) -> physx::PxMaterial *
		{
			physx::PxMaterial* newMaterial;

			newMaterial = m_Physics->createMaterial(parameter.x, parameter.y, parameter.z);
			ERROR_MANAGER->CheckPointer(newMaterial);
			return newMaterial;
		}

		auto PhysXWrapper::CreateActor(physx::PxMaterial * material, bool isStatic, ShapeType type, math::Vector3 translation, math::Vector3 rotation, component::Mesh * mesh) -> physx::PxRigidActor *
		{
			physx::PxQuat rotationHolder = physx::PxQuat(physx::PxIdentity);
			//physx::PxTransform pose = ToPxTransform(translation, rotation );
			physx::PxVec3 translationHolder(translation.x, translation.y, translation.z);
			physx::PxTransform pose(translationHolder, rotationHolder);
			if (isStatic)
			{
				physx::PxRigidStatic* actor = m_Physics->createRigidStatic(pose);
				if (actor)
				{
					SwitchShape(actor, material, type, mesh);
					return actor;
				}
			}
			else
			{
				physx::PxRigidDynamic* actor = m_Physics->createRigidDynamic(pose);
				if (actor)
				{
					actor->setRigidBodyFlag(physx::PxRigidBodyFlag::eKINEMATIC, false);
					SwitchShape(actor, material, type, mesh);
					return actor;
				}
			}
			return nullptr;
		}

		auto PhysXWrapper::CreateCharacterControler(Scene* scene) -> physx::PxController *
		{
			physx::PxCapsuleControllerDesc desc;
			desc.radius = 0.5;
			desc.height = 1.f;
			desc.climbingMode = physx::PxCapsuleClimbingMode::eEASY;
			physx::PxController* control = scene->GetController()->createController(desc);
			return control;
		}

		void PhysXWrapper::ResizeControler(physx::PxController* toResize, float height, float radius)
		{
			physx::PxCapsuleController* resize = dynamic_cast<physx::PxCapsuleController*>(toResize);
			if(radius != NULL)
				resize->setRadius(radius);
			if (height != NULL)
				resize->setHeight(height);
		}

		void PhysXWrapper::Movecontroler(physx::PxController * toMove, math::Vector3 displacementVector, float elapsedTime)
		{
			physx::PxVec3 displacement(displacementVector.x, displacementVector.y, displacementVector.z);
			physx::PxControllerFilters filter;
			toMove->move(displacement, 1, elapsedTime, filter, NULL);	
		}

		auto PhysXWrapper::AddToScene(physx::PxScene * scene, physx::PxActor *newActor) -> void
		{
			scene->addActor(*newActor);
		}

		auto PhysXWrapper::RemoveFromScene(physx::PxScene * scene, physx::PxActor * actor) -> void
		{
			scene->removeActor(*actor);
		}

		void PhysXWrapper::PhysicLoop()
		{
			std::unordered_map<std::string,Scene*>* activeScene = SCENE_MANAGER->GetActiveScene();
			int i = 0;
			size_t size = activeScene->size();
			for (i; i < size; i++)
			{
				Scene * scene = Tools::IterateMap(*activeScene, i);
				physx::PxReal elapsedTime(0.04);
				scene->GetPxScene()->simulate(elapsedTime);///TODO argue must not be in hard
				scene->GetPxScene()->fetchResults(true);
			}
		}

		HitResult * PhysXWrapper::RayCast(component::Collider * origineEntity, math::Vector3 direction, uint32_t maxHit, uint32_t maxDist)
		{
			HitResult* result = new HitResult();
			physx::PxRaycastHit hitInfo;
			physx::PxHitFlags hitFlags = physx::PxHitFlag::ePOSITION | physx::PxHitFlag::eNORMAL | physx::PxHitFlag::eDISTANCE;

			math::Vector3 globalTranslate = origineEntity->GetGameObject()->GetTransform()->getGlobalTranslation();
			physx::PxTransform originTranslate = ToPxTransform(globalTranslate, origineEntity->GetGameObject()->GetTransform()->getGlobalRotation());
			const physx::PxVec3 origin(globalTranslate.x, globalTranslate.y, globalTranslate.z);
			physx::PxVec3 pxDirection = physx::PxVec3(direction.x, direction.y, direction.z);

			physx::PxRigidActor* actor = dynamic_cast<physx::PxRigidActor*>(origineEntity->GetActor());
			physx::PxShape** buffershape = nullptr;
			actor->getShapes(buffershape, actor->getNbShapes(), 0);

			physx::PxGeometry geomToTest(buffershape[0]->getGeometry().any());
			physx::PxU32 hitCount = physx::PxGeometryQuery::raycast(origin, pxDirection, geomToTest, originTranslate, physx::PxReal(maxDist),hitFlags, physx::PxU32(maxHit), &hitInfo);
			
			result->hitDistance = hitInfo.distance;
			result->hitLocation = math::Vector3(hitInfo.position.x, hitInfo.position.y, hitInfo.position.z);
			result->hitNormal = math::Vector3(hitInfo.normal.x, hitInfo.normal.y, hitInfo.normal.z);
			result->nodeHit = findNodeByActor(hitInfo.actor);

			return result;
		}

		void PhysXWrapper::Overlaps(component::Collider * collider)
		{
			physx::PxTransform pose = ToPxTransform(collider->GetGameObject()->GetTransform()->getGlobalTranslation(), collider->GetGameObject()->GetTransform()->getGlobalRotation());
			math::Vector3 selfPos = collider->GetGameObject()->GetTransform()->getGlobalTranslation();
			physx::PxRigidActor* actor = dynamic_cast<physx::PxRigidActor*>(collider->GetActor());
			physx::PxShape** buffershape = nullptr;
			actor->getShapes(buffershape, actor->getNbShapes(), 0);
			physx::PxGeometry geom(buffershape[0]->getGeometry().any());


			int i = 0;
			std::unordered_map<std::string, Scene*>* scenes = SCENE_MANAGER->GetActiveScene();
			size_t sceneCount = scenes->size();
			for (i; i < sceneCount; ++i)
			{
				Scene* scene = Tools::IterateMap(*scenes, i);
				SceneNode * node = scene->GetRoot();
				std::vector<SceneNode*> children = node->GetChildren();
				int childrenIdex = 0;
				size_t childrenCount = children.size();
				for (childrenIdex; childrenIdex < childrenCount; ++ childrenIdex)
				{

					math::Vector3 nodePose = children[childrenIdex]->GetTransform()->getGlobalTranslation();
					if (nodePose.distance(selfPos) <= 10)
					{

						physx::PxTransform poseTotest = ToPxTransform(nodePose, children[childrenIdex]->GetTransform()->getGlobalRotation());
						std::vector<component::Component*> colliders = children[childrenIdex]->GetComponents(component::ComponentType::COLLIDER);

						int componentIndex = 0;
						size_t componentCount = colliders.size();
						for (componentIndex; componentIndex < componentCount; ++i)
						{
							component::Collider* colliderToTest = dynamic_cast<component::Collider*>(colliders[componentIndex]);
							physx::PxRigidActor* actor = dynamic_cast<physx::PxRigidActor*>(colliderToTest->GetActor());
							physx::PxShape** buffershape = nullptr;
							actor->getShapes(buffershape, actor->getNbShapes(), 0);
							physx::PxGeometry geomToTest(buffershape[0]->getGeometry().any());
							bool isOverlapping = physx::PxGeometryQuery::overlap(geom, pose, geomToTest, poseTotest);
							if (isOverlapping)
								collider->OverLap();
						}
					}
				}

			}
		}

		auto PhysXWrapper::CreateBox(physx::PxMaterial * material, physx::PxRigidActor * actor) -> physx::PxShape *
		{
			physx::PxShape* box = physx::PxRigidActorExt::createExclusiveShape(*actor, physx::PxBoxGeometry(1, 1, 1), *material);
			return box;
		}

		auto PhysXWrapper::CreateCapsule(physx::PxMaterial * material, physx::PxRigidActor * actor) -> physx::PxShape *
		{
			physx::PxShape* caps = physx::PxRigidActorExt::createExclusiveShape(*actor, physx::PxCapsuleGeometry(1, 1), *material);
			return caps;
		}

		auto PhysXWrapper::CreateMesh(component::Mesh* mesh) -> physx::PxTriangleMeshGeometry*
		{
			physx::PxTriangleMeshDesc meshDesc;
			meshDesc.points.count = mesh->GetData().Count;
			meshDesc.points.stride = sizeof(physx::PxVec3);
			meshDesc.points.data = mesh->GetData().Verts;

			if (!meshDesc.isValid())
			{
				LOGGER->Debuglog("Fail creating triangle mesh", tools::service::LogLevel::ERRORM);
				return nullptr;
			}
			physx::PxDefaultMemoryOutputStream writeBuffer;
			physx::PxTriangleMeshCookingResult::Enum result;
			bool status = m_Cooking->cookTriangleMesh(meshDesc, writeBuffer, &result);
			if (!status)
			{
				LOGGER->Debuglog("Fail creating triangle mesh", tools::service::LogLevel::ERRORM);
				return nullptr;
			}
			physx::PxDefaultMemoryInputData readBuffer(writeBuffer.getData(), writeBuffer.getSize());
			physx::PxTriangleMesh* trianglesMesh = m_Physics->createTriangleMesh(readBuffer);
			physx::PxTriangleMeshGeometry* triangleGeometrie = new physx::PxTriangleMeshGeometry(trianglesMesh, physx::PxVec3(1, 1, 1));
			return triangleGeometrie;
		}

		auto PhysXWrapper::SwitchShape(physx::PxRigidActor * actor, physx::PxMaterial * material, ShapeType type, component::Mesh * mesh) -> void
		{
			switch (type)
			{
			case ShapeType::BOX:
			{
				CreateBox(material, actor);
				break;
			}
			case ShapeType::CAPSULE:
			{
				CreateCapsule(material, actor);
				break;
			}
			case ShapeType::TRIANGLEMESH:
			{
				physx::PxRigidStatic* castedActor = dynamic_cast<physx::PxRigidStatic*>(actor);
				physx::PxShape* triangleMesh;
				triangleMesh = physx::PxRigidActorExt::createExclusiveShape(*castedActor, *CreateMesh(mesh), *material);
				castedActor->attachShape(*triangleMesh);
			}
			}
		}

		auto PhysXWrapper::ToPxTransform(math::Vector3 translation, math::Vector3 rotation) -> physx::PxTransform
		{
			physx::PxVec3 translate(translation.x, translation.y, translation.z);
			math::Vector4 rotate = rotation.vector3ToVector4();
			physx::PxQuat finalRotation(rotate.x, rotate.y, rotate.z, rotate.w);
			physx::PxTransform transform(translate, finalRotation);
			return transform;
		}

		SceneNode * PhysXWrapper::findNodeByActor(physx::PxActor * actor)
		{
			SceneNode* result = nullptr;
			std::unordered_map<std::string, Scene*>* scenes = SCENE_MANAGER->GetActiveScene();
			int i = 0;
			size_t size = scenes->size();
			for (i; i < size; ++i)
			{
				result = nullptr;
				Scene* scene = Tools::IterateMap(*scenes, i);
				result = RecurciveSearch(scene->GetRoot(), actor);
				if (result != nullptr)
					return result;
			}
			return result;
		}

		void PhysXWrapper::EnablePhyscDebug(physx::PxScene* scene)
		{
			scene->setVisualizationParameter(physx::PxVisualizationParameter::eSCALE, 1.0f);
			scene->setVisualizationParameter(physx::PxVisualizationParameter::eACTOR_AXES, 2.0f);
		}
	}
}

