#include "../include/vec3.h"
double Vec3::X() const 
{
  return this->x_;
}
double Vec3::Y() const 
{
  return this->y_;
}
double Vec3::Z() const
{
  return this->z_;
}

Vec3 Vec3::operator-()const
{
  return {*this};
}
Vec3 Vec3::operator-(const Vec3 otherVector) const
{
  double subtracted_x = this->X() - otherVector.X();
  double subtracted_y = this->Y() - otherVector.Y();
  double subtracted_z = this->Z() - otherVector.Z();
  Vec3 subtracted_vector = {subtracted_x, subtracted_y, subtracted_z};
  return subtracted_vector;
}
Vec3 Vec3::operator+(const Vec3 otherVector) const
{
  double added_x = this->X() + otherVector.X();
  double added_y = this->Y() + otherVector.Y();
  double added_z = this->Z() + otherVector.Z();
  Vec3 added_vector = {added_x, added_y, added_z};
  return added_vector;
}
Vec3 Vec3::operator*(double scale) const
{
  double scaled_x = this->X() * scale;
  double scaled_y = this->Y() * scale;
  double scaled_z = this->Z() * scale;
  Vec3 scaled_vector = {scaled_x, scaled_y, scaled_z};
  return scaled_vector;
}
Vec3 Vec3::operator/(double scale) const
{
  double scale_value = (1/scale);
  Vec3 divided_vector =  *this * scale_value;
  return divided_vector;
}
Vec3 operator*(double scale, const Vec3& otherVector)
{
  Vec3 scaled_vector = otherVector * scale;
  return scaled_vector;
}
Vec3 operator/(double scale, const Vec3& otherVector)
{
  double scale_value = (1/scale);
  Vec3 divided_vector = otherVector * scale;
  return divided_vector;
}
Vec3& Vec3::operator+=(const Vec3& inVector)
{
  this->x_ += inVector.X();
  this->y_ += inVector.Y();
  this->z_ += inVector.Z();
  return *this;
}
Vec3& Vec3::operator*=(double scale)
{
  this->x_ *= scale;
  this->y_ *= scale;
  this->z_ *= scale;
  return *this;
}
Vec3& Vec3::operator/=(double scale)
{
  double scale_value = (1/scale);
  return *this *= scale_value;
}

Vec3 Vec3::operator*(const Vec3 secondVector) const
{
  double scaled_x = this->X() * secondVector.X();
  double scaled_y = this->Y() * secondVector.Y();
  double scaled_z = this->Z() * secondVector.Z();
  Vec3 scaled_vector = {scaled_x, scaled_y, scaled_z};
  return scaled_vector;
}

Vec3 operator*(Vec3& firstVector,Vec3& secondVector)
{
  Vec3 scaled_vector = firstVector*secondVector;
  return scaled_vector;
}



std::ostream& operator<<(std::ostream outputStream,const Vec3& vector){
  return outputStream << vector.X() << ' ' << vector.Y() << ' ' << vector.Z();
}
double Vec3::Dot(const Vec3& otherVector) const
{
  double x_product = this->X()*otherVector.X();
  double y_product= this->Y()*otherVector.Y();
  double z_product = this->Z()*otherVector.Z();
  double dot_product = x_product+y_product+z_product;
  return dot_product;
}
Vec3 Vec3::Cross(const Vec3 otherVector) const
{
  double cross_x = this->Y()*otherVector.Z()-this->Z()*otherVector.Y();
  double cross_y = this->Z()*otherVector.X()-this->X()*otherVector.Z();
  double cross_z = this->X()*otherVector.Y()-this->Y()*otherVector.X();
  Vec3 cross_vector = {cross_x, cross_y, cross_z};
  return cross_vector;
}
double Vec3::Length_Squared() const
{
  double squared_x = this->X()*this->X();
  double squared_y = this->Y()*this->Y();
  double squared_z = this->Z()*this->Z();
  double squared_length = squared_x+squared_y+squared_z;
  return squared_length;
}
double Vec3::Length() const
{
  double squared_length = this->Length_Squared();
  double length = sqrt(squared_length);
  return length; 
}
Vec3 Vec3::UnitVector() const
{
  double vector_length = Length();
  double unit_x = this->X()/vector_length;
  double unit_y = this->Y()/vector_length;
  double unit_z = this->Z()/vector_length;
  return {unit_x, unit_y,unit_z};
}
bool Vec3::NearZero(double epsilon) const
{
  bool x_less_than_epsilon = (fabs(this->X())<epsilon);
  bool y_less_than_epsilon = (fabs(this->Y())<epsilon);
  bool z_less_than_epsilon = (fabs(this->Z())<epsilon);
  bool near_zero = x_less_than_epsilon && y_less_than_epsilon && z_less_than_epsilon;
  return near_zero;
}
Vec3 Vec3::ReflectionAboutNormalVector(const Vec3& normalVector)const
{
  Vec3 self = *this;
  double doubled_dot = (2*self.Dot(normalVector));
  Vec3 normal_vector_by_doubled_dot = (normalVector*doubled_dot);
  return self - normal_vector_by_doubled_dot;
}
Vec3 Vec3::RefractionAboutNormalVector(const Vec3& normalVector, double refractiveIndexRatio) const
{
  Vec3 self = *this;
  double cosine_theta = fmin(-self.Dot(normalVector), 1.0);
  Vec3 perpendicular_component = (self + (normalVector*cosine_theta)) * refractiveIndexRatio;
  Vec3 parallel_component = normalVector * -sqrt(fabs(1.0-perpendicular_component.Length_Squared()));
  return perpendicular_component + parallel_component;
}
Vec3 Vec3::Random0to1()
{
  Vec3 random_vector;
  double random_x = RandomDouble0to1();
  double random_y = RandomDouble0to1();
  double random_z = RandomDouble0to1();
  random_vector = {random_x, random_y, random_z};
  return random_vector;
}
Vec3 Vec3::RandomInRange(double minimum, double maximum)
{
  Vec3 random_vector;
  double random_x = RandomDouble(minimum, maximum);
  double random_y = RandomDouble(minimum, maximum);
  double random_z = RandomDouble(minimum, maximum);
  random_vector = {random_x, random_y, random_z};
  return random_vector;
}
Vec3 Vec3::RandomInUnitSphere()
{
  Vec3 random_vector;
  while(true)
  {
    random_vector = RandomInRange(-1,1);
    if(random_vector.Length_Squared()<1)
      return random_vector;
  }
}
Vec3 Vec3::RandomInUnitDisk()
{
  Vec3 random_vector;
  while(true)
  {
    random_vector = {RandomDouble(-1,1), RandomDouble(-1,1),0};
    if(random_vector.Length_Squared()<1)
      return random_vector;
  }
}
Vec3 Vec3::RandomUnitVector()
{
  Vec3 random_vector = RandomInUnitSphere();
  Vec3 random_unit_vector = random_vector.UnitVector();
  return random_unit_vector;
}
Vec3 Vec3::RandomOnHemisphere(const Vec3& normalVector)
{
  Vec3 random_unit_vector = RandomUnitVector();
  bool ternary_condition = (random_unit_vector.Dot(normalVector)>0.0);
  Vec3 ternary_output = ternary_condition ? random_unit_vector : -random_unit_vector;
  return ternary_output;
}
double Vec3::operator[](int i) const {
    switch (i) {
        case 0: return this->x_;
        case 1: return this->y_;
        case 2: return this->z_;
        default: throw std::out_of_range("Vec3 subscript out of range");
    }
}

double& Vec3::operator[](int i) {
    switch (i) {
        case 0: return this->x_;
        case 1: return this->y_;
        case 2: return this->z_;
        default: throw std::out_of_range("Vec3 subscript out of range");
    }
}
