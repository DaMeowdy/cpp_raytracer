#include "../include/camera.h"
Camera::Camera(double inAspectRatio)
{
  this->viewport_width_ = 2.0;
  this->viewport_height_ = 2.0;
  this->aspect_ratio_ = inAspectRatio;
  this->focal_length_ = 1.0;
  this->origin_={0.0,0.0,0.0};
  this->horizontal_={viewport_width_,0.0,0.0};
  this->vertical_={0.0,viewport_height_,0.0};
  this->lower_left_corner_ = origin_-horizontal_/2-vertical_/2-Vec3(0.0,0.0,focal_length_);

}
double Camera::ViewportWidth() const {
  return this->viewport_width_;
}
double Camera::ViewportHeight() const {
  return this->viewport_height_;
}
double Camera::AspectRatio() const {
  return this->aspect_ratio_;
}
double Camera::FocalLength() const {
  return this->focal_length_;
}
Point3 Camera::Origin() const {
  return this->origin_;
}
Vec3 Camera::Horizontal() const {
  return this->horizontal_;
}
Vec3 Camera::Vertical() const {
  return this->vertical_;
}
Vec3 Camera::LowerLeftCorner() const {
  return this->lower_left_corner_;
}
