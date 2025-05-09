#ifndef CSE3PSD_ASSIGNMENT3_INTERVAL_H
#define CSE3PSD_ASSIGNMENT3_INTERVAL_H
#include "helper_functions.h"
class Interval
{
  public: 
  Interval(double inMin, double inMax): min_(inMin), max_(inMax) {};
  double Min() const {return this->min_;}
  double Max() const {return this->max_;}
  double Size() const;
  bool Contains(double testValue) const;
  bool Surrounds(double testValue) const;
  double ClampValue(double inputValue) const;
  static double ClampValueToInterval(double inputValue, Interval inputInterval);
  static const Interval emptyInterval;
  static const Interval infiniteInterval;
  private:
  double min_ {+INFINITY_};
  double max_ {-INFINITY_};

};

#endif
