#include "ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Ball::Ball(){

}

Ball::Ball(sf::Vector2f _pos, double _radius){
	pos = _pos;
	previousPos = _pos;
	radius = _radius;
	acceleration = sf::Vector2f(10,0);
}

Ball::Ball(double x, double y, double _radius){
	pos = sf::Vector2f(x, y);
	previousPos = sf::Vector2f(x, y);
	radius = _radius;
	acceleration = sf::Vector2f(0,-100);
}
	
void Ball::update(float dt){
	
	sf::Vector2f temp = pos;
	pos = 2.0f * pos - previousPos + acceleration * dt * dt;
	previousPos = temp;
	
	if (pos.y <= radius) {
		pos.y = -pos.y + 2.0f * radius;
		previousPos.y = -previousPos.y + 2.0f * radius;
	
	}

}
	
void Ball::show(sf::RenderWindow& window){
	sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Red);
    circle.setOrigin(radius, radius); // Center the circles
    circle.setPosition(pos);
    window.draw(circle);

}
	
	
	
	
Ball::~Ball(){

}
