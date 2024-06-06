#pragma once
#include <SFML/Graphics.hpp>

class Wall{
private:
	sf::Vector2f start;
	sf::Vector2f end;
	
public:
	Wall(float x1, float y1, float x2, float y2);
	
	void show(sf::RenderWindow& window);

	~Wall();
};
