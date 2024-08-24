#version 300 es
layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>

out vec4 colorOut;

uniform mat4 model;
uniform mat4 projection;
uniform vec4 color;


void main()
{
    gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);
    colorOut = color;
}
