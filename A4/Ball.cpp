#include "Ball.h"
#include "Random.h"
#include <iostream>


using namespace std;

void Ball::create_ball() {
	static std::uniform_real_distribution<float> distr(0,1);
	r = distr(Random::get())*50;
	x = distr(Random::get())*(700-2*r)+r;
	y = distr(Random::get())*(500-2*r)+r;
	dx = distr(Random::get())*1.6f-0.8f;
	dy = distr(Random::get())*1.6f-0.8f;
	circle.setPosition({x,y});
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
}

void Ball::update() {
	x+=dx;
	y+=dy;
	if (x+dx>700|| x+dx <0) {
		dx = -dx;
	}
	if (y+dy>500|| y+dy <0) {
		dy = -dy;
	}
}


void Ball::draw() {

	circle.setPosition({x-r,y-r});
	window->draw(circle);
	circle.setPosition({x+r,y+r});
}
