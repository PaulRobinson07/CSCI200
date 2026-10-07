#ifndef CORDNIATE_CONVERSTION_H
#define CORDNIATE_CONVERSTION_H

//converts polar to cartesian
void polar_to_cartesian(double radius, double theta, double* x, double* y);

//converts cartesian to polar
void cartesian_to_polar(double x, double y, double* radius, double* theta);

#endif 
