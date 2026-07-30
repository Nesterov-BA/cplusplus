#version 330 core
out vec4 FragColor;

in vec3 ourColor;

uniform float brightness;

void main()
{
    FragColor = vec4(0.0f,1.0f*brightness,0.0f, 0.5f);
}
