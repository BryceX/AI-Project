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
#include "SteeringAgent.h"
#define 	GLFW_KEY_UNKNOWN   -1

#define 	GLFW_KEY_SPACE   32

#define 	GLFW_KEY_APOSTROPHE   39 /* ' */

#define 	GLFW_KEY_COMMA   44 /* , */

#define 	GLFW_KEY_MINUS   45 /* - */

#define 	GLFW_KEY_PERIOD   46 /* . */

#define 	GLFW_KEY_SLASH   47 /* / */

#define 	GLFW_KEY_0   48

#define 	GLFW_KEY_1   49

#define 	GLFW_KEY_2   50

#define 	GLFW_KEY_3   51

#define 	GLFW_KEY_4   52

#define 	GLFW_KEY_5   53

#define 	GLFW_KEY_6   54

#define 	GLFW_KEY_7   55

#define 	GLFW_KEY_8   56

#define 	GLFW_KEY_9   57

#define 	GLFW_KEY_SEMICOLON   59 /* ; */

#define 	GLFW_KEY_EQUAL   61 /* = */

#define 	GLFW_KEY_A   65

#define 	GLFW_KEY_B   66

#define 	GLFW_KEY_C   67

#define 	GLFW_KEY_D   68

#define 	GLFW_KEY_E   69

#define 	GLFW_KEY_F   70

#define 	GLFW_KEY_G   71

#define 	GLFW_KEY_H   72

#define 	GLFW_KEY_I   73

#define 	GLFW_KEY_J   74

#define 	GLFW_KEY_K   75

#define 	GLFW_KEY_L   76

#define 	GLFW_KEY_M   77

#define 	GLFW_KEY_N   78

#define 	GLFW_KEY_O   79

#define 	GLFW_KEY_P   80

#define 	GLFW_KEY_Q   81

#define 	GLFW_KEY_R   82

#define 	GLFW_KEY_S   83

#define 	GLFW_KEY_T   84

#define 	GLFW_KEY_U   85

#define 	GLFW_KEY_V   86

#define 	GLFW_KEY_W   87

#define 	GLFW_KEY_X   88

#define 	GLFW_KEY_Y   89

#define 	GLFW_KEY_Z   90

#define 	GLFW_KEY_LEFT_BRACKET   91 /* [ */

#define 	GLFW_KEY_BACKSLASH   92 /* \ */

#define 	GLFW_KEY_RIGHT_BRACKET   93 /* ] */

#define 	GLFW_KEY_GRAVE_ACCENT   96 /* ` */

#define 	GLFW_KEY_WORLD_1   161 /* non-US #1 */

#define 	GLFW_KEY_WORLD_2   162 /* non-US #2 */

#define 	GLFW_KEY_ESCAPE   256

#define 	GLFW_KEY_ENTER   257

#define 	GLFW_KEY_TAB   258

#define 	GLFW_KEY_BACKSPACE   259

#define 	GLFW_KEY_INSERT   260

#define 	GLFW_KEY_DELETE   261

#define 	GLFW_KEY_RIGHT   262

#define 	GLFW_KEY_LEFT   263

#define 	GLFW_KEY_DOWN   264

#define 	GLFW_KEY_UP   265

#define 	GLFW_KEY_PAGE_UP   266

#define 	GLFW_KEY_PAGE_DOWN   267

#define 	GLFW_KEY_HOME   268

#define 	GLFW_KEY_END   269

#define 	GLFW_KEY_CAPS_LOCK   280

#define 	GLFW_KEY_SCROLL_LOCK   281

#define 	GLFW_KEY_NUM_LOCK   282

#define 	GLFW_KEY_PRINT_SCREEN   283

#define 	GLFW_KEY_PAUSE   284

#define 	GLFW_KEY_F1   290

#define 	GLFW_KEY_F2   291

#define 	GLFW_KEY_F3   292

#define 	GLFW_KEY_F4   293

#define 	GLFW_KEY_F5   294

#define 	GLFW_KEY_F6   295

#define 	GLFW_KEY_F7   296

#define 	GLFW_KEY_F8   297

#define 	GLFW_KEY_F9   298

#define 	GLFW_KEY_F10   299

#define 	GLFW_KEY_F11   300

#define 	GLFW_KEY_F12   301

#define 	GLFW_KEY_F13   302

#define 	GLFW_KEY_F14   303

#define 	GLFW_KEY_F15   304

#define 	GLFW_KEY_F16   305

#define 	GLFW_KEY_F17   306

#define 	GLFW_KEY_F18   307

#define 	GLFW_KEY_F19   308

#define 	GLFW_KEY_F20   309

#define 	GLFW_KEY_F21   310

#define 	GLFW_KEY_F22   311

#define 	GLFW_KEY_F23   312

#define 	GLFW_KEY_F24   313

#define 	GLFW_KEY_F25   314

#define 	GLFW_KEY_KP_0   320

#define 	GLFW_KEY_KP_1   321

#define 	GLFW_KEY_KP_2   322

#define 	GLFW_KEY_KP_3   323

#define 	GLFW_KEY_KP_4   324

#define 	GLFW_KEY_KP_5   325

#define 	GLFW_KEY_KP_6   326

#define 	GLFW_KEY_KP_7   327

#define 	GLFW_KEY_KP_8   328

#define 	GLFW_KEY_KP_9   329

#define 	GLFW_KEY_KP_DECIMAL   330

#define 	GLFW_KEY_KP_DIVIDE   331

#define 	GLFW_KEY_KP_MULTIPLY   332

#define 	GLFW_KEY_KP_SUBTRACT   333

#define 	GLFW_KEY_KP_ADD   334

#define 	GLFW_KEY_KP_ENTER   335

#define 	GLFW_KEY_KP_EQUAL   336

#define 	GLFW_KEY_LEFT_SHIFT   340

#define 	GLFW_KEY_LEFT_CONTROL   341

#define 	GLFW_KEY_LEFT_ALT   342

#define 	GLFW_KEY_LEFT_SUPER   343

#define 	GLFW_KEY_RIGHT_SHIFT   344

#define 	GLFW_KEY_RIGHT_CONTROL   345

#define 	GLFW_KEY_RIGHT_ALT   346

#define 	GLFW_KEY_RIGHT_SUPER   347

#define 	GLFW_KEY_MENU   348

#define 	GLFW_KEY_LAST   GLFW_KEY_MENU


#define GLFW_RELEASE 0
#endif // !_GRAPH_H_


int astConstant = 40;
float deltaTime = 0;
float currentTime = glfwGetTime();
float lastFrame = currentTime;
float x = 0;
float y = 0;
float windowSize = 600;
int squares = 5;
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

	//EEnsert this into the main.cpp example given in the setting up GLFW section E
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
	
	
	//Quad player("square.png", 1,1,0);
	float playerXPos = squareSize / 2;
	float playerYPos = squareSize / 2;
	//GraphNode player1;


	//Quad target("square.png", 1, 0, 1);
	float targetX = 0;
	float targetY = 0;
	GraphNode target1;
	//target1.entity->sprite->fColours[0] = 1.0f;
	//target1.entity->sprite->fColours[1] = 0.0f;
	//target1.entity->sprite->fColours[2] = 1.0f;
	//target1.entity->sprite->fColours[3] = 1.0f;


	/*float xPos = ;
	float yPos = windowSize/squares*2;*/
	
	
	Binding myBox;
	

	std::vector<Binding> myBoxes;
	

	


	SteeringAgent target("square.png", 1,0.5f,1);
	target.x = 200;
	target.y = 200;

	SteeringAgent myAgent("square.png", 1, 0, 1);
	myAgent.max_velocity = glm::vec2(100, 100);
	myAgent.x = 600;
	myAgent.y = 600;
	myAgent.targetPos = &target;



	HWND tempWin;
	Text myText;
	glScalef(1.f, -1.f, 1.f);

	playerXPos = myGraph.m_aNodes[0]->x;
	playerYPos = myGraph.m_aNodes[0]->y;
	//myGraph.SearchDFS(myGraph.m_aNodes[1], myGraph.m_aNodes[1]);


	Player player1("square.png");


	//myGraph.Dijkstra(myGraph.m_aNodes[0], myGraph.m_aNodes[15]);



	while (!glfwWindowShouldClose(myGlobals.window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		GetDeltaTime();

		
		//currentTime = glfwGetTime();
		//deltaTime = currentTime - lastFrame;
		//lastFrame = currentTime;
		
		
		myGraph.DrawGraph();
		//player.Draw(playerXPos, playerYPos, squareSize, squareSize);
		//target.Draw(targetX, targetY, squareSize, squareSize);
		//myGraph.GraphMoveTest(20, deltaTime);
		
		
		player1.Draw(playerXPos, playerYPos, squareSize / 3, squareSize / 3);
		
		//std::cout << playerXPos << std::endl;

		//dijkstra
		//todo pushback all neighbors of each node into a container
		//figure out how to make container accessable by everything
		//make a new container for every node
		//make blocks change color for path by changing rgb values
		//have the lowest weight edge ending node become the new node
		//check all neighbors of new node and repeat until at goal node and repeat previous step
	
	//	myAgent.seek();
		//myAgent.flee();
		myAgent.arrive();
		myAgent.update(deltaTime);
		myAgent.Draw(myAgent.x, myAgent.y, 50, 50);
		target.Draw(target.x, target.y, 50, 50);

		



		









		POINT p;
		double xPos;
		double yPos;

		glfwGetCursorPos(myGlobals.window, &xPos, &yPos);


		GraphNode * clickedNode = myGraph.FindLeastDist(xPos, yPos);
		GraphNode * clickedNode2 = myGraph.FindLeastDist(xPos, yPos);


	
	if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
		{
			
		target.x = xPos;
		target.y = yPos;
				
			//myGraph.Dijkstra(myGraph.m_aNodes[clickedNode->id], myGraph.m_aNodes[15]);

		}
		if ((GetKeyState(VK_RBUTTON) & 0x100) != 0)
		{
			//std::cout << "ZZZZZZZZ" << std::endl;

			//targetX = clickedNode->x;
			//targetY = clickedNode->y;
			//myGraph.Dijkstra(clickedNode, myGraph.m_aNodes[24]);
			myGraph.m_aNodes[1]->gScore = 10;
			myGraph.m_aNodes[2]->gScore = 10;
			myGraph.m_aNodes[10]->gScore = 10;
			myGraph.m_aNodes[15]->gScore = 10;
			myGraph.m_aNodes[11]->gScore = 10;



			graphCounter += 1;

			if (0 < xPos && xPos < windowSize && 0 < yPos && yPos < windowSize)
			{

				if (clickedNode != nullptr)
				{
					int nodeX = windowSize / squares;







				}

				if (GetCursorPos(&p))
				{

					//std::cout << "at " << xPos << "X   " << yPos << "Y" << std::endl;

				}
			}


			//std::cout << "You clicked" << std::endl;
			//std::cout << "Node  " << clickedNode->id << "\n";
			playerXPos = clickedNode->x;
			playerYPos = clickedNode->y;

			//myGraph.Dijkstra(clickedNode, myGraph.m_aNodes[24]);
			myGraph.aStar(clickedNode, myGraph.m_aNodes[24], 1);

		}

		if (GetKeyState(32))
		{
		
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