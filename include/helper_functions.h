#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_HELPER_FUNCTIONS_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_HELPER_FUNCTIONS_H
#include <cmath>
#include <iostream>
#include <optional>
#include <random>
const double PI_ = 3.1415926535897932385;
const double INFINITY_ = std::numeric_limits<double>::infinity();
double DegreesToRadians(double degrees);
double RadiansToDegrees(double Radians);
double RandomDouble(double minimum, double maximum);
double RandomDouble0to1();
int RandomInt(int minimum, int maximum);
int RandomInt0to255();

#endif
