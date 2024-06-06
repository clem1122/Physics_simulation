#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.h"


void printVector(const sf::Vector2f& vector) {
    std::cout << "(" << vector.x << ", " << vector.y << ")" << std::endl;
}


int main(int argc, char* argv[]) {
	float dt = 0.1;
	if (argc == 2){dt = std::stof(argv[1]);;} 
	Ball v = Ball(150,100,30);
	
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Ball Simulation");
	window.setPosition(sf::Vector2i(100, 100));
	
	sf::View view = window.getDefaultView();
    view.setSize(view.getSize().x, -view.getSize().y); // Invert the y-axis

    // Apply the view to the window
    window.setView(view);
	sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(0, 30)),          // Start point of the line (left)
        sf::Vertex(sf::Vector2f(800, 30))         // End point of the line (right)
    };
    
	while (window.isOpen()) {
		sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
       
        window.draw(line, 2, sf::Lines);
        double radius = v.getRadius();
        sf::CircleShape circle(radius);
        circle.setFillColor(sf::Color::Red);
        
        circle.setOrigin(radius, radius); // Center the circles
        circle.setPosition(v.getPos());
        window.draw(circle);
        
        // Display the window
        window.display();
        v.update(dt);
        printVector(v.getPos());

        // Sleep to control frame rate
        sf::sleep(sf::milliseconds(10));
        window.clear(sf::Color::Black);

	}
	return 0;
}


