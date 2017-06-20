#include "Component\renderer.h"

#include "Service\servicelocator.h"
#include "Libraries\RenderLibrary.h"
#include "Scene\camera.h"

namespace tools
{
	namespace service
	{
		Renderer::Renderer()
		{
			SetName("Renderer");
		}

		Renderer::~Renderer()
		{
		}

		void Renderer::Initialize()
		{

		}

		void Renderer::RenderLoop()
		{
			Camera* cam = SCENE_MANAGER->GetCamera();
			cam->Render();

			RenderLibrary* renderLib = LIBRARY_MANAGER->GetRenderLibrary();

			if (renderLib)
				renderLib->Render();

			SCENE_MANAGER->ClearDeleteQueue();
		}

		void Renderer::Shutdown()
		{
		}
	}
}