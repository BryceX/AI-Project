#include <glew.h>
#include "wglew.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <SOIL.h>
#include <iostream>
#include <time.h>
#include "Globals.h"
#include "Player.h"
#include "Asteroids.h"
#include "Stars.h"
#include "Text.h"
#include "Animator.h"
#include <fstream>
#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Graph.h"
#include "Quad.h"
#endif // !_GRAPH_H_


int astConstant = 40;
float deltaTime = 0;
float timeSinceLastFrame = 0;
float currentTime = glfwGetTime();
float lastFrame = currentTime;
float x = 0;
float y = 0;





void GetDeltaTime()
{
	deltaTime + glfwGetTime();
	glfwSetTime(0);
}

int main()
{
	Globals& myGlobals = Globals::instance();
	srand(time(NULL));
	// init GLFW
	if (!glfwInit())
	{
		return -1;
	}
	myGlobals.window = glfwCreateWindow(600, 600, "Hello World", NULL, NULL);
	myGlobals.orthographicProjection = myGlobals.getOrtho(0, 600, 600, 0, 0, 100);
	if (!myGlobals.window)
	{
		glfwTerminate();
		return -1;
	}

	//make the window's context current
	glfwMakeContextCurrent(myGlobals.window);

	//ÅEÅEnsert this into the main.cpp example given in the setting up GLFW section ÅE
	//once the glfw window has been created and after 'glfwMakeContextCurrent(window);'
	// start GLEW
	if (glewInit() != GLEW_OK)
	{
		// OpenGL didn't start-up! shutdown GLFW and return an error code
		glfwTerminate();
		return -1;
	}
	//Initialise GLFW
	Player myShip("sample.jpg");
	Stars myStars[50];
	
	
	Asteroids myAsteroids[10];
	Animator test("mario.png"); 
	Quad square("square.png");
	
	Graph myGraph;
	int squares = 12;
	Quad testQuad("square.png");

	

	Text myText;
	myGraph.SetGraphData(25, 25, squares, squares, 600 / squares);
	myGraph.CreateGraph();
	HWND tempWin;
	glScalef(1.f, -1.f, 1.f);
	//myGraph.SearchDFS(myGraph.m_aNodes[1], myGraph.m_aNodes[1]);
	while (!glfwWindowShouldClose(myGlobals.window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		GetDeltaTime();

		
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastFrame;
		lastFrame = currentTime;
		//square.Draw(300,300, 50,50);
		myGraph.DrawGraph();
		//testQuad.Draw(300, 300, 50, 50);

		// TODO: use fucking glfw - love terh glfwGetKey() == GLFW_PRESS
		if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
		{
			std::cout << "you clicked" << std::endl;
			POINT p;
			double xPos;
			double yPos;

			glfwGetCursorPos(myGlobals.window, &xPos, &yPos);
			
			GraphNode * clickedNode = myGraph.FindLeastDist(xPos, yPos);

			if (clickedNode != nullptr)
			{

				std::cout << "i derped on " << clickedNode->id << "\n";

			}

			if (GetCursorPos(&p))
			{
				
				std::cout << xPos << "   " << yPos << std::endl;

			}

			
		}

		if ((GetKeyState(VK_RBUTTON) & 0x100) != 0)
		{
			std::cout << "ZZZZZZZZ" << std::endl;
		}

		
		

		//test.Draw(300, 300, 200, 200, 12, deltaTime);
		//myShip.Move();
		//myShip.Draw();
		

		//myText.Draw(20.f,20.f, std::string("The Quick Brown Fox Jumps Over A Lazy Dog"));
		

		//	animatedSprite.Draw();
		//animatedSprite.Move();

		/*for (int i = 0; i < 10; i++)
		{
		
		square.Draw(100+(20*i), 50, 20, 20);

		}*/
		



		//for (int i = 0; i < 10; i++)
		{
		//	myAsteroids[i].Draw();
		}

		//for (int i = 0; i < 50; i++)
		{
		//	myStars[i].Draw();
		}


		glfwSwapBuffers(myGlobals.window);

		if (glfwGetKey(myGlobals.window, GLFW_KEY_ESCAPE))
		{
			break;
		}


		//poll for and process events
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}