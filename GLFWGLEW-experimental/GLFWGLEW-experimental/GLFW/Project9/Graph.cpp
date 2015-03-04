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


Graph Graph::CreateGraph(float xSpace, float ySpace, int xNum, int yNum)
{
	Graph tempGraph;
	Quad tile("square.png");

	// creating the graph
	for (int i = 0, id = 0; i < xNum; i++)
	{
		for (int j = 0; j < yNum; j++)
		{
			GraphNode * temp = new GraphNode();
			temp->x = i;
			temp->y = j;
			temp->id = id;

			// todo
			//temp2->x = i + xSpace;
			//temp2->y = j + ySpace;
			id++;

			tempGraph.AddNode(temp);
			tile.Draw((temp->x*10), (temp->y*10), xSpace/2, ySpace/2);
			//// goes right
			//if (yNum*2>id>0 && id != xNum)
			//{
			//	Edge tempEdge1;
			//	tempEdge1.m_pStart = temp;
			//	tempEdge1.m_pEnd = temp2;
			//	tempEdge1.m_fCost = 1;
			//	
			//	temp->m_aEdges.push_back(tempEdge1);
			//}
			//temp->PrintNeighbors();
		}
	}

	// adding neighbors
	for (int k = 0, currentID = 0; k < xNum; k++)
	{
		for (int l = 0; l < yNum; l++)
		{
			GraphNode * currentNode = tempGraph.m_aNodes[currentID];


			//std::cout << "Working on: " << currentNode->id << "\n";

			// up
			if (currentID + yNum < tempGraph.m_aNodes.size())
			{
				Edge temp(currentNode, tempGraph.m_aNodes[currentID + yNum], 1);
				currentNode->m_aEdges.push_back(temp);
				tempGraph.m_aNodes[currentID + yNum]->m_aEdges.push_back(temp);
			}

			// down
			if (currentID - yNum > 0)
			{
				Edge temp(currentNode, tempGraph.m_aNodes[currentID - yNum], 1);
				currentNode->m_aEdges.push_back(temp);
				tempGraph.m_aNodes[currentID - yNum]->m_aEdges.push_back(temp);
			}

			//left
			if (currentID - 1 >= 0 &&	// not below 0
				currentID % xNum != 0)	// not a multiple of the xNum
			{
				Edge temp(currentNode, tempGraph.m_aNodes[currentID - 1], 1);
				currentNode->m_aEdges.push_back(temp);
				tempGraph.m_aNodes[currentID - 1]->m_aEdges.push_back(temp);
			}

			//right
			if (currentID + 1 < xNum * yNum &&
				(currentID + 1) % xNum != 0)
			{
				Edge temp(currentNode, tempGraph.m_aNodes[currentID + 1], 1);
				currentNode->m_aEdges.push_back(temp);
				tempGraph.m_aNodes[currentID + 1]->m_aEdges.push_back(temp);
			}



			// left
			// right

			//temp->x = k;
			//temp->y = l;
			//temp->id = id;

			//temp2->x = k + xSpace;
			//temp2->y = l + ySpace;
			//temp2->id = id + yNum;
			//if (yNum*xNum>id>0)
			//{
			//	Edge tempEdge2;
			//	tempEdge2.m_pStart = temp;
			//	tempEdge2.m_pEnd = temp2;
			//	tempEdge2.m_fCost = 1;
			//	temp->m_aEdges.push_back(tempEdge2);
			//}
			//currentNode->PrintNeighbors();


			//tempGraph.m_aNodes[currentID + yNum]->PrintNeighbors();
			currentID++;
		}


	}

	// creating the graph
	for (int i = 0, id = 0; i < xNum; i++)
	{
		for (int j = 0; j < yNum; j++)
		{
			tempGraph.m_aNodes[id]->PrintNeighbors();
			id++;
		}
	}

	return tempGraph;
}




Graph::~Graph()
{
}