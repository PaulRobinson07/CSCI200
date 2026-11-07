#ifndef LETTER_H
#define LETTER_H

#include <SFML/Graphics.hpp>



//class for letters
class Letter {
private:
//private variables
float x;
float y;

//current row
int last_row;

//text variables
char c;
sf::Text text;

//reference to the window
sf::RenderWindow *window;

//@brief picks a random char to display
void pick_letter();

//@brief picks a random position for the letter to be
void set_position();

public:
//constructor
Letter(sf::Font &f, sf::RenderWindow *w) : text(f) {
	//makes a random characteristics
	pick_letter();
	set_position();

	//reference to window
	window = w;

	//sets up the character text
	text.setFont(f);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Green);
}

//@brief updates the character
void update();

//@brief draws the character
void draw();

};


#endif
