#include "../include/interval.h"

bool Interval::Contains(double x) const
{
  double min = this->Min;
  double max = this->Max;
  bool min_is_less_than = min <=x;
  bool is_less_than_max = x <=max;
  bool contains = min_is_less_than&&is_less_than_max;
  return contains;
}
bool Interval::Surrounds(double x) const
{
  double min = this->Min;
  double max = this->Max;
  bool min_is_less_than = min <x;
  bool is_less_than_max = x < max;
  bool surrounds = min_is_less_than&&is_less_than_max;
  return surrounds;
}
double Interval::ClampValue(double inputValue) const 
{
  double min = this->Min;
  double max = this->Max;
  if(Contains(inputValue))
  {
    return inputValue;
  }
  bool input_value_less_than_min = inputValue<min;
  double clamp_value = input_value_less_than_min?min:max;
  return clamp_value;
}
double Interval::ClampValueToInterval(double inputValue, Interval inputInterval)
{

  double min = inputInterval.Min;
  double max = inputInterval.Max;
  if(inputInterval.Contains(inputValue))
  {
    return inputValue;
  }
  bool input_value_less_than_min = inputValue<min;
  double clamp_value = input_value_less_than_min?min:max;
  return clamp_value;
}
Interval Interval::Surrounding(const Interval& a, const Interval& b) {
    return Interval(std::fmin(a.Min, b.Min), std::fmax(a.Max, b.Max));
}
