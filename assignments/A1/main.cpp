/* CSCI 200: Lab A1 
 *
 * Author: Paul Rayford Robinson
 *
 *
 */

#include <iostream>
#include <string>

using namespace std;

bool is_valid(int number) {
	string number_string = to_string(number);	
	char c1 = number_string[0];
	char c2 = number_string[1];
	return true;
}


int main() {

	int num1;
	cout << "Give a number: ";
	cin >> num1;

	cout << "Your number was: " << num1 << endl;

	return 0;
}

