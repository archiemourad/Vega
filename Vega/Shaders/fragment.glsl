#version 330 core

in vec2 texCoord;

uniform sampler2D sampler;

out vec4 FragColor;

void main()
{
    FragColor = texture(sampler, texCoord);
}

