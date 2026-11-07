#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"

using namespace std;



int main() {
	//variables for the window
	int width = 700;
	int height = 500;
	
	//number of falling letter objects created
	int letter_count = 1;

	//the opacity of the screen, lower increases the time letters are on screen, higher is shorter
	uint8_t letter_time = 15;

    // create a window
    sf::Vector2u windowSize((unsigned int)width, (unsigned int)height);
    sf::RenderWindow window( sf::VideoMode( windowSize ), "SFML Test" );

	//creates the font for the letters
	sf::Font font;

	//tries to open the file and if it can't the program exists
	if (!font.openFromFile("CourierPrime-Regular.ttf")) {
		std::cerr << "Couldn't load fonts" << endl;
		return -1;
	}

	//background rectangle 
	sf::RectangleShape rect({(float)width,(float)height}); 
	rect.setFillColor(sf::Color(0,0,0,letter_time));

	//the letters that are falling initialization
	vector<Ball> letters;
	for (int i = 0; i<letter_count;i++) {
		letters.push_back(Ball(&window));
	}

    // while the window is open
    while( window.isOpen() ) {
		
		//updates and draws all letters
		for (size_t i=0; i<letters.size(); i++) {
			letters.at(i).update();
			letters.at(i).draw();
		}
		//draws the background window
		window.draw(rect);
		
		//displays content of the window
        window.display();

		//checks for events
        while( const std::optional event = window.pollEvent() ) {
            // if event type corresponds to pressing window X
            if( event->is<sf::Event::Closed>() ) {
                // tell the window to close
                window.close();
            }
        }
    }
    return 0;
}
