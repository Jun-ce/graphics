#include <gl\glew.h>
#include <MeGlWindow.h>

void MeGlWindow::initializeGL()
{
	glewInit();

	GLfloat verts[] =  // Normalized coordinates in window space, origion is (0,0), bottom left is (-1,-1), top right is (1,1)
	{
		-0.5f, +0.0f,
		-1.0f, -1.0f,
		+0.0f, -1.0f,

		+0.5f, +0.0f,
		+0.0f, -1.0f,
		1.0f, -1.0f,

		-0.5f, +0.0f,
		-1.0f, 1.0f,
		+0.0f, 1.0f,

		+0.5f, +0.0f,
		+0.0f, 1.0f,
		1.0f, 1.0f,
	};
	GLuint myBufferID;
	glGenBuffers(1, &myBufferID);  // Ask for a buffer, give it an ID
	glBindBuffer(GL_ARRAY_BUFFER, myBufferID);  // Bind it to a array buffer point
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts),  // Set the data format of the buffer and send actual data
		verts, 
		GL_STATIC_DRAW);  // Data params
	glEnableVertexAttribArray(0);  // ?
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);  // ?
}

void MeGlWindow::paintGL()
{
	glViewport(0, 0, width(), height());  // Windows coordinate
	glDrawArrays(GL_TRIANGLES, 0, 12);  // Draw triangles, starting with 0 idx, using 12 vectors
}