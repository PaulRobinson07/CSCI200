#include <SFML/Graphics.hpp>
#include "Bubble.h"
#include "Random.h"


//array of colors that can be used for the bubbles
sf::Color colors[] = {
	sf::Color::Red,
	sf::Color::Blue,
	sf::Color::Magenta,
	sf::Color::White,
	sf::Color::Yellow,
	sf::Color::Green
};

//picks a random color for the bubble
sf::Color pick_color() {
	//makes the distribution
	std::uniform_int_distribution<int> distr(0,5);

	//picks and returns the color
	sf::Color color = colors[distr(Random::get())];
	return color;
}

//variables for the window size
const unsigned int WIDTH = 500;
const unsigned int HEIGHT= 500;

//number of falling letter objects created
const int BUBBLE_STARTING_COUNT = 5;

int main() {
    //creates the window
    sf::Vector2u windowSize(WIDTH, HEIGHT);
    sf::RenderWindow window( sf::VideoMode( windowSize ), "Bubbles Program" );

	//makes and start a clock for rendering only every 1/60th a second
	sf::Clock clock;

	//stores bubbles
	std::vector<Bubble> bubbles;

	//makes bubbles at the start of the program
	for (int i = 0; i<BUBBLE_STARTING_COUNT;i++) {
		sf::Color color = pick_color();
		bubbles.push_back(Bubble(&window, color));
	}
	sf::Vector2i mousePos;


    // while the window is open
    while( window.isOpen() ) {
	
		//if it's time to display a new frame
		if (clock.getElapsedTime() >= sf::seconds(1.f/60.f)) {
			//draws the background window
			window.clear();

			//updates all bubbles
			for (size_t i=0; i<bubbles.size(); i++) {
				bubbles.at(i).draw();
				bubbles.at(i).update();
			}
			//displays content of the window
			window.display();
			
			//restart the frametimer
			clock.restart();
		}
		
		//checks for events
        while( const std::optional event = window.pollEvent() ) {
            // if event type corresponds to pressing window X
            if( event->is<sf::Event::Closed>() ) {
                // tell the window to close
                window.close();
            }

			//checks for keycodes
			//XXX this is where all keyboard functionality originates
			if (const sf::Event::KeyPressed* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				//if the keycode is the space bar and there are less than 10 bubbles
				if( keyPressed->code == sf::Keyboard::Key::Space && bubbles.size()<10 ) {
					//makes a new bubble
					sf::Color color = pick_color();
					bubbles.push_back(Bubble(&window, color));
				}
				//if the keyboard has the Q or Escape key pressed
				if( keyPressed->code == sf::Keyboard::Key::Q || keyPressed->code == sf::Keyboard::Key::Escape) {
					//close the window
                	window.close();
				}
			}
			//code for checking mousepressees
			if (const sf::Event::MouseButtonPressed* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
				//if left click
				if (mousePressed->button == sf::Mouse::Button::Left) {
					// Get click coordinates relative to the window
					mousePos = mousePressed->position;
					//checks for every bubble if it within the mouse press
					for (size_t i=0; i<bubbles.size(); i++) {
						bool delete_current = bubbles.at(i).check_clicked(mousePos);
						if (delete_current) {
							//removes the current bubble
							bubbles.erase(bubbles.begin()+(int)i);
						}
					}
				}
			}
		}
	}
    return 0;
}
