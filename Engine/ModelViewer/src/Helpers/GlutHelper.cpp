#include "Helpers\GlutHelper.h"
#include <iostream>

std::unique_ptr<GlutHelper> GlutHelper::m_Instance = nullptr;

GlutHelper::GlutHelper()
{
}


GlutHelper::~GlutHelper()
{
}

GlutHelper* GlutHelper::Get()
{
	if (m_Instance == nullptr)
		m_Instance = std::make_unique<GlutHelper>();

	return m_Instance.get();
}

void GlutHelper::Initialize(unsigned int mode, int& argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(mode);

#if FREEGLUT
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
#endif
}

void GlutHelper::InitWindow(std::string const title, int x, int y, int width, int height)
{
	glutInitWindowPosition(x, y);
	glutInitWindowSize(width, height);

	glutInitContextVersion(4, 5);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutCreateWindow(title.c_str());
}

float GlutHelper::GetDeltaTime()
{
	return glutGet(GLUT_ELAPSED_TIME) / 1000.f;
}

void GlutHelper::SetKeyboardFunc(KeyFunc keyDown, KeyFunc keyUp)
{
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
}

void GlutHelper::SetReshapeFunc(ReshapeFunc func) const
{
	glutReshapeFunc(func);
}

void GlutHelper::SetIdleFunc(UpdateFunc func) const
{
	glutIdleFunc(func);
}

void GlutHelper::SetDisplayFunc(UpdateFunc func) const
{
	glutDisplayFunc(func);
}

void GlutHelper::PostRedisplay() const
{
	glutPostRedisplay();
}

void GlutHelper::Update()
{
	glutMainLoop();
}

void GlutHelper::SwapBuffers() const
{
	glutSwapBuffers();
}