#version 430

in layout(location=0) vec2 position;
in layout(location=1) vec3 vertexColor;
uniform vec3 vertexUniColor;
uniform vec2 vertexOffset;
uniform float vertexScale;

out vec3 theColor;

void main()
{
	//gl_Position = vec4(position, 0.0, 1.0);
	gl_Position = vec4(position*vertexScale + vertexOffset, 0.0, 1.0);
	
	
	theColor = vertexColor;
	//theColor = vec3(position*vertexScale + vertexOffset, 0.0);
	//theColor = vertexUniColor;
}