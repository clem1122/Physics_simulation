#pragma once
#include <SFML/Graphics.hpp>
#include "wall.h"

class Ball{
private:
	sf::Vector2f pos;
	sf::Vector2f previousPos;
	sf::Vector2f acceleration;
	double radius;
	
	sf::Color color;
	
public:
	Ball();
	Ball(sf::Vector2f _pos, double _radius);
	Ball(double x, double y, double radius);
	
	~Ball();
	
	void update(float dt);
	void show(sf::RenderWindow& window);
	
	std::vector<sf::Vector2f> wallIntersection(Wall w);
	void wallBounce(Wall w);
	
	
	
	sf::Vector2f getPos(){return pos;}
	sf::Vector2f getVel(float dt){return (pos - previousPos) /dt;}
	sf::Vector2f getAcc(){return acceleration;}
	double    getRadius(){return radius;}
	
	void setPos(sf::Vector2f p){pos = p;}
	void setAcc(sf::Vector2f a){acceleration = a;}
};

