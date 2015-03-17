#include "GraphNode.h"
GraphNode::GraphNode()
{


}

void Edge::PrintEnd()
{
	std::cout << m_pEnd->id << std::endl;
}



void GraphNode::PrintNeighbors()
{
	for (int i = 0; i < m_aEdges.size(); i++)
	{
		if (m_aEdges[i].m_pStart != this ||
			m_aEdges[i].m_pEnd == this)
		{
			// skip over
			continue;
		}

		std::cout << "Node  [";
		std::cout << this->id;
		std::cout << "]  has neighbor/s:  [";
		std::cout << m_aEdges[i].m_pEnd->id;
		std::cout << "]" << std::endl;

	}
}
void GraphNode::SetNode(int id, float x, float y)
{
	this->id = id;
	this->x = x;
	this->y = y;

}



//questionable if necessary at all
bool GraphNode::CheckIfNeighbor(GraphNode* nodeB)
{
if (this->m_aEdges[0].m_pEnd == nodeB->m_aEdges[1].m_pStart &&
this->m_aEdges[0].m_pStart == nodeB->m_aEdges[1].m_pEnd||
this->m_aEdges[1].m_pEnd == nodeB->m_aEdges[0].m_pStart &&
this->m_aEdges[1].m_pStart == nodeB->m_aEdges[0].m_pEnd
/*||
this->m_aEdges[0].m_pEnd == nodeB->m_aEdges[0].m_pStart &&
this->m_aEdges[0].m_pStart == nodeB->m_aEdges[0].m_pEnd ||
this->m_aEdges[1].m_pEnd == nodeB->m_aEdges[1].m_pStart &&
this->m_aEdges[1].m_pStart == nodeB->m_aEdges[1].m_pEnd*/
)
{
return true;
}
else return false;
}


GraphNode::~GraphNode()
{
}