//
// Coded by Madison Sutton 21985164 
// using Richard Skarbez code as inspiration
//
#include <fstream>
#include <iostream>
#include "include/camera.h"
#include "include/colour3.h"
#include "include/ray.h"
#include "include/renderer.h"
int main() {
  // image size definition, is temporary as it will be handled by the renderer in the future
  Renderer renderer = Renderer();
  renderer.Render();
  return 0;
}
