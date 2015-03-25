#pragma once
#include "GraphNode.h"
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include "Quad.h"
#include <list>
#include <glm/glm.hpp>


class Graph
{

	typedef std::vector<GraphNode*> NodeList;
	


	
	
public:
	//Creates an empty graph
	Graph();

	~Graph();
	
	//Creates a graph with the given number of nodes
	//the contents and links of the nodes are randomised
	Graph(unsigned int a_uiNodeCount);
	void AddNode(GraphNode* a_pNode);
	void RemoveNode(GraphNode* node);
	void ResetVisited();
	GraphNode * FindLeastDist(float mouseX, float mouseY);
	void SetGraphData(float xStart, float yStart, int xCount, int yCount, float spacing);
	void CreateGraph(int screenSize);
	
	Quad * tile;
	void DrawGraph();
	float xStart = 0;
	float yStart = 0;
	int xCount = 0;
	int yCount = 0;
	float leastDist=0;
	class State *current;
	void setCurrent(State *s)
	{
		State *Open;
		State *Closed;
		current = s;
	}
	void GraphMoveTest(float moveValue, float deltaTime);
	bool aStar(GraphNode * start , GraphNode * goal);
	bool Dijkstra(GraphNode*start,GraphNode*goal);
	static bool AStarNodeCompare(const GraphNode* start, const GraphNode* goal);
	float spacing = 0;
	float GetHeuristic(const GraphNode* start, const GraphNode* goal);
	static bool NodeCompare(const GraphNode* left, const GraphNode* right);
	bool SearchDFS(GraphNode* a_pStart, GraphNode* a_pEnd);
	bool SearchBFS(GraphNode* a_pStart, GraphNode* a_pEnd);
	glm::vec2 Seek(Quad target);

	//private:
	NodeList	m_aNodes;
	
	




};