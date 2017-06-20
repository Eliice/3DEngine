#pragma once

#include <memory>
#include <cstdint>
#include <string>

#include "GL/glew.h"
#include "GL/freeglut.h"

typedef void(*KeyFunc)(unsigned char, int, int);
typedef void(*ReshapeFunc)(int, int);
typedef void(*UpdateFunc)();

class GlutHelper
{
public:
	GlutHelper();
	~GlutHelper();

	static GlutHelper* Get();

	void Initialize(unsigned int mode, int& argc, char* argv[]);
	void InitWindow(std::string const title, int x, int y, int width, int height);

	float GetDeltaTime();

	void SetKeyboardFunc(KeyFunc keyDown, KeyFunc keyUp);
	void SetReshapeFunc(ReshapeFunc func) const;
	void SetIdleFunc(UpdateFunc func) const;
	void SetDisplayFunc(UpdateFunc func) const;
	
	void PostRedisplay() const;

	void Update();
	void SwapBuffers() const;

private:
	static std::unique_ptr<GlutHelper> m_Instance;
};

