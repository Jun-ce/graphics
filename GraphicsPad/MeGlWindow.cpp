#include <gl\glew.h>
#include <iostream>
#include <fstream>
#include <MeGlWindow.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <Primitives\Vertex.h>
#include <Primitives\ShapeGenerator.h>
using namespace std;
using glm::vec3;
using glm::mat4;

const uint NUM_VERTICES_PER_TRI = 3;
const uint NUM_FLOATS_PER_VERTICE = 6;
const uint VERTEX_BYTE_SIZE = NUM_FLOATS_PER_VERTICE * sizeof(float);
GLuint programID;
GLuint numIndices;
GLuint drawIdxOffset;

float myRotation = 54.0f;

void sendDataToOpenGL()
{
	ShapeData shape = ShapeGenerator::makeCube();

	GLuint bufferID;
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, shape.vertexBufferSize()+shape.indexBufferSize(), NULL , GL_STATIC_DRAW);

	// verts
	glBufferSubData(GL_ARRAY_BUFFER, 0, shape.vertexBufferSize(), shape.vertices);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));

	// idx
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, shape.vertexBufferSize(), shape.indexBufferSize(), shape.indices);
	numIndices = shape.numIndices;
	drawIdxOffset = shape.vertexBufferSize();
	shape.cleanup();
}

void MeGlWindow::paintGL()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, width(), height());

	GLint fullTransformMatrixUniformLocation =
		glGetUniformLocation(programID, "fullTransformMatrix");


	mat4 translationMatrix;
	mat4 rotationMatrix;
	mat4 projectionMatrix;

	myRotation += 0.5f;

	mat4 fullTransformMatrix;;

	// Draw 1
	translationMatrix = glm::translate(mat4(), vec3(0.0f, 0.0f, -8.0f));
	rotationMatrix = glm::rotate(mat4(), myRotation, vec3(1.0f, 0.0f, 0.0f));
	projectionMatrix = glm::perspective(60.0f, ((float)width()) / height(), 0.1f, 10.0f);

	fullTransformMatrix = projectionMatrix * translationMatrix * rotationMatrix;

	glUniformMatrix4fv(fullTransformMatrixUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, (void*)drawIdxOffset);

	// Draw 2
	translationMatrix = glm::translate(mat4(), vec3(-4.0f, 1.0f, -8.0f));
	rotationMatrix = glm::rotate(mat4(), myRotation, vec3(0.0f, 1.0f, 0.0f));
	projectionMatrix = glm::perspective(60.0f, ((float)width()) / height(), 0.1f, 10.0f);

	fullTransformMatrix = projectionMatrix * translationMatrix * rotationMatrix;

	glUniformMatrix4fv(fullTransformMatrixUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, (void*)drawIdxOffset);

	// Draw 3
	translationMatrix = glm::translate(mat4(), vec3(4.0f, -1.0f, -8.0f));
	rotationMatrix = glm::rotate(mat4(), myRotation, vec3(0.0f, 0.0f, 1.0f));
	projectionMatrix = glm::perspective(60.0f, ((float)width()) / height(), 0.1f, 10.0f);

	fullTransformMatrix = projectionMatrix * translationMatrix * rotationMatrix;

	glUniformMatrix4fv(fullTransformMatrixUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, (void*)drawIdxOffset);
}

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

	glUseProgram(programID);
}


void MeGlWindow::initializeGL()
{
	glewInit();
	glEnable(GL_DEPTH_TEST);
	sendDataToOpenGL();
	installShaders();

	// Update PaintGL for every delta ms
	connect(&myQTimer, SIGNAL(timeout()), this, SLOT(update()));
	myQTimer.start(16.7f);
}