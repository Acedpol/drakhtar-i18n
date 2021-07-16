// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once

#include <array>
#include <map>
#include <string>

#include "Parser/Strings/StringContent.h"

class Plurals {
 private:
  // punctuation marks symbols:
  std::string zero_{};
  std::string one_{};
  std::string two_{};
  std::string few_{};
  std::string many_{};
  std::string other_{};
  std::string value_{};

  static bool read(const std::map<std::string, StringContent>& map,
                   const std::string& key, std::string& string) noexcept;

 public:
  Plurals(const std::map<std::string, StringContent>& map);

  void apply(const std::map<std::string, StringContent>& map) noexcept;

  [[nodiscard]] const std::string& count(int n) const noexcept;

};
