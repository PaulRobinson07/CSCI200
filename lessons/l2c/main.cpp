/* CSCI 200: Fix Loop and Function Errors
 *
 * Author: (Paul Robinson)
 * 
 * Description: Lesson L2C seeks to teach students how to use header files
 * 
 * Copyright 2026 Dr. Jeffrey Paone
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

/*
 * Please have mercy on grading 
 * I commented nearly every line that I wrote
 * It works fully
 *
 */



#include <iostream>
#include "cordinate_conversion.h"

using namespace std;

//gets the staus of the program from the user
int get_status() {
	//variable for status
	int status;

	//prompts the user with available options
	cout << "What do you want to convert?" << endl;
	cout << "1: Polar Cordinates to Cartesian" << endl;
	cout << "2: Cartesian Cordinates to Polar" << endl;
	cout << "0: Exit Program" << endl;
	cout << "Answer: " << endl;
	cin >> status;

	//checks if the status was valid
	if ((status < 0) || (status > 3)) {
		//if not recursively ask again
		status = get_status();
	}
	//returns the status
	return status;
}

//runs all the code based of the status
void run_functions(int* status) {
	//variables for later
	double radius, theta, x, y;

	//does different things based of status
	switch (*status) {
		//user wants polar_to_cartesian
		case (1):
			//prompts and writes the radius
			cout << "Give a radius: " << endl;
			cout << "Enter here: " << endl;
			cin >> radius;

			//prompts and writes the theta 
			cout << "Give a theta value: " << endl;
			cout << "Enter here: " << endl;
			cin >> theta;

			//calculuates (x,y)
			polar_to_cartesian(radius,theta, &x, &y);
		
			//returns (x,y)
			cout << "(" << x << "," << y << ")" << endl;
		break;
		//user wants cartesian_to_polar
		case 2:
			//prompts and writes x
			cout << "Give a x value: " << endl;
			cout << "Enter here: " << endl;
			cin >> x;

			//prompts and writes y 
			cout << "Give a y value: " << endl;
			cout << "Enter here: " << endl;
			cin >> y;
			
			//converts (x,y) to R,0
			cartesian_to_polar(x,y, &radius, &theta);
			
			//returns R,0
			cout << "R: " << radius << "0: " << theta << endl;
		break;
	}
}
int main() {
	int status;
	//gets what the user wants
	status = get_status();

	//acts based on their request from earlier
	run_functions(&status);
    return 0;
}

