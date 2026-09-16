/* CSCI 200: Lab A1 
 *
 * Author: Paul Rayford Robinson
 *
 *
 */

#include <iostream>
#include <random>


/*
 * Sorry for sloppy implementation
 * I was a bit confused and didn't understand this assignment
 * I also took a lot of shortcuts and should've used a header file for all of the functions
 * Also sorry that there is no comments
 *
 */

using namespace std;

bool is_valid(int number) {
	int valid_nums[] = {11,12,13,14,15,16,22,23,24,25,26,33,34,35,36,44,45,46,55,56};
	for (int i =0;i<19;i++) {
		if (number == valid_nums[i]) {
			return true;
		}

	}
	return false;
}

int get_num() {
	int num1;
	cout << "Give a number to annouce: ";
	cin >> num1;

	if (is_valid(num1)) {
		cout << "Your number was: " << num1 << endl;
	}
	else {
		num1 = get_num();
	}
	return num1;
}

int get_random() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distrib(1,6);
	int roll= distrib(gen)*10+distrib(gen);
	return roll;

}

int get_bluff() {
	int bluff;
	cout << "Is the user bluffing? (1=yes, 0=no)";
	cin >> bluff;
	if (bluff!= 0 && bluff!=1) {
		bluff = get_bluff();
	}
	return bluff;
}

bool check_bluff(int actual, int typed) {
	if (actual==typed) {
		cout << "They were bluffing!" << endl;
		return false;
	}
	cout << "They weren't bluffing!" << endl;
	return true;
}

int main() {
	int random_roll = get_random();
	cout << "Your roll number is: " << random_roll << endl;
	int user_num = get_num();
	cout << user_num << endl;
	int a = get_bluff();
	bool b = check_bluff(random_roll,user_num);
	if (a == b) {
		cout << "You guessed their bluff";
	}
	else {
		cout << "You didn't guess their bluff";
	}
	return 0;
}

