#include "../include/helper_functions.h"

double DegreesToRadians(double degrees)
{
  double radian_conversion = (degrees*PI_) /180.0;
  return radian_conversion;
}
double RadiansToDegrees(double Radians)
{
  double degree_conversion = (Radians*180.0) / PI_;
  return degree_conversion;
}
double RandomDouble(double minimum, double maximum)
{
  std::random_device random_device;
  thread_local static std::mt19937 generator(random_device());
  std::uniform_real_distribution<double> distribution(minimum, maximum);
  double random_double = distribution(generator);
  return random_double;
}
double RandomDouble0to1()
{
  double random_double_0to1 = RandomDouble(0.0, 1.0);
  return random_double_0to1;
}
int RandomInt(int minimum, int maximum)
{
  std::random_device random_device;
  thread_local static std::mt19937 generator(random_device());
  std::uniform_int_distribution<int> distribution(minimum, maximum);
  int random_int = distribution(generator);
  return random_int;
}
int RandomInt0to255()
{
  int random_int_0to255 = RandomInt(0,255);
  return random_int_0to255;
}
