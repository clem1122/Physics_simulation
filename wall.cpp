#include "wall.h"
#include <SFML/Graphics.hpp>

Wall::Wall(float x1, float y1, float x2, float y2){
	start = sf::Vector2f(x1, y1);
	end = sf::Vector2f(x2, y2);
}


void Wall::show(sf::RenderWindow& window){
	sf::Vertex line[] = {start, end};
	window.draw(line, 2, sf::Lines);
}

Wall::~Wall(){

}
