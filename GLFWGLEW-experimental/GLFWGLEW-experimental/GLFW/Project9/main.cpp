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
	myGlobals.orthographicProjection = myGlobals.getOrtho(0, 600, 0, 600, 0, 100);
	if (!myGlobals.window)
	{
		glfwTerminate();
		return -1;
	}

	//make the window's context current
	glfwMakeContextCurrent(myGlobals.window);

	//�E�Ensert this into the main.cpp example given in the setting up GLFW section �E
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

	

	

	Text myText;
	myGraph.SetGraphData(180, 180, 15, 15);
	myGraph.CreateGraph();
	
	myGraph.SearchDFS(myGraph.m_aNodes[1], myGraph.m_aNodes[1]);
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
		
		//test.Draw(300, 300, 200, 200, 12, deltaTime);
		//myShip.Move();
		//myShip.Draw();
		

		//myText.Draw(0.f, 0.f, std::string("Ayy lmao"));


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