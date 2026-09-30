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
	//makes the variables to enter into the equations
	double moles;
	double temperature;
	double volume;

	cout << "Give some values to find the pressure of a system" << endl;
	//prompts the user for the variables

	//stores them
	cout << "Give the moles: ";
	cin >> moles;
	cout << "Give the temperature (Kelvin): ";
	cin >> temperature;
	cout << "Give the volume (Liters): ";
	cin >> volume;
	
	//gets the pressure and tells the user it
	double pressure = get_pressure(moles,temperature,volume);
	cout << "The pressure using ideal gas law is: " << pressure << "atm" << endl;

	//makes and gets the radius of the sphere from the user
	double radius;
	cout << "Give the radius of the sphere who's volume you are needed to compute";
	cin >> radius;

	//computes and returns the volume of the sphere
	double volume_of_sphere = get_sphere_volume(radius);
	cout << "The volume of a sphere given radius " << radius << " is: " << volume_of_sphere << endl;

	return 0;
}

