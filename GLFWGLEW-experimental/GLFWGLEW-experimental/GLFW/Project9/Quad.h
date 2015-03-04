#pragma once
#include <glew.h>
#include "wglew.h"
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include "Globals.h"
class Quad
{
public:
	void Move();
	void Draw(float x, float y, float width, float height);
	Vertex* sprite;
	GLuint uiVBOQuad;
	GLuint uiIBOQuad;
	GLuint  uiProgramTextured;
	GLuint  uiTextureId;
	Quad();
	Quad(const char * texturePath);
	~Quad();
};