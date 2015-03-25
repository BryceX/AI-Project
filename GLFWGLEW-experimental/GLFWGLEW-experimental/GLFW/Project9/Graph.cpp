#include "Graph.h"
Graph::Graph()
{
	tile = new Quad("square.png",1,1,1);
}
void Graph::AddNode(GraphNode* a_pNode)
{
	m_aNodes.push_back(a_pNode);
}

void Graph::RemoveNode(GraphNode* node)
{
	//loop through every node in the vector
	for (int i = 0; i < m_aNodes.size(); i++)
	{
		//looping through every edge in each node
		for (int j = 0; j < m_aNodes[i]->m_aEdges.size(); j++)
		{
			// check if the edge ends with the node we are trying to remove
			if (m_aNodes[i]->m_aEdges[j].m_pEnd == node)
			{
				// erase that edge
				m_aNodes[i]->m_aEdges.erase(m_aNodes[i]->m_aEdges.begin() + j);
			}

		}

	}

	// loop over each node in the node list
	for (int i = 0; i < m_aNodes.size(); ++i)
	{
		if (node == m_aNodes[i])
		{
			m_aNodes.erase(m_aNodes.begin() + i);
			break;
		}
	}
	// check if we've found the node we're trying to remove

	// remove it

}

void Graph::ResetVisited()
{
	bool Visited = false;
}



bool Graph::SearchDFS(GraphNode* a_pStart, GraphNode* a_pEnd)//Add to SearchDFS function
{
	std::stack <GraphNode*> oNodeStack;
	oNodeStack.push(a_pStart);

	while (!oNodeStack.empty())
	{
		//the rest of the algorithm goes in here
		GraphNode* pCurrent = oNodeStack.top();
		oNodeStack.pop();

		if (pCurrent->m_aEdges[0].m_pEnd->Visited == true)
		{
			continue;
		}

		pCurrent->Visited = true;

		if (pCurrent == a_pEnd)
		{
			return true;
		}

		// Add all of its unvisited neighbors
		for (int i = 0; i < pCurrent->m_aEdges.size(); ++i)
		{
			if (!pCurrent->m_aEdges[i].m_pEnd->Visited)
			{
				oNodeStack.push(pCurrent->m_aEdges[i].m_pEnd);
			}
		}
	}
	//return false if we didn't find a_pEnd
	return false;
}





bool Graph::SearchBFS(GraphNode* a_pStart, GraphNode* a_pEnd)//Add to SearchDFS function
{
	std::queue <GraphNode*> oNodeQueue;
	oNodeQueue.push(a_pStart);

	//add to the SearchDFS function

	//keep looping until the stack is empty. 
	//This will only happen once we've checked every node. 
	while (!oNodeQueue.empty())
	{
		//the rest of the algorithm goes in here
		GraphNode* pCurrent = oNodeQueue.front();
		oNodeQueue.pop();

		if (pCurrent->m_aEdges[0].m_pEnd->Visited == true)
		{
			continue;
		}

		pCurrent->Visited = true;

		if (pCurrent == a_pEnd)
		{
			return true;
		}

		for (int i = 0; i < pCurrent->m_aEdges.size(); ++i)
		{
			oNodeQueue.push(pCurrent->m_aEdges[i].m_pEnd);
		}
	}

	//return false if we didn't find a_pEnd
	return false;
}

void Graph::SetGraphData(float xStart, float yStart, int xCount, int yCount, float spacing)
{
	this->xStart = xStart;
	this->yStart = yStart;
	this->xCount = xCount;
	this->yCount = yCount;
	this->spacing = spacing;
}


void Graph::CreateGraph(int screenSize)
{
	std::list<Edge> neighbors;
	// creating the graph
	float xNum = xCount;
	float yNum = yCount;

	// iterate over tiles
	for (int i = 0, id = 0; i < xCount; i++)
	{

		// x
		//for (int k = 0; k < 1; k++)
		{
			// y
		for (int j = 0; j < yCount; j++)
		{
			GraphNode * temp = new GraphNode();
			temp->x = 0;
			temp->y = 0;
			temp->x += ((j*2+1)*(spacing/2));
			temp->y += (i*2+1)*(spacing/2);
			temp->id = id;



			id++;

			AddNode(temp);
		}
		}
			
	}


	// adding neighbors
	for (int k = 0, currentID = 0; k < xCount; k++)
	{
		for (int l = 0; l < yCount; l++)
		{

			GraphNode * currentNode = m_aNodes[currentID];
			

			//std::cout << "Working on: " << currentNode->id << "\n";

			// up
			if (currentID + yCount < m_aNodes.size())
			{
				Edge temp(currentNode, m_aNodes[currentID + yCount], 1);
				currentNode->m_aEdges.push_back(temp);
				//m_aNodes[currentID + yCount]->m_aEdges.push_back(temp);
			}

			// down
			if (0 <= (currentID - yCount))
			{
				Edge temp(currentNode, m_aNodes[currentID - yCount], 1);
				currentNode->m_aEdges.push_back(temp);
				//m_aNodes[currentID - yCount]->m_aEdges.push_back(temp);
			}

			

			//left
			if (currentID >= 0 &&	// not below 0
				currentID % xCount != 0)	// not a multiple of the xNum
			{
				Edge temp(currentNode, m_aNodes[currentID - 1], 1);
				currentNode->m_aEdges.push_back(temp);
				//m_aNodes[currentID - 1]->m_aEdges.push_back(temp);
			}

			//right
			if (currentID + 1 < xCount * yCount &&
				(currentID + 1) % xCount != 0)
			{
				Edge temp(currentNode, m_aNodes[currentID + 1], 1);
				currentNode->m_aEdges.push_back(temp);
				//m_aNodes[currentID + 1]->m_aEdges.push_back(temp);
			}



			
			currentID++;
		
		}


	}
	

	for (int i = 0, id = 0; i < xCount; i++)
	{
		for (int j = 0; j < yCount; j++)
		{
			m_aNodes[id]->PrintNeighbors();
			id++;

			
		
		}
	}


	
}

bool Graph::NodeCompare(const GraphNode* left, const GraphNode* right)
{
	
	
		return (left->gScore < right->gScore );
	
}


void Graph::DrawGraph()
{
	//todo use values from creategraph
	
	int yRows = 0;
	int xColumns = 0;
	int xPos = spacing/2;// +xStart;
	int yPos = spacing/2;// +yStart;
	float width = spacing;
	float height = spacing;
	
	for (int k = 0; k < yCount; k++)
	{
		for (int l = 0;  l < xCount; l++)
		{
			
			

				tile->Draw(xPos, yPos, width, height);
				xPos += spacing;
				
				xColumns += 1; //moves tiles back, moves them up
			if (xColumns >= xCount)
			{
				yRows += 1;
				xColumns = 0;
				xPos = spacing/2;
				yPos += spacing;
			}
		}
	}
	
	//std::cout << tempGraph.m_aNodes.size();
	//std::cout << tempGraph.m_aNodes[0]->x << std::endl;
	//std::cout << tempGraph.m_aNodes[0]->y << std::endl;
}


float distance(float leftX, float leftY, float rightX, float rightY)
{
	return sqrt(pow(leftX - rightX, 2) + pow(leftY-rightY , 2));
}


float GetHeuristic(const GraphNode* start, const GraphNode* goal)
{
	//return (glm::vec2(start->x, start->y) - glm::vec2(goal->x, goal->y));//GetMagnitude();
}

bool AStarNodeCompare(const GraphNode* left, const GraphNode* right)
{
	float leftF = left->gScore + GetHeuristic(left, right);
	float rightF = right->gScore + GetHeuristic(right, left);
	return (leftF < rightF);
}

bool Graph::aStar(GraphNode* start, GraphNode * goal)
{
	std::list<GraphNode*> nodeQueue;
	for (int i = 0; i < m_aNodes.size(); i++)
	{
		m_aNodes[i]->N = NULL;
		m_aNodes[i]->gScore = INFINITY;
		m_aNodes[i]->fScore = INFINITY;
	}
	nodeQueue.sort(NodeCompare);
	nodeQueue.push_back(start);
	start->N = NULL;
	start->gScore = 0;
	start->fScore = 0;

	while (!nodeQueue.empty())
	{
		GraphNode* current = nodeQueue.front();
		nodeQueue.pop_front();
		current->Visited = true;
		if (current == goal)
		{
			return true;
		}
		//iterate through every edge
		for (int j = 0; j < current->m_aEdges.size(); j++)
		{

			if (current->m_aEdges[j].m_pEnd->Visited == false)
			{

				//
				nodeQueue.push_front(current->m_aEdges[j].m_pEnd);
				//add the cost of the gscore to the edge just crossed
				current->m_aEdges[j].m_pEnd->gScore = (current->gScore + current->m_aEdges[j].m_fCost);
				
				
			}
		}
	}
}
bool Graph::Dijkstra(GraphNode* start, GraphNode * goal)
{
	std::list<GraphNode*> nodeQueue;
	for (int i = 0; i < m_aNodes.size(); i++)
	{
		m_aNodes[i]->N = NULL;
		m_aNodes[i]->gScore = INFINITY;
		m_aNodes[i]->fScore = INFINITY;
	}
	
	nodeQueue.push_back(start);
	start->N = NULL;
	start->gScore = 0;
	start->fScore = 0;

	while (!nodeQueue.empty())
	{
		GraphNode* current = nodeQueue.front();
		
		nodeQueue.pop_front();
		//nodeQueue.sort(NodeCompare);

		
		//bool isLeast = true;
		//if (isLeast)
		
	
		if (current->Visited == true)
		{
			continue;
		}

		current->Visited = true;
		std::cout << current->id << std::endl;
		if (current == goal)
		{
			std::cout << "goal reached" << std::endl;
			return true;
		}
		
		//looping over each edge to see if we havebeen there
		for (int j = 0; j < current->m_aEdges.size(); j++)
		{
			// have we visited the end of that node?
			if (current->m_aEdges[j].m_pEnd->Visited == false)
			{

				// add it to the front of the queue
				nodeQueue.push_back(current->m_aEdges[j].m_pEnd);
				//calculate the cost of the gscore to the edge just crossed
				current->m_aEdges[j].m_pEnd->gScore = (current->gScore + current->m_aEdges[j].m_fCost);
				
				
			}
		}

	}
}
GraphNode * Graph::FindLeastDist(float mouseX, float mouseY)
{
	int shortestDistance = INT_MAX;
	GraphNode * closestNode = nullptr;

	// loop over all the nodes
	for (int i = 0; i < m_aNodes.size(); i++)
	{
		// calculating the distance between the node and the cursor
		float nodeDistance = distance(m_aNodes[i]->x, m_aNodes[i]->y, mouseX, mouseY);
		
		// checks to see if this distance is shorter than the current shortest distance
		if (nodeDistance < shortestDistance)
		{
			shortestDistance = nodeDistance;
			closestNode = m_aNodes[i];
		}

	}

	return closestNode;



}
void Graph::GraphMoveTest(float moveValue, float deltaTime)
{
	tile->x += moveValue*deltaTime;

}
glm::vec2 Graph::Seek(Quad target)
{
	glm::vec2 test = glm::normalize(glm::vec2(target.x, target.y) - glm::vec2(this->m_aNodes[0]->x, this->m_aNodes[0]->y));
	return test;
}

Graph::~Graph()
{
}