#version 300 es

precision mediump float;

in vec2 TexCoords;
out vec4 color;

uniform sampler2D text;
uniform vec3 textColor;

void main()
{
    vec4 sampled = vec4(1,1,1, texture(text, TexCoords).a);
    color = vec4(textColor,1) * sampled;
}