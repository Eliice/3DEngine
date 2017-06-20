#pragma once

#include <unordered_map>
#include <string>

#include "Service\Service.h"
#include "Plugins\Event.h"

#include "DllExport.h"

class BasicShader;
class RenderCache;

namespace component
{
	class Texture;
	class Mesh;
}

class SceneNode;

namespace tools
{
	namespace service
	{
		class Renderer : public Service
		{
		public:
			Renderer();

			virtual void Shutdown();

			virtual ~Renderer();

			ENGINE_DLL void Initialize() override;
			ENGINE_DLL void RenderLoop();

		private:
			Renderer(Renderer const&) = delete;
			Renderer(Renderer &&) = delete;

			Renderer& operator=(Renderer const&) = delete;
			Renderer& operator=(Renderer &&) = delete;
		};
	}
}