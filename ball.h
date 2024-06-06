#pragma once
#include <SFML/Graphics.hpp>

class Ball{
private:
	sf::Vector2f pos;
	sf::Vector2f previousPos;
	sf::Vector2f acceleration;
	double radius;
	
public:
	Ball();
	Ball(sf::Vector2f _pos, double _radius);
	Ball(double x, double y, double radius);
	
	~Ball();
	
	void update(float dt);
	
	
	sf::Vector2f getPos(){return pos;}
	sf::Vector2f getVel(float dt){return (pos - previousPos) /dt;}
	sf::Vector2f getAcc(){return acceleration;}
	double    getRadius(){return radius;}
	
	void setPos(sf::Vector2f p){pos = p;}
	void setAcc(sf::Vector2f a){acceleration = a;}
};

