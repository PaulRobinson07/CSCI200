#include "Letter.h"
#include "Random.h"


//@brief picks a random position for the character
void Letter::set_position() {
	//gets the random generator
	static std::uniform_real_distribution<float> distr(0,1);

	//generates a y value
	y = distr(Random::get())*-1080.0f;

	//generates a x value
	x = (float)((int)(distr(Random::get())*1920)/30)*30;

	//resets the row index
	last_row = -999;
}

//@brief picks a random character for the letter
void Letter::pick_letter() {
	//calls the random generator
	static std::uniform_int_distribution<int> distr(' ','~');

	//picks and sets the character
	c = (char)distr(Random::get());
	text.setString(c);
}

//@brief updates the character
void Letter::update() {
	//moves y a bit
	//change to speed up or slow down the decent
	y+=0.25f;

	//if the y is off screen reset it
	if (y>1080) {
		set_position();
		pick_letter();
	}

	//updates the current row for y to snap it to a grid
	int current_row = static_cast<int>(y) / 30;
    
    //if a new row is picked update the variables for position
    if (current_row != last_row) {
        last_row = current_row;
        float snapped_y = static_cast<float>(current_row * 30);
        text.setPosition({x, snapped_y});
    }
}

//@brief draws the character
void Letter::draw() {
	window->draw(text);
}
