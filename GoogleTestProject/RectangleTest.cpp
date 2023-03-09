#include "../SmellyShapes/include/Rectangle.h"
#include "Rectangle.h"
#include "pch.h"

class RectangleTest : public ::testing::Test
{
protected:
  Rectangle rectangle;

  RectangleTest()
      : rectangle(0, 0, 2, 1)
  {
  }

  // void SetUp() override {}
  // void TearDown() override {}
};

TEST_F(RectangleTest, Contains)
{
  ASSERT_TRUE(rectangle.containsPoint(Point{0, 0}));
  ASSERT_TRUE(rectangle.containsPoint(Point{1, 0}));
  ASSERT_TRUE(rectangle.containsPoint(Point{1, 1}));
  ASSERT_TRUE(rectangle.containsPoint(Point{2, 1}));

  ASSERT_FALSE(rectangle.containsPoint(Point{2, 2}));
  ASSERT_FALSE(rectangle.containsPoint(Point{-1, 0}));
  ASSERT_FALSE(rectangle.containsPoint(Point{0, -1}));
}

TEST_F(RectangleTest, CalculateArea)
{
  ASSERT_EQ(2, rectangle.calculateArea());
}

TEST_F(RectangleTest, ToXml)
{
  std::string xml = rectangle.toXml();

  ASSERT_STREQ("<rectangle x=\"0\" y=\"0\" width=\"2\" height=\"1\" />\n", xml.c_str());
}
