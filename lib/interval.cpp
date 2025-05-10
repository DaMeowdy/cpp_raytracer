#include "../include/interval.h"
double Interval::Size() const
{
  double min = this->Min();
  double max = this->Max();
  double interval_size = max-min;
  return interval_size;
}
bool Interval::Contains(double testValue) const
{
  double min = this->Min();
  double max = this->Max();
  bool min_is_less_than = min <=testValue;
  bool is_less_than_max = testValue <=max;
  bool contains = min_is_less_than&&is_less_than_max;
  return contains;
}
bool Interval::Surrounds(double testValue) const
{
  double min = this->Min();
  double max = this->Max();
  bool min_is_less_than = min <testValue;
  bool is_less_than_max = testValue < max;
  bool surrounds = min_is_less_than&&is_less_than_max;
  return surrounds;
}
double Interval::ClampValue(double inputValue) const 
{
  double min = this->Min();
  double max = this->Max();
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

  double min = inputInterval.Min();
  double max = inputInterval.Max();
  if(inputInterval.Contains(inputValue))
  {
    return inputValue;
  }
  bool input_value_less_than_min = inputValue<min;
  double clamp_value = input_value_less_than_min?min:max;
  return clamp_value;
}
const Interval Interval::emptyInterval= Interval(+INFINITY_,-INFINITY_);
const Interval Interval::infiniteInterval = Interval(-INFINITY_, +INFINITY_);
