#include "../include/camera.h"
Camera::Camera(const Point3& inCameraPosition,const Point3& inImagePlaneCentre, double inImageHeight, double inAspectRatio)
{
  // Definition of helper variables
  double viewport_height = 2.0;
  double image_width = inImageHeight*inAspectRatio;
  double viewport_width = viewport_height*inAspectRatio;
  // this is where the fun begins 
  this->cameraCentre_ = inCameraPosition;
  Vec3 lookAtVector = inCameraPosition - inImagePlaneCentre;
  Vec3 viewport_horizontal = Vec3(viewport_width,0.0,0.0);
  Vec3 viewport_vertical = Vec3(0.0,-viewport_height,0.0);
  // setting horizontal and vertical step
  this->horizontalStep_ = viewport_horizontal/image_width;
  this->verticalStep_ = viewport_vertical/inImageHeight;
  // defining viewport ul corner which helps with setting pixel00_
  Vec3 half_viewport_horizontal = (viewport_horizontal/2.0);
  Vec3 half_viewport_vertical = (viewport_vertical/2.0);
  Vec3 viewport_top_left = this->cameraCentre_ + lookAtVector -half_viewport_horizontal - half_viewport_vertical;
  // setting pixel00_
  Vec3 half_horizontal_step = (this->horizontalStep_*0.5);
  Vec3 half_vertical_step = (this->verticalStep_*0.5);
  this->pixel00_ = viewport_top_left + half_horizontal_step + half_vertical_step;
}
Ray Camera::GetRay(double inX, double inY)
{
  Vec3 ray_horizontal_step = (this->horizontalStep_*inX);
  Vec3 ray_vertical_step = (this->verticalStep_*inY); 
  // I do not have a good variable name for the variable below do not judge me :c 
  Vec3 ray_first_equation = this->pixel00_ + ray_horizontal_step + ray_vertical_step;
  Vec3 direction = ray_first_equation-this->cameraCentre_;
  Ray ray = Ray(this->cameraCentre_,direction);
  return ray;
}
