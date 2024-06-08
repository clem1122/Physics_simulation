#include "ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "wall.h"
#include "cmath"

Ball::Ball(){

}

Ball::Ball(sf::Vector2f _pos, double _radius){
	pos = _pos;
	previousPos = _pos;
	radius = _radius;
	acceleration = sf::Vector2f(10,0);
	color = sf::Color(255,0,0);
}

Ball::Ball(double x, double y, double _radius){
	pos = sf::Vector2f(x, y);
	previousPos = sf::Vector2f(x, y);
	radius = _radius;
	acceleration = sf::Vector2f(0,-100);
	color = sf::Color(255,0,0);
}
	
void Ball::update(float dt){
	
	sf::Vector2f temp = pos;
	pos = 2.0f * pos - previousPos + acceleration * dt * dt;
	previousPos = temp;
	
}

float sign(float x){return 2 * (x >= 0) - 1;}

void Ball::show(sf::RenderWindow& window){
	sf::CircleShape circle(radius);
    circle.setFillColor(color);
    circle.setOrigin(radius, radius); // Center the circles
    circle.setPosition(pos);
    window.draw(circle);

}
	
std::vector<sf::Vector2f> Ball::wallIntersection(Wall w){
	sf::Vector2f start = w.getStart();
	sf::Vector2f end = w.getEnd();
	
	float dx = end.x - start.x;
	float dy = end.y - start.y;

	float dr = sqrt(dx*dx + dy*dy);
	float D = (start.x - pos.x) * (end.y - pos.y) - (end.x - pos.x) * (start.y - pos.y);
	
	float delta = radius * radius * dr * dr - D * D;
	
	if (delta == 0) {
		
		float x = (D * dy) / (dr * dr) + pos.x;
		float y = (-D * dx)/ (dr * dr) + pos.y;
		if ((x > std::min(start.x, end.x) && x < std::max(start.x, end.x)) || 
			(y > std::min(start.y, end.y) && x < std::max(start.y, end.y))) { 
		    
			return {sf::Vector2f(x,y)};
		}
	
	} else if (delta > 0) {
		
		float x1 =  (D * dy + sign(dy) * dx * sqrt(delta)) / (dr * dr) + pos.x;
		float y1 = (-D * dx + abs(dy) * sqrt(delta))/ (dr * dr) + pos.y;
		
		float x2 =  (D * dy - sign(dy) * dx * sqrt(delta)) / (dr * dr) + pos.x;
		float y2 = (-D * dx - abs(dy) * sqrt(delta))/ (dr * dr) + pos.y;
		
		if ((x1 > std::min(start.x, end.x) && x1 < std::max(start.x, end.x)) ||
		    (x2 > std::min(start.x, end.x) && x2 < std::max(start.x, end.x)) ||
		    (y1 > std::min(start.y, end.y) && y1 < std::max(start.y, end.y)) ||
		    (y2 > std::min(start.y, end.y) && y2 < std::max(start.y, end.y))) { 
				
				return {sf::Vector2f(x1,y1), sf::Vector2f(x2, y2)};
		}
	
	} 
	
	
	return {};

}

void Ball::wallBounce(Wall w){
	std::vector<sf::Vector2f> points = wallIntersection(w);
	
	if (points.size() > 0) {
		std::cout << "bounce" << std::endl;
		sf::Vector2f normal = w.getNormal();
		sf::Vector2f v = pos - w.getStart();
		
		float s = sign(v.x * normal.x + v.y * normal.y);
		pos = w.getSymetricPoint(pos) + s * 2.0f * float(radius) * normal;
		previousPos = w.getSymetricPoint(previousPos) + s * 2.0f * float(radius) * normal;
	}

}

 
	
Ball::~Ball(){

}
