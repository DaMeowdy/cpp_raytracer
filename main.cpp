//
// Coded by Madison Sutton 21985164 
// using Richard Skarbez code as inspiration
//
#include <fstream>
#include <iostream>
#include "include/camera.h"
#include "include/colour3.h"
#include "include/ray.h"
// yoinking the progress bar code. will rewrite and make pretty later
void updateProgressBar(int rowsDone, int imageHeight){
  // To get to a percentage first subtract rowsDone from the height, because rowsDone is descending,
  float percentage = ((float)(imageHeight - rowsDone) / imageHeight) * 100;
  std::cout << "[";
  for(int i = 0; i < 50; i++){
      if(i < (percentage / 2)){ // percentage needs to be divided by 2 because the percentage bar is 50 width
          std::cout << "#";
      }else{
          std::cout << " ";
      }
  }
    std::cout << "] " << percentage << "% \r" << std::flush;
}


Colour3 rayColor(const Ray& r) {
  Vec3 unit_direction = r.Direction().UnitVector();
  double lerp_factor = 0.5 * (unit_direction.Y() + 1.0);
  Colour3 white = Colour3(1.0, 1.0, 1.0);
  Colour3 blue = Colour3(0.5, 0.7, 1.0);
  return ((1.0 - lerp_factor) * white) + (lerp_factor * blue);
}

int main() {
  // image size definition, is temporary as it will be handled by the renderer in the future
  int image_width = 512;
  int image_height = 512;
  std::string out_file_name = "image_21985164.ppm";
  std::ofstream out_file(out_file_name);
  if(!out_file.is_open())
  {
    std::cerr << "Error : unable to open file :C" << std::endl;
    return 1;
  }
  Camera camera = Camera();
  // rendering
  out_file << "P3\n" << image_width << " " << image_height << "\n255\n";
  for(int i = 0; i<image_height; ++i)
  {
    for(int j = 0; j<image_width; ++j)
    {
      Ray ray = camera.GetRay(j, i);
      Colour3 pixel_colour = rayColor(ray);
      out_file << pixel_colour.R() << ' ' <<pixel_colour.G() << ' ' << pixel_colour.B()<<'\n';

    }
    updateProgressBar(i,image_height);
  }
  out_file.close();
  return 0;
}
