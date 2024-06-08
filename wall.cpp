#include "wall.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Wall::Wall(float x1, float y1, float x2, float y2){
	start = sf::Vector2f(x1, y1);
	end = sf::Vector2f(x2, y2);
}


void Wall::show(sf::RenderWindow& window){
	sf::Vertex line[] = {start, end};
	window.draw(line, 2, sf::Lines);
}

sf::Vector2f Wall::getNormal() {
	sf::Vector2f normal(end.y - start.y, start.x - end.x);
	float norm = std::sqrt(normal.x * normal.x + normal.y * normal.y);
	return  normal / norm;
}

sf::Vector2f Wall::getSymetricPoint(sf::Vector2f P){
	sf::Vector2f AP = P - start;
	sf::Vector2f N = getNormal();
	float dot_product = AP.x * N.x + AP.y * N.y;

	
	return P - 2 * dot_product * N;

}

Wall::~Wall(){

}
