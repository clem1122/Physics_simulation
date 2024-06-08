#include "ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include "wall.h"
#include "cmath"

float getRandomFloat(float min, float max) {
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_real_distribution<float> dis(min, max); // Define the range

    return dis(gen);
}

int getRandomInt(int min, int max) {
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> dis(min, max); // Define the range

    return dis(gen);
}

Ball::Ball(){
	pos =  sf::Vector2f(getRandomFloat(0.0f, 800.0f), getRandomFloat(0.0f, 600.0f));
	previousPos = pos;
	radius = double(getRandomFloat(10.0f, 40.0f));
	color = sf::Color(getRandomInt(0, 255), getRandomInt(0, 255), getRandomInt(0, 255));
	acceleration = sf::Vector2f(0,-100);
}

Ball::Ball(sf::Vector2f _pos, double _radius){
	pos = _pos;
	previousPos = _pos;
	radius = _radius;
	acceleration = sf::Vector2f(0,-100);
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
		sf::Vector2f normal = w.getNormal();
		sf::Vector2f v = pos - w.getStart();
		
		float s = sign(v.x * normal.x + v.y * normal.y);
		pos = w.getSymetricPoint(pos) + s * 2.0f * float(radius) * normal;
		previousPos = w.getSymetricPoint(previousPos) + s * 2.0f * float(radius) * normal;
	}

}

 
	
Ball::~Ball(){

}
