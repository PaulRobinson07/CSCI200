#ifndef BOX_H
#define BOX_H

/*
 * @brief stores the dimensions of a box and can print it out
 *
 */
class Box {
public:
	float length;
	float depth;
	float height;
	
	//@brief prints the dimensions of the box
	void print_dimensions();
};



#endif
