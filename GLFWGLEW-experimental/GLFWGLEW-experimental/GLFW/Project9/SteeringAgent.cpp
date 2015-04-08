#include "SteeringAgent.h"
SteeringAgent::SteeringAgent()
{}



SteeringAgent::SteeringAgent(const char * texturePath, float r, float g, float b) :Quad(texturePath, r,g,b)
{
	
}
void SteeringAgent::update(float deltaTime)
{
	x += velocity.x * deltaTime;
	y += velocity.y * deltaTime;
}

SteeringAgent::~SteeringAgent()
{

}

void SteeringAgent::seek()
{
	velocity = glm::normalize(glm::vec2(targetPos->x, targetPos->y) - glm::vec2(x, y)) * max_velocity;
}
void SteeringAgent::flee()
{
	velocity = -glm::normalize(glm::vec2(targetPos->x, targetPos->y) - glm::vec2(x, y)) *max_velocity;
}
void SteeringAgent::arrive()
{

	float distance = glm::distance(glm::vec2(x, y), glm::vec2(targetPos->x, targetPos->y));
	velocity = glm::normalize(glm::vec2(targetPos->x, targetPos->y) - glm::vec2(x, y)) * max_velocity;
	
	if (distance < (slowingRadius))
	{
		std::cout << "sadlkjsdlfj" << std::endl;
		velocity.x *= .25;
		velocity.y *= .25;

		
	}
	if ( (targetPos->x - x)*(targetPos->x - x)<0.01 && (targetPos->y - y) *(targetPos->y - y) <0.01)
	{
	
		velocity.x = 0;
		velocity.y = 0;
	}

}