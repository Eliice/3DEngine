
#version 450

// INPUTS du Fragment Shader = OUTPUTS du Vertex Shader

in vec2 v_TexCoordsDebug;
in vec3 v_TexCoords;

uniform sampler2D u_SkyTexture;

out vec4 o_Color;

#define PI 3.14159265

vec4 radialSample(sampler2D tex, vec3 texCoords)
{
    float r = length(texCoords);
    float longitude = atan(texCoords.z, texCoords.x);
    float latitude = acos(texCoords.y / r);

    const vec2 radianFactors = vec2(1.0 / (2.0*PI), 1.0 / PI);
    vec2 sphereCoords = vec2(longitude, latitude) * radianFactors;
    return texture(tex, sphereCoords);
}

void main(void)
{
    o_Color = radialSample(u_SkyTexture, v_TexCoords);
}
