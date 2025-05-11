#include "../include/progress_bar.h"
#include <iostream>

void ProgressBar::UpdateProgressBar(int rowsDone, int imageHeight)
{
  float progress_bar_status_as_percentage = ((float)(imageHeight - rowsDone) / imageHeight) * 100;
  std::cout << "[";
  for(int i = 0; i < 50; i++){
      if(i < (progress_bar_status_as_percentage / 2)){ // percentage needs to be divided by 2 because the percentage bar is 50 width
          std::cout << "#";
      }else{
          std::cout << " ";
      }
  }
    std::cout << "] " << progress_bar_status_as_percentage << "% \r" << std::flush;
}
