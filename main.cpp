#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.h"
#include "wall.h"


void printVector(const sf::Vector2f& vector) {
    std::cout << "(" << vector.x << ", " << vector.y << ")" << std::endl;
}


int main(int argc, char* argv[]) {
	float dt = 0.1;
	int width = 800;
	int height = 600;
	if (argc == 2){dt = std::stof(argv[1]);;} 
	Ball v = Ball(150,400,30);
	Wall w(30, 300, 500, 30);
	Wall down(0, 0, width, 0);
	Wall right(width, 0, width, height);
	Wall left(0, 0, 0, height);
	
	
	sf::RenderWindow window(sf::VideoMode(width, height), "Ball Simulation");
	window.setPosition(sf::Vector2i(100, 100));
	
	sf::View view = window.getDefaultView();
    view.setSize(view.getSize().x, -view.getSize().y); // Invert the y-axis

    // Apply the view to the window
    window.setView(view);
    
	while (window.isOpen()) {
		sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
       	
       	sf::Vector2i mousePos_i= sf::Mouse::getPosition(window);
       	mousePos_i.y = height - mousePos_i.y;
       	sf::Vector2f mousePos(static_cast<float>(mousePos_i.x), static_cast<float>(mousePos_i.y));
       	
		//v.setPos(w.getSymetricPoint(mousePos));
		//v.setPos(mousePos);
		
		v.wallBounce(down);
		v.wallBounce(right);
		v.wallBounce(left);
		v.wallBounce(w);
		
		printVector(v.getPos());
		
		
       	w.show(window);
        v.show(window);
        
        
        // Display the window
        window.display();
        if(dt);
        v.update(dt);
        //printVector(v.getPos());

        // Sleep to control frame rate
        sf::sleep(sf::milliseconds(10));
        window.clear(sf::Color::Black);

	}
	return 0;
}


