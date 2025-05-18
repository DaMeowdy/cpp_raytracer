#include "../include/progress_bar.h"
void ProgressBar::Update(int current_step)
{
  using namespace std::chrono;

  float progress = float(current_step) / total_steps_;
  int pos = int(bar_width_ * progress);

  // Time calculation
  auto now = steady_clock::now();
  auto elapsed = duration_cast<seconds>(now - start_time_).count();
  double eta = (current_step > 0) ? elapsed * (total_steps_ - current_step) / double(current_step) : 0;

  // Display progress bar
  std::cout << "\r[";
  for (int i = 0; i < bar_width_; ++i) {
      if (i < pos) std::cout << "=";
      else if (i == pos) std::cout << ">";
      else std::cout << " ";
  }

  std::cout << "] ";
  std::cout << std::setw(3) << int(progress * 100.0) << "%";
  std::cout << " ETA: " << std::setw(3) << int(eta) << "s";
  std::cout << std::flush;
}
void ProgressBar::Done()
{
  this->Update(total_steps_);
  std::cout << std::endl;
}
