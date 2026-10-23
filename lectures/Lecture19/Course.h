#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

/*
 *
 *@breif takes in a name of a class and an enrollment class
 *
 *
 */
class Course {
public: 
	//public variables
	string title;
	int enrollment;
	//@breif takes in the title of class and the enrollment count
	Course(string title_input, int enrollment_input) {
		title = title_input;
		enrollment = enrollment_input;
	}
	string getTitle();
	int getEnrollment();
	void registerStudent();
	void withdrawStudent();
};





#endif
