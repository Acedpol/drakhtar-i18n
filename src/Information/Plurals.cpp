// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Information/Plurals.h"

#include "Information/Locale.h"
#include "Parser/FileParser.h"
#include "Parser/Strings/StringContent.h"
#include "Utils/Util.h"

Plurals::Plurals(
    const std::map<std::string, StringContent>& map) {
  apply(map);
}

void Plurals::apply(
    const std::map<std::string, StringContent>& map) noexcept {
  // Punctuation marks:
  read(map, "PLZERO", zero_);
  read(map, "PLONE", one_);
  read(map, "PLTWO", two_);
  read(map, "PLFEW", few_);
  read(map, "PLMANY", many_);
  read(map, "PLOTHER", other_);
  read(map, "PLVALUE", value_);
}

const std::string& Plurals::count(int n) const noexcept {
  switch (n) {
    case 0:
      return zero_;
      break;
    case 1:
      return one_;
      break;
    case 2:
      return two_;
      break;
    default:
      if (n > 2 && n <= 10)
        return few_;
      else if (n > 10 && n <= 100)
        return many_;
      else if (n > 100 && n <= 1000)
        return other_;
      else
        return std::to_string(n);
  }
}

bool Plurals::read(const std::map<std::string, StringContent>& map,
                          const std::string& key,
                          std::string& string) noexcept {
  const auto it = map.find(key);
  if (it == map.cend()) return false;

  string = it->second.run({});
  return true;
}
