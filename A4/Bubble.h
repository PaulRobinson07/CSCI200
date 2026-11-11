#define BUBBlE_H
#ifndef BUBBLE_H

#include <SFML/Graphics.hpp>


class Bubble {
private:
//variables for movement
float x;
float y;
float dx;
float dy;
float r;

//the actual circle
sf::CircleShape circle;

//used to draw the circle
sf::RenderWindow *window;

void create_ball();

public:
//runs on creation to update all variables
Bubble(sf::RenderWindow *w, sf::Color color) {
	window = w;
	create_ball();
	circle.setRadius(r);
	circle.setFillColor(color);
}

//@brief draws the circle
void draw();

//@brief updates the circle
void update();

//@brief checks if the mouse clicked the circle given a {int,int}
bool check_clicked(sf::Vector2i pos);


};

#endif
