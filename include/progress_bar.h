#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_PROGRESS_BAR_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_PROGRESS_BAR_H
#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>
class ProgressBar
{
  public:
  ProgressBar(int total_steps, int bar_width = 50)
        : total_steps_(total_steps),
          bar_width_(bar_width),
          start_time_(std::chrono::steady_clock::now()) {}
  void Update(int current_step);
  void Done();
  private:
    int total_steps_;
    int bar_width_;
    std::chrono::steady_clock::time_point start_time_;
};
#endif
