#include <cmath>

//converts polar to cartestian
void polar_to_cartesian(double radius, double theta, double* x, double* y) {
	//gets x and sets it
	*x = radius*cos(theta);
	//gets y and sets it
	*y = radius*sin(theta);
}

//converts cartesian to polar
void cartesian_to_polar(double x, double y, double* radius, double* theta) {
	//gets the radius by the magnitude of vector xy
	*radius = sqrt(x*x+y*y);
	//gets the angle through trig function inverse tan(y/x)
	*theta = atan(y/x);
}
