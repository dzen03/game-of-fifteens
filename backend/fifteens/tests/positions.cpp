#include "position.h"

#include <gtest/gtest.h>

using namespace fifteens;

TEST(Positions, BasicAdd) {
  Position a = {1, 2};
  Position b = {2, 1};
  Position c = a + b;

  EXPECT_TRUE(a.is_valid());
  EXPECT_TRUE(b.is_valid());
  EXPECT_TRUE(c.is_valid());

  EXPECT_EQ(c.x, a.x + b.x);
  EXPECT_EQ(c.y, a.y + b.y);
}

TEST(Positions, BasicSub) {
  Position a = {3, 3};
  Position b = {1, 1};
  Position c = a - b;

  EXPECT_TRUE(a.is_valid());
  EXPECT_TRUE(b.is_valid());
  EXPECT_TRUE(c.is_valid());

  EXPECT_EQ(c.x, a.x - b.x);
  EXPECT_EQ(c.y, a.y - b.y);
}
