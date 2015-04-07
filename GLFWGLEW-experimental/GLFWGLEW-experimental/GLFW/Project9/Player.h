#pragma once
#include <glew.h>
#include "wglew.h"
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include "Globals.h"
class Player
{
public:
	void Move();
	void Draw(float x, float y, float width, float height);
	float x;
	float y;
	Vertex* playerShip;
	GLuint uiVBOplayerShip;
	GLuint uiIBOplayerShip;
	GLuint  uiProgramTextured;
	GLuint  uiTextureId;


	

	Player();
	Player(const char * texturePath);
	~Player();
};