#pragma once
#include <vector>
#include <iostream>
#include <list>
#include "Quad.h"


class GraphNode;
struct Edge
{
	Edge() {}
	~Edge() {}
	Edge(GraphNode* start, GraphNode* end, float cost)
	{

		m_pStart = start;
		m_pEnd = end;
		m_fCost = cost;
	}



	GraphNode*	m_pStart;
	GraphNode*	m_pEnd;
	float		m_fCost;
	void PrintEnd();

};

class GraphNode
{
	

public:
	GraphNode(int a_iNum);
	void PrintNeighbors();
	bool CheckIfNeighbor(GraphNode* nodeB);
	bool Visited = false;
	void IsNeighbor();
	void DrawEntity(float x, float y, float width, float height);
	void SetNode(int id, float x, float y);
	float x = 0;
	float y = 0;
	int	id;
	GraphNode* lastNode;
	Quad * entity;
	float gScore =0;
	float fScore=0;
	typedef std::vector<Edge> EdgeList;
	EdgeList  m_aEdges;

	
	


	GraphNode();

	~GraphNode();
};