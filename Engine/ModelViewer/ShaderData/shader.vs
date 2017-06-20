
#version 450

in vec4 a_Position;
in vec3 a_Normal;
in vec2 a_TexCoords;

out vec2 v_TexCoords;
out vec4 v_Color;

uniform mat4 u_View;
uniform float u_Time;

layout (std140) uniform shaderData
{
	mat4 u_WorldMatrix[128];
};

const vec3 LightDir = - vec3(-1.0, -1.0, -1.0);

mat4 testMat = mat4(
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	);

void main(void)
{
	v_TexCoords = a_TexCoords;

	v_Color = vec4(a_Normal * 0.5 + 0.5, 1.0);

	float width = 1280.0; float height = 720.0;
	float aspectRatio = width/height;
	float fov = radians(45.0); 
	float near = 0.1;
	float far = 1000.0;

	float d =  1.0 / tan(fov/2.0);
	float range = 1.0/ (near - far);
	
	mat4 projectionMatrix = mat4(	d / aspectRatio, 0.0, 0.0, 0.0,
									0.0, d, 0.0, 0.0,
									0.0, 0.0, (near+far)*range, -1.0,
									0.0, 0.0, (near*far*2.0)*range, 1.0	);


	mat4 viewMatrix = u_WorldMatrix[gl_InstanceID] * u_View;
	
	vec3 SkyColor = vec3(0.0,0.0,1.0);
	vec3 GroundColor = vec3(0.0,1.0,0.0);

	vec3 Normal = normalize(vec3( mat3(u_WorldMatrix[gl_InstanceID]) * a_Normal));
	v_Color = vec4(mix(SkyColor, GroundColor, 0.5) * dot(Normal, LightDir), 1.0);

	gl_Position = projectionMatrix * viewMatrix * u_WorldMatrix[gl_InstanceID] * a_Position;
}