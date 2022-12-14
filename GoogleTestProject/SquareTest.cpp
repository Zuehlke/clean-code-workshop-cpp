#include "../SmellyShapes/include/Square.h"
#include "Rectangle.h"
#include "pch.h"
#include <stdexcept>

TEST(SquareTest, CalculateArea)
{
  Square square(Point{0, 0}, 2);
  ASSERT_EQ(4, square.calculateArea());
}

TEST(SquareTest, ToString_)
{
  Square square(Point{0, 0}, 1, Color("Red"));
  ASSERT_STREQ("Square: (0:0) edgeLength=1 color=#FF0000", square.ToString().c_str());
}

/* Ignored test - c.f.
https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#temporarily-disabling-tests
*/
TEST(SquareTest, DISABLED_ToString_FromBaseClass)
{
  Rectangle *square = new Square(Point{0, 0}, 1, Color("Red"));
  ASSERT_STREQ("Square: (0:0) edgeLength=1 color=#FF0000", square->toString().c_str());
}

TEST(SquareTest, ToXml)
{
  Square square(Point{0, 1}, 2);
  std::string xml = square.toXml();
  ASSERT_STREQ("<square x=\"0\" y=\"1\" edgeLength=\"2\" />\n", xml.c_str());
}

TEST(SquareTest, ContainsPoints)
{
  Square square(Point{0, 0}, 1);

  ASSERT_TRUE(square.ContainsPoint(Point{0, 0}));
  ASSERT_TRUE(square.ContainsPoint(Point{0, 1}));
  ASSERT_TRUE(square.ContainsPoint(Point{1, 1}));
  ASSERT_TRUE(square.ContainsPoint(Point{1, 0}));

  ASSERT_FALSE(square.ContainsPoint(Point{-1, -1}));
  ASSERT_FALSE(square.ContainsPoint(Point{-1, 0}));
  ASSERT_FALSE(square.ContainsPoint(Point{0, -1}));
  ASSERT_FALSE(square.ContainsPoint(Point{1, 2}));
  ASSERT_FALSE(square.ContainsPoint(Point{2, 1}));
}

TEST(SquareTest, GetHeigth)
{
  Square square(Point{0, 0}, 0);
  auto func = [&]
  { square.getHeight(); };

  ASSERT_THROW(func(), std::runtime_error); // InvalidOperationException
}