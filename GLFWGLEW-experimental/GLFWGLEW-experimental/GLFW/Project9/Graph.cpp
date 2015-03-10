#include "Graph.h"
Graph::Graph()
{

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

void Graph::SetGraphData(int xSpace, int ySpace, int xCount, int yCount)
{
	this->xSpace = xSpace;
	this->ySpace = ySpace;
	this->xCount = xCount;
	this->yCount = yCount;

}



Graph Graph::CreateGraph()
{
	
	Graph tempGraph;
	
	// creating the graph
	for (int i = 0, id = 0; i < xCount; i++)
	{
		for (int j = 0; j < yCount; j++)
		{
			GraphNode * temp = new GraphNode();
			temp->x = i;
			temp->y = j;
			temp->id = id;
			

			
			id++;

			tempGraph.AddNode(temp);
			
		
		}
	}


	// adding neighbors
	for (int k = 0, currentID = 0; k < xCount; k++)
	{
		for (int l = 0; l < yCount; l++)
		{
			GraphNode * currentNode = tempGraph.m_aNodes[currentID];


			//std::cout << "Working on: " << currentNode->id << "\n";

			// up
			if (currentID + yCount < tempGraph.m_aNodes.size())
			{
				Edge temp(currentNode, tempGraph.m_aNodes[currentID + yCount], 1);
				currentNode->m_aEdges.push_back(temp);
				tempGraph.m_aNodes[currentID + yCount]->m_aEdges.push_back(temp);
			}

			// down
			if (currentID - yCount > 0)
			{
				Edge temp(currentNode, tempGraph.m_aNodes[currentID - yCount], 1);
				currentNode->m_aEdges.push_back(temp);
				tempGraph.m_aNodes[currentID - yCount]->m_aEdges.push_back(temp);
			}

			//left
			if (currentID - 1 >= 0 &&	// not below 0
				currentID % xCount != 0)	// not a multiple of the xNum
			{
				Edge temp(currentNode, tempGraph.m_aNodes[currentID - 1], 1);
				currentNode->m_aEdges.push_back(temp);
				tempGraph.m_aNodes[currentID - 1]->m_aEdges.push_back(temp);
			}

			//right
			if (currentID + 1 < xCount * yCount &&
				(currentID + 1) % xCount != 0)
			{
				Edge temp(currentNode, tempGraph.m_aNodes[currentID + 1], 1);
				currentNode->m_aEdges.push_back(temp);
				tempGraph.m_aNodes[currentID + 1]->m_aEdges.push_back(temp);
			}



			
			currentID++;
		
		}


	}
	
	// creating the graph
	for (int i = 0, id = 0; i < xCount; i++)
	{
		for (int j = 0; j < yCount; j++)
		{
			tempGraph.m_aNodes[id]->PrintNeighbors();
			id++;
		}
	}
	
	return tempGraph;
}

void Graph::DrawGraph()
{
	Graph tempGraph;
	Quad tile("square.png");
	int yRows = 0;
	int xColumns = 0;
	
	for (int i = 0, id = 0; i < xCount; i++)
	{
		for (int j = 0; j < yCount; j++)
		{
			GraphNode * temp = new GraphNode();
			temp->id = id;



			id++;

			tempGraph.AddNode(temp);


		}
	}
	
	
	
	for (int k = 0; k < yCount; k++)
	{
		for (int l = 0; l < xCount; l++)
		{
			
				tile.Draw( tempGraph.m_aNodes[l]->x+xSpace, tempGraph.m_aNodes[k]->y+ySpace, spacing, spacing);
				tempGraph.m_aNodes[l]->x += spacing;
				xColumns += 1;
				tempGraph.m_aNodes[k]->y += spacing;

			if (xColumns > xCount)
			{
				yRows += 1;
				xColumns = 0;
				tempGraph.m_aNodes[l]->x = tempGraph.m_aNodes[0]->x;
			
				
			}
			
		}
		
	}
	//std::cout << tempGraph.m_aNodes.size();
	//std::cout << tempGraph.m_aNodes[0]->x << std::endl;
	//std::cout << tempGraph.m_aNodes[0]->y << std::endl;
}



Graph::~Graph()
{
}