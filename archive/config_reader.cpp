#include "../include/config_reader.h"
#include <fstream>
#include <iostream>
bool ConfigReader::LoadConfig(AppConfig& config, const std::string& path)
{
  std::ifstream file(path);
  if (!file.is_open()) {
      std::cerr << "Failed to open config file: " << path << "\n";
      return false;
  }

  try {
      nlohmann::json j;
      file >> j;

      if (j.contains("image")) {
          config.image_width_ = j["image"].value("width", config.image_width_);
          config.image_height_ = j["image"].value("height", config.image_height_);
          config.image_output_ = j["image"].value("output", config.image_output_);
      }

      if (j.contains("render")) {
          config.renderer_anti_aliasing_ = j["render"].value("anti_aliasing", config.renderer_anti_aliasing_);
          config.renderer_pixel_samples_ = j["render"].value("sample_rate", config.renderer_pixel_samples_);
          config.renderer_max_depth_ = j["render"].value("max_depth", config.renderer_max_depth_);
      }

      return true;
  } catch (std::exception& e) {
      std::cerr << "JSON parsing error: " << e.what() << "\n";
      return false;
  }
  return true;
}
