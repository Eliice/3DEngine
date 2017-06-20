#include <iostream>
#include <functional>

#include "Scene\camera.h"
#include "Component\renderer.h"
#include "Service\InputManager.h"
#include "Service\servicelocator.h"
#include "Helpers\FunctionBindHelper.h"
#include "Vector3.h"

#include "Mat4.h"


Camera::Camera(SceneNode* parent)
	: SceneNode("Camera", parent)
{
	m_Position = math::Vector3(0.f, 0.f, 70.f);
}

Camera::~Camera()
{
	Event<Key>* keyDownEvt = InputManager::Get()->GetKeyDownEvent();
	Event<Key>* keyUpEvt = InputManager::Get()->GetKeyUpEvent();

	keyDownEvt->Unbind(m_keyDownEvt);
	keyUpEvt->Unbind(m_keyUpEvt);
}

void Camera::Initialize()
{
	Event<Key>* keyDownEvt = InputManager::Get()->GetKeyDownEvent();
	Event<Key>* keyUpEvt = InputManager::Get()->GetKeyUpEvent();

	m_keyDownEvt = keyDownEvt->Bind(FunctionBindHelper::Bind(this, &Camera::OnMove));
	m_keyUpEvt = keyUpEvt->Bind(FunctionBindHelper::Bind(this, &Camera::StopMove));

	SceneNode::Initialize();
}

void Camera::Render()
{
	m_Rotation += m_Offset * m_Speed * TIMERS->GetTimer("FrameTimer");

	math::Mat4 matrix;
	m_View = math::Mat4::Identity;
	m_View *= matrix.MatrixTranslation(m_Position).Inverse() * matrix.MatrixRotateX(m_Rotation.x) * matrix.MatrixRotateY(m_Rotation.y) * matrix.MatrixRotateZ(m_Rotation.z);
}

void Camera::OnMove(Key key)
{
	switch (key)
	{
	case KEY_A:
		m_Offset.y = -1;
		break;

	case KEY_D:
		m_Offset.y = 1;
		break;

	case KEY_W:
		m_Offset.x = 1;
		break;

	case KEY_S:
		m_Offset.x = -1;
		break;

	default:
		break;
	}
}

void Camera::StopMove(Key key)
{
	if (key == KEY_A || key == KEY_D)
		m_Offset.y = 0;

	if (key == KEY_W || key == KEY_S)
		m_Offset.x = 0;
}

void Camera::SetSpeed(float value)
{
	m_Speed = value;
}

std::string Camera::Serialize()
{
	std::string data;
	data = " \t Camera: \n \t { \n \t\t Speed: " + std::to_string(m_Speed) + ",\n \t },";
	return data;
}

void Camera::Deserialize(std::string& data)
{
	std::string str;

	data.erase(0, data.find_first_of(":") + 2);
	data.erase(0, data.find_first_of(":") + 2);
	str = data.substr(0, data.find_first_of(","));

	m_Speed = std::stof(str);

}
