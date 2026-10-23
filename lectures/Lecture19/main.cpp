#include <iostream>
#include "Course.h"
#include <vector>

using namespace std;
int main() {
	//makes a list of classes
	vector<Course> catalog;
	//adds two courses to the list
	catalog.push_back(Course("CSCI 200",10));
	catalog.push_back(Course("MATH 112", 10));

	//registers students for class one
	catalog.at(0).registerStudent();
	catalog.at(0).registerStudent();

	//registers and removes some kids from class two
	catalog.at(1).registerStudent();
	catalog.at(1).withdrawStudent();
	catalog.at(1).withdrawStudent();

	//prints the names of the classes
	string class_1_name = catalog.at(0).getTitle();
	string class_2_name = catalog.at(1).getTitle();
	cout << "Class one's name is: " << class_1_name << endl;
	cout << "Class two's name is: " << class_2_name << endl;

	//prints the number of kids in the classes
	int enrollment_one =  catalog.at(0).getEnrollment();
	int enrollment_two=  catalog.at(1).getEnrollment();
	cout << "Class one's enrollment is: " << enrollment_one << " kids" <<  endl;
	cout << "Class two's enrollment is: " << enrollment_two << " kids" <<  endl;

    return 0;
}
