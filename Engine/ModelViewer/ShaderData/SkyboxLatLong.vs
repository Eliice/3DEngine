
#version 450

const vec2 QuadStrip[4] = vec2[]
(
  vec2(-1.0,  1.0),
  vec2(-1.0, -1.0),
  vec2( 1.0,  1.0),
  vec2( 1.0, -1.0)
);

out vec2 v_TexCoordsDebug;
out vec3 v_TexCoords;

uniform float u_Time;
uniform mat4 u_View;

void main(void)
{
	vec4 position = vec4( QuadStrip[ gl_VertexID ], 1.0, 1.0);

	float width = 1280.0; float height = 720.0;
	float aspectRatio = width / height;		
	float fovY = radians(45.0);				
	float near = 0.1;						
	float far = 1000.0;						

	float d = 1.0 / tan(fovY/2.0);			
	float range = 1.0 / (near - far);		
	mat4 projectionMatrix = mat4(
						d / aspectRatio, 0.0, 0.0, 0.0,
						0.0, d, 0.0, 0.0,
						0.0, 0.0, (near+far)*range, -1.0,
						0.0, 0.0, (near*far*2.0)*range, 0.0
					);

	// ROTATION 3D (pivot Y)
	mat4 ViewMatrix = mat4(
					cos(u_Time), 0.0, -sin(u_Time), 0.0, 	// 1ere colonne					
					0.0, 1.0, 0.0, 0.0,						// 2eme colonne
					sin(u_Time), 0.0, cos(u_Time), 0.0,		// 3eme colonne
					0.0, 0.0, 0.0, 1.0						// 4eme colonne
				);

	
	v_TexCoordsDebug = position.xy * 0.5 + 0.5;
	
	v_TexCoords = vec3(inverse(mat4(mat3(u_View))) * inverse(projectionMatrix) * position);
	//v_TexCoords = vec3(u_View * inverse(projectionMatrix));

	gl_Position = position;
}
