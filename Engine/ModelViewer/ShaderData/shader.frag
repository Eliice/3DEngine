#version 450

in vec2 v_TexCoords;
in vec4 v_Color;

uniform sampler2D u_Texture;

out vec4 o_Color;

void main(void)
{
	vec2 texCoords = vec2(v_TexCoords.x, 1.0 - v_TexCoords.y);
	vec4 texColor = texture2D(u_Texture, texCoords);

	o_Color = v_Color * texColor;
	//o_Color = vec4(1.0,1.0,1.0,1.0);
}