// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once

#include <array>
#include <map>
#include <string>

#include "Parser/Strings/StringContent.h"

enum class distance { pulgada, pie, yarda, milla, legua, metro, kilometro };
enum class fever { celsius, farenheit };
enum class weight { libra, onza, gramo, kilo };
enum class badge { euro, libra, dollar };
enum class date { dia, mes, anio };

class Units {
 private:

  static bool read(const std::map<std::string, StringContent>& map,
                   const std::string& key, std::string& string) noexcept;

 public:
  Units(const std::map<std::string, StringContent>& map);

  double distance(const std::map<std::string, StringContent>& map, double size, distance given) noexcept;
  double fever(const std::map<std::string, StringContent>& map, double size, fever given) noexcept;
  double weight(const std::map<std::string, StringContent>& map, double size, weight given) noexcept;
  double badge(const std::map<std::string, StringContent>& map, double size, badge given) noexcept;
  double date(const std::map<std::string, StringContent>& map, double size, date given) noexcept;

  void apply(const std::map<std::string, StringContent>& map) noexcept;

};
