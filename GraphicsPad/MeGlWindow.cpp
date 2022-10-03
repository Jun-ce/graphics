#include <gl\glew.h>
#include <iostream>
#include <fstream>
#include <MeGlWindow.h>
#include <glm/glm.hpp>
#include <Transform2D.h>
using namespace std;

#pragma region ExternalConsts

extern const int refWidth;
extern const int refHeight;

extern float GetGLCoordinate(int value, int max);

extern float getERSymbolX(int x);

extern float getERSymbolY(int y);

#pragma endregion



// GL mid
#pragma region GlMid

GLuint programID;
GLint offsetAttribLoc;
GLint scaleAttribLoc;
GLint uniColorAttribLoc;

#pragma endregion

// My Data
#pragma region MyData

Transform2D triAtrans;
Transform2D triBtrans;

#pragma endregion

bool checkStatus(
	GLuint objectID,
	PFNGLGETSHADERIVPROC objectPropertyGetterFunc,
	PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
	GLenum statusType)
{
	GLint status;
	objectPropertyGetterFunc(objectID, statusType, &status);
	if (status != GL_TRUE)
	{
		GLint infoLogLength;
		objectPropertyGetterFunc(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* buffer = new GLchar[infoLogLength];

		GLsizei bufferSize;
		getInfoLogFunc(objectID, infoLogLength, &bufferSize, buffer);
		cout << buffer << endl;
		delete[] buffer;
		return false;
	}
	return true;
}

bool checkShaderStatus(GLuint shaderID)
{
	return checkStatus(shaderID, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS);
}

bool checkProgramStatus(GLuint programID)
{
	return checkStatus(programID, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS);
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
		getERSymbolX(269),
		getERSymbolY(326),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 5 
		getERSymbolX(313),
		getERSymbolY(326),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
		
		// 6
		getERSymbolX(295),
		getERSymbolY(4),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 7
		getERSymbolX(289),
		getERSymbolY(639),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// R 
		// 8
		getERSymbolX(301),
		getERSymbolY(320),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 9
		getERSymbolX(300),
		getERSymbolY(383),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 10
		getERSymbolX(450),
		getERSymbolY(461),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,		
		
		// 11
		getERSymbolX(432),
		getERSymbolY(470),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,	

		// 12
		getERSymbolX(410),
		getERSymbolY(427),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 13
		getERSymbolX(331),
		getERSymbolY(511),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
		
		// 14
		getERSymbolX(352),
		getERSymbolY(535),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
		
		// 15
		getERSymbolX(347),
		getERSymbolY(495),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,			
		
		// 16
		getERSymbolX(471),
		getERSymbolY(674),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// E
		// 17
		getERSymbolX(286),
		getERSymbolY(309),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 18
		getERSymbolX(150),
		getERSymbolY(251),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 19
		getERSymbolX(284),
		getERSymbolY(364),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
		
		// 20
		getERSymbolX(171),
		getERSymbolY(237),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 21
		getERSymbolX(290),
		getERSymbolY(185),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
		
		// 22
		getERSymbolX(290),
		getERSymbolY(165),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 23
		getERSymbolX(175),
		getERSymbolY(272),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 24
		getERSymbolX(256),
		getERSymbolY(195),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
		
		// 25
		getERSymbolX(147),
		getERSymbolY(97),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 26
		getERSymbolX(159),
		getERSymbolY(92),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 27
		getERSymbolX(295),
		getERSymbolY(96),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 28
		getERSymbolX(294),
		getERSymbolY(51),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 29
		getERSymbolX(174),
		getERSymbolY(115),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
};

	// ===Def data buffer===
	GLuint myBufferID;
	glGenBuffers(1, &myBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, myBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts),
		verts, GL_STATIC_DRAW);
	// ===


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 2));

	// ===Def idx buffer===
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
	// ===
}

string readShaderCode(const char* fileName)
{
	ifstream meInput(fileName);
	if ( ! meInput.good())
	{
		cout << "File failed to load..." << fileName;
		exit(1);
	}
	return std::string(
		std::istreambuf_iterator<char>(meInput),
		std::istreambuf_iterator<char>());
}

void installShaders()
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const GLchar* adapter[1];
	string temp = readShaderCode("VertexShaderCode.glsl");
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	temp = readShaderCode("FragmentShaderCode.glsl");
	adapter[0] = temp.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

	if( ! checkShaderStatus(vertexShaderID) || ! checkShaderStatus(fragmentShaderID))
		return;

	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);

	if ( ! checkProgramStatus(programID))
		return;

	// === Get Uniform location ===
	offsetAttribLoc = glGetUniformLocation(programID, "vertexOffset");
	scaleAttribLoc = glGetUniformLocation(programID, "vertexScale");
	uniColorAttribLoc = glGetUniformLocation(programID, "vertexUniColor");
	// ===

	glUseProgram(programID);
}

void applyUniform() {

	// === Set Uniform ===
	glUniform2f(offsetAttribLoc, 0.0f, 0.0f);
	glUniform1f(scaleAttribLoc, 0.5f);
	glUniform3f(uniColorAttribLoc, 1.0f, 0.0f, 0.0f);
	// ===
}


void MeGlWindow::initializeGL()
{
	glewInit();
	sendDataToOpenGL();
	installShaders();
	applyUniform();
}

void MeGlWindow::paintGL()
{
	glViewport(0, 0, width(), height());
	//glViewport(0, 0, refWidth, refHeight);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, 51, GL_UNSIGNED_SHORT, 0);
}

void MeGlWindow::keyPressEvent(QKeyEvent* e) {

}