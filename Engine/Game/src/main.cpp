// Game.cpp : Defines the entry point for the console application.
//

#include "system.h"

int main(int argc, char* argv[])
{
	System sys(argc, argv);
	sys.Initialize();

	sys.Run();

	sys.Shutdown();

    return EXIT_SUCCESS;
}

