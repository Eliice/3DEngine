#pragma once

#include <unordered_map>
#include "Service.h"
#include "Plugins\Event.h"

namespace component
{
	class Mesh;
}

class MeshObject;

namespace tools
{
	namespace service
	{
		class MeshStorage final: public Service  
		{

			typedef Event<std::unordered_map<std::string, component::Mesh*>>::EventCallback EventCallback;

		public:
			MeshStorage();
			~MeshStorage();

			void Initialize();
			void Shutdown();

			void LoadDefaultMeshes();
			MeshObject* LoadMesh(std::string const& name, std::string const& path);

			void BindNewMeshEvent(EventCallback const& callback);

			inline std::unordered_map<std::string, MeshObject*>& GetAll() { return m_MeshObjects; }

		private:

			Event<std::unordered_map<std::string, component::Mesh*>>* OnNewMesh;

			//std::unordered_map<std::string,component::Mesh*> meshStorage;
			std::unordered_map<std::string, MeshObject*> m_MeshObjects;
		};
	}
}


