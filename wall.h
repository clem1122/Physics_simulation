#pragma once
#include <SFML/Graphics.hpp>


class Wall{
private:
	sf::Vector2f start;
	sf::Vector2f end;
	
public:
	Wall(float x1, float y1, float x2, float y2);
	
	void show(sf::RenderWindow& window);
	
	sf::Vector2f getStart(){return start;}
	sf::Vector2f getEnd(){return end;}	
	
	sf::Vector2f getNormal();

	sf::Vector2f getSymetricPoint(sf::Vector2f P);

	~Wall();
};
