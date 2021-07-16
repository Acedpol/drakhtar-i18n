#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>

#include "Information/Plurals.h"
#include "Parser/FileParser.h"

TEST(NumberMetadata, latn) {
  std::filesystem::path path{"languages"};
  std::ifstream s{path / "en" / ".meta.txt"};
  Plurals meta{FileParser(s).run()};

  EXPECT_EQ(meta.count(0), "zero");
  EXPECT_EQ(meta.count(1), "one");
  EXPECT_EQ(meta.count(2), "two");
  EXPECT_EQ(meta.count(6), "few");
  EXPECT_EQ(meta.count(70), "many");
  EXPECT_EQ(meta.count(800), "other");
  EXPECT_EQ(meta.count(-1), "-1");
}
