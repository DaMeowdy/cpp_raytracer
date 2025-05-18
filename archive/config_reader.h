#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_CONFIG_READER_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_CONFIG_READER_H
#include "../external/json/json.hpp"
#include "app_config.h"
class ConfigReader
{
  public:
  static bool LoadConfig(AppConfig& configuration,  const std::string& path);
};
#endif
