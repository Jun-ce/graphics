#include <gl\glew.h>
#include <MeGlWindow.h>

extern const char* vertexShaderCode;
extern const char* fragmentShaderCode;

const int refWidth = 605;
const int refHeight = 689;

float GetGLCoordinate(int value, int max) {
	float r;
	r = (float)value / (float)max *2.0f -1.0f;
	return r;
}

float getX(int x) {
	return GetGLCoordinate(x, refWidth);
}

float getY(int y) {
	return GetGLCoordinate(refHeight - y, refHeight);
}


void sendDataToOpenGL()
{
	GLfloat verts[] =
	{
		// Data
		// float x, float, y,
		// float r, float g, floar b

		// BG color
		// 1.0f, 198.0f/255.0f, 14.0f/255.0f,

		// Symbol color
		// 127.0f/255.0f, 211.0f / 255.0f, 42.0f / 255.0f

		// BG
		// 0 TR 
		+1.0f, +1.0f,
		1.0f, 198.0f / 255.0f, 14.0f / 255.0f,
		// 1 TL
		-1.0f, +1.0f,
		1.0f, 198.0f / 255.0f, 14.0f / 255.0f,
		// 2 BL
		-1.0f, -1.0f,
		1.0f, 198.0f / 255.0f, 14.0f / 255.0f,
		// 3 BR
		+1.0f, -1.0f,
		1.0f, 198.0f / 255.0f, 14.0f / 255.0f,

		// Symbol
		// 4
		getX(269),
		getY(326),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 5 
		getX(313),
		getY(326),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
		
		// 6
		getX(295),
		getY(4),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 7
		getX(289),
		getY(639),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// R 
		// 8
		getX(301),
		getY(320),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 9
		getX(300),
		getY(383),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 10
		getX(450),
		getY(461),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,		
		
		// 11
		getX(432),
		getY(470),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,	

		// 12
		getX(410),
		getY(427),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 13
		getX(331),
		getY(511),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
		
		// 14
		getX(352),
		getY(535),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
		
		// 15
		getX(347),
		getY(495),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,			
		
		// 16
		getX(471),
		getY(674),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// E
		// 17
		getX(286),
		getY(309),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 18
		getX(150),
		getY(251),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 19
		getX(284),
		getY(364),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
		
		// 20
		getX(171),
		getY(237),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 21
		getX(290),
		getY(185),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
		
		// 22
		getX(290),
		getY(165),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 23
		getX(175),
		getY(272),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 24
		getX(256),
		getY(195),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
		
		// 25
		getX(147),
		getY(97),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 26
		getX(159),
		getY(92),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 27
		getX(295),
		getY(96),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 28
		getX(294),
		getY(51),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 29
		getX(174),
		getY(115),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
};

	GLuint myBufferID;
	glGenBuffers(1, &myBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, myBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts),
		verts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 2));

	GLushort indices[] = { 
		// BG
		0,1,2, 
		0,2,3,
		// Symbol
		4,5,6,
		4,5,7,
		// R
		8,9,10,
		8, 9, 11,
		10,12,13,
		13,10,14,
		13, 16, 15,
		// E
		17, 18, 19,
		17, 18, 20,
		18,21,22,
		18,21,23,
		21,24,25,
		21, 25, 26,
		25,27,28,
		25,27,29,

	};
	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
		indices, GL_STATIC_DRAW);
}

void installShaders()
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* adapter[1];
	adapter[0] = vertexShaderCode;
	glShaderSource(vertexShaderID, 1, adapter, 0);
	adapter[0] = fragmentShaderCode;
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);

	glUseProgram(programID);
}

void MeGlWindow::initializeGL()
{
	glewInit();
	sendDataToOpenGL();
	installShaders();
}

void MeGlWindow::paintGL()
{
	//glViewport(0, 0, width(), height());
	glViewport(0, 0, refWidth, refHeight);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, 51, GL_UNSIGNED_SHORT, 0);
}