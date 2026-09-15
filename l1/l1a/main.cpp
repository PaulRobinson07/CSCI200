/* CSCI 200: Lab l1A
 *
 * Author: Paul Rayford Robinson
 *
 *
 */

#include <iostream>
#include <cmath>

//uses the ideal gas law to get pressure in atm if temperature is in Kelvin and volume is in Liters.
double get_pressure(double moles, double temperature, double volume) {
	double pressure = (moles*temperature*0.08206)/volume;
	return pressure;
}

//gets the volume of a sphere given its radius
double get_sphere_volume(double radius) {
	return pow(radius, 3)* std::acos(-1.0)*4.0/3.0;
}

using namespace std;

int main() {

	double pressure = get_pressure(2.5,298,5.0);
	
	cout << "The pressure using ideal gas law is: " << pressure << endl;
	
	double volume = get_sphere_volume(5.0);
	
	cout << "The volume of a sphere given radius 5 is: " << volume << endl;

	return 0;
}

