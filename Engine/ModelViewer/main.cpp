#if _WIN32
#define FREEGLUT_LIB_PRAGMAS 1
#pragma comment (lib, "freeglut.lib")
#pragma comment (lib, "glew32.lib")
#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "SDL2.lib")
#pragma comment (lib, "SDL2main.lib")
#pragma comment (lib,"Math.lib")
#endif

#include "system.h"

int main(int argc, char* argv[])
{
 	System* sys = new System(argc, argv);
	sys->Initialize();

	sys->Run();
	delete(sys);

	sys->Shutdown();
	
	return EXIT_SUCCESS;

}