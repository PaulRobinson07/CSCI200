#include <string>
#include "Course.h"
//gets the title of the class
std::string Course::getTitle() {
	return title;
}

//gets the enrollment of the class
int Course::getEnrollment(){
	return enrollment;
}

//registers a kid for the class
void Course::registerStudent() {
	enrollment++;
}

//if there are still kids in the class, remove one from it
void Course::withdrawStudent() {
	if (enrollment>0) {
		enrollment--;
	}
}

