#include <SFML/Graphics.hpp>
#include <iostream>
#include "Letter.h"
#include <vector>

using namespace std;



int main() {
	//variables for the window
	int width = 1920;
	int height = 1080;
	
	//number of falling letter objects created
	int letter_count = 100;

	//the opacity of the screen, lower increases the time letters are on screen, higher is shorter
	uint8_t letter_time = 20;

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
	vector<Letter> letters;
	for (int i = 0; i<letter_count;i++) {
		letters.push_back(Letter(font,&window));
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
