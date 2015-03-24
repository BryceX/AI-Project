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
#include <glm/glm.hpp>

#define GLFW_RELEASE 0
#endif // !_GRAPH_H_


int astConstant = 40;
float deltaTime = 0;
float currentTime = glfwGetTime();
float lastFrame = currentTime;
float x = 0;
float y = 0;
float windowSize = 600;
int squares = 10;
float squareSize = 30;
int graphCounter = squares;



void GetDeltaTime()
{
	deltaTime = glfwGetTime();
	glfwSetTime(0);
	
}

struct Binding
{
	float upper = windowSize / (squares * 2);
	float lower = 0;
	float left = 0;
	float right = windowSize / (squares * 2);
};
int main()
{
	Globals& myGlobals = Globals::instance();
	srand(time(NULL));
	// init GLFW
	if (!glfwInit())
	{
		return -1;
	}
	myGlobals.window = glfwCreateWindow(windowSize, windowSize, "Hello World", NULL, NULL);
	myGlobals.orthographicProjection = myGlobals.getOrtho(0, windowSize, windowSize, 0, 0, 100);
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
	//Player myShip("sample.jpg");
	Stars myStars[50];
	
	
	//Asteroids myAsteroids[10];
	//Animator test("mario.png"); 
	//Quad square("square.png",1,1,1);
	
	Graph myGraph;

	myGraph.SetGraphData(0, 0, squares, squares, windowSize / squares);
	myGraph.CreateGraph(windowSize);
	
	
	Quad player("square.png", 1,1,0);
	float playerXPos = squareSize / 2;
	float playerYPos = squareSize / 2;


	Quad target("square.png", 1, 0, 1);
	float targetX = 0;
	float targetY = 0;


	/*float xPos = ;
	float yPos = windowSize/squares*2;*/
	
	
	Binding myBox;
	

	std::vector<Binding> myBoxes;
	

	
	
	HWND tempWin;
	Text myText;
	glScalef(1.f, -1.f, 1.f);

	playerXPos = myGraph.m_aNodes[0]->x;
	playerYPos = myGraph.m_aNodes[0]->y;
	//myGraph.SearchDFS(myGraph.m_aNodes[1], myGraph.m_aNodes[1]);
	while (!glfwWindowShouldClose(myGlobals.window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		GetDeltaTime();

		
		//currentTime = glfwGetTime();
		//deltaTime = currentTime - lastFrame;
		//lastFrame = currentTime;
		
		
		myGraph.DrawGraph();
		player.Draw(playerXPos, playerYPos, squareSize, squareSize);
		target.Draw(targetX, targetY, squareSize, squareSize);
		//myGraph.GraphMoveTest(20, deltaTime);
		
		
		std::cout << playerXPos << std::endl;

		//dijkstra
		//todo pushback all neighbors of each node into a container
		//figure out how to make container accessable by everything
		//make a new container for every node
		//make blocks change color for path by changing rgb values
		//have the lowest weight edge ending node become the new node
		//check all neighbors of new node and repeat until at goal node and repeat previous step
	
	


		



		








		POINT p;
		double xPos;
		double yPos;

		glfwGetCursorPos(myGlobals.window, &xPos, &yPos);


		GraphNode * clickedNode = myGraph.FindLeastDist(xPos, yPos);



	

		// TODO: use fucking glfw - love terh glfwGetKey() == GLFW_PRESS
	if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
		{
			
			
				graphCounter += 1;

				if (0 < xPos && xPos < windowSize && 0 < yPos && yPos < windowSize)
				{

					if (clickedNode != nullptr)
					{
						int nodeX = windowSize / squares;
						
					
						


						

					}

					if (GetCursorPos(&p))
					{

						std::cout << "at " << xPos << "X   " << yPos << "Y" << std::endl;

					}
				}
				
			
			std::cout << "You clicked" << std::endl;
			std::cout << "Node  " << clickedNode->id << "\n";
			playerXPos = clickedNode->x;
			playerYPos = clickedNode->y;

		}

		if ((GetKeyState(VK_RBUTTON) & 0x100) != 0)
		{
			//std::cout << "ZZZZZZZZ" << std::endl;

			targetX = clickedNode->x;
			targetY = clickedNode->y;


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
		currentTime = 0;

		//poll for and process events
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}