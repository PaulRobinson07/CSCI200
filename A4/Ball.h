#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>


class Ball {
private:
float x;
float y;
float r;
float dx;
float dy;
sf::CircleShape circle;
sf::RenderWindow *window;

void create_ball();

public:
Ball(sf::RenderWindow *w) {
	window = w;
	create_ball();
	circle.setRadius(r);
	circle.setFillColor(sf::Color::Red);
}

void draw();

void update();


};




#endif
