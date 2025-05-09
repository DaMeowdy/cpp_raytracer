#include "../include/colour3.h"
Colour3 Colour3::operator*(double scale) const 
{
  double scaled_r = this->colourVector_.X()*scale;
  double scaled_g = this->colourVector_.Y()*scale;
  double scaled_b = this->colourVector_.Z()*scale;

  return {scaled_r, scaled_g, scaled_b};
}
Colour3 operator*(double scale, Colour3& colourVector)
{
  Colour3 scaled_colour_vector = colourVector * scale;
  return scaled_colour_vector;
}
Colour3 Colour3::operator+(const Colour3 otherColour) const 
{
  double added_r = this->colourVector_.X() + otherColour.colourVector_.X();
  double added_g = this->colourVector_.Y() + otherColour.colourVector_.Y();
  double added_b = this->colourVector_.Z() + otherColour.colourVector_.Z();
  return {added_r, added_g, added_b};
}
