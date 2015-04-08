#pragma once
#include "GraphNode.h"
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include "Quad.h"
#include <list>
#include <glm/glm.hpp>

class SteeringAgent : public Quad
{
public:
	SteeringAgent();
	SteeringAgent(const char * texturePath, float r, float g, float b);
	~SteeringAgent();

	void update(float deltaTime);
	float slowingRadius = 100;
	glm::vec2 velocity;
	glm::vec2 max_velocity;
	Quad * targetPos;

	void seek();
	void flee();
	void arrive();
};