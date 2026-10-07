/* CSCI 200: Lab l1A
 *
 * Author: Paul Rayford Robinson
 *
 *
 */

#include <iostream>
#include <random>

using namespace std;

int get_quartile(float upper,float lower, float num) {
	float range = upper-lower;
	float quarter = range/4;
	for (int i=0;i<4;i++) {
		if (num<=lower+quarter*i) {
			return i;
		}
	}
	return 4;
}

int generate(float min, float max) {
	char answer;
	cout << "Do you want to generate a number within those bounds? (Y/N)";
	cin >> answer;
	if (answer == 'N') {
		return 1;
	}

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> disrib(min,max);
	float random_num = disrib(gen);
	cout << "A random number is: " << random_num << endl;

	int a = get_quartile(max,min,random_num);

	cout << "It is in the " << a << " quartile " << endl;
	return 0;
}

int main() {
	random_device rd;
	mt19937 gen(rd());

	float max;
	float min;

	cout << "Enter the maximum value: ";
	cin >> max;
	cout << "Enter the minimum value: ";
	cin >> min;
	int a = 0;
	while (a==0){
		a = generate(min,max);
	}
	return 0;
}
