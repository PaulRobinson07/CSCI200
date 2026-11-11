#include "Bubble.h"
#include "Random.h"
#include <cmath>

//runs on initiation to make variables for later use
void Bubble::create_ball() {
	//makes a distribution of floats
	static std::uniform_real_distribution<float> distr(0,1);
	
	//generates random values that paone wanted
	r = distr(Random::get())*40+10.0f;
	x = distr(Random::get())*((float)window->getSize().x-2*r)+r;
	y = distr(Random::get())*((float)window->getSize().y-2*r)+r;
	dx = distr(Random::get())*1.6f-0.8f;
	dy = distr(Random::get())*1.6f-0.8f;
	circle.setPosition({x,y});
}

//updates every frame
void Bubble::update() {
	//movement 
	x+=dx;
	y+=dy;

	//checks if the ball will go out of frame next frame in the x direction
	if (x+dx+r>(float)window->getSize().x|| x+dx-r <0) {
		//flips the x direction
		dx = -dx;
	}

	//checks if the ball will go out of frame next frame in the y direction
	if (y+dy+r>(float)window->getSize().y|| y+dy-r <0) {
		//flips the y direction
		dy = -dy;
	}
}

//checks if the mouse was clicked on top of the bubble
bool Bubble::check_clicked(sf::Vector2i pos) {
	if (r>std::sqrt((x-(float)pos.x)*(x-(float)pos.x)+(y-(float)pos.y)*(y-(float)pos.y))) {
		return true;
	}
	return false;
}

//draws the bubble every game with the origin of the circle taken into account
void Bubble::draw() {
	circle.setPosition({x-r,y-r});
	window->draw(circle);
	circle.setPosition({x+r,y+r});
}
