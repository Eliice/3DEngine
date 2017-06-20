#pragma once

#include "SceneNode.h"
#include "Vector3.h"
#include "Mat4.h"
#include "Key.h"

class Camera : public SceneNode
{
public:
	Camera(SceneNode* parent = nullptr);
	virtual ~Camera();

	virtual void Initialize();

	virtual void Render();

	void OnMove(Key key);
	void StopMove(Key key);

	void SetSpeed(float value);

	math::Mat4 GetView() const { return m_View; }

	virtual std::string Serialize(); 
	virtual void Deserialize(std::string& data);

private:
	math::Mat4 m_View;

	math::Vector3 m_Position;
	math::Vector3 m_Rotation;     ///TODO: switch to Transform, dont forget to add it to serialize func
	math::Vector3 m_Scale;
	
	float m_Speed = 1.0;

	math::Vector3 m_Offset;

	int m_keyDownEvt = 0;
	int m_keyUpEvt = 0;
};