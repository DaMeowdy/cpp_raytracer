#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_INTERVAL_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_INTERVAL_H
#include "helper_functions.h"
class Interval
{
  public:
  double Min, Max;
  Interval(): Min(+INFINITY_),Max(-INFINITY_){}
  Interval(double inMin, double inMax):Min(inMin),Max(inMax){}

  bool Contains(double x) const;
  bool Surrounds(double x) const;
  double ClampValue(double inputValue) const;
  static const Interval empty_interval,infinite_interval;
  static Interval Surrounding(const Interval& a, const Interval& b);
  static double ClampValueToInterval(double inputValue, Interval inputInterval);
};
const static Interval empty_interval {+INFINITY_,-INFINITY_};
const static Interval infinite_interval {-INFINITY_, +INFINITY_};

#endif
