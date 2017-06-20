#pragma once


#ifdef DLL_EXPORT
#define ENGINE_DLL __declspec(dllexport)
#else
#define ENGINE_DLL __declspec(dllimport)
#endif
