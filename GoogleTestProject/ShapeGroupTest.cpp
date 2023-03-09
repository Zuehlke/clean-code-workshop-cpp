#include "../SmellyShapes/include/ShapeGroup.h"
#include "../SmellyShapes/include/Circle.h"
#include "../SmellyShapes/include/Rectangle.h"
#include "pch.h"

TEST(ShapeGroupTest, ToXml)
{
  ShapeGroup shapeGroup;
  auto rectangle = new Rectangle(0, 0, 2, 1);
  shapeGroup.add(rectangle);

  std::string xml = shapeGroup.toXml();

  ASSERT_STREQ(
      "<shapegroup>\n<rectangle x=\"0\" y=\"0\" width=\"2\" height=\"1\" />\n</shapegroup>\n",
      xml.c_str());
}

TEST(ShapeGroupTest, Constructor_WithShapeArray)
{
  std::vector<Shape *> shapes{new Circle(0, 0, 0)};
  ShapeGroup shapeGroup(shapes, true);

  ASSERT_EQ(1, shapeGroup.getSize());
}

TEST(ShapeGroupTest, Add_WithReadOnly)
{
  ShapeGroup shapeGroup;
  shapeGroup.setReadOnly(true);

  shapeGroup.add(new Circle(0, 0, 0));

  ASSERT_EQ(0, shapeGroup.getSize());
}

TEST(ShapeGroupTest, Add_WithoutReadOnly)
{
  ShapeGroup shapeGroup;
  shapeGroup.setReadOnly(false);

  shapeGroup.add(new Circle(0, 0, 0));

  ASSERT_EQ(1, shapeGroup.getSize());
}

TEST(ShapeGroupTest, Add_SameElementTwice)
{
  ShapeGroup shapeGroup;
  shapeGroup.setReadOnly(false);

  auto circle = new Circle(0, 0, 0);
  shapeGroup.add(circle);
  shapeGroup.add(circle);

  ASSERT_EQ(1, shapeGroup.getSize());
}

TEST(ShapeGroupTest, Add_TwoSimilarElements)
{
  ShapeGroup shapeGroup;
  shapeGroup.setReadOnly(false);

  Circle *circle1 = new Circle(0, 0, 0);
  Circle *circle2 = new Circle(0, 0, 0);
  shapeGroup.add(circle1);
  shapeGroup.add(circle2);

  ASSERT_EQ(2, shapeGroup.getSize());
}

TEST(ShapeGroupTest, Add_InternalArraySizeExceeded)
{
  ShapeGroup shapeGroup;
  shapeGroup.setReadOnly(false);

  for (int i = 0; i < 11; i++)
  {
    auto circle = new Circle(0, 0, 0);
    shapeGroup.add(circle);
  }

  ASSERT_EQ(11, shapeGroup.getSize());
}

TEST(ShapeGroupTest, Contains_PointNotInGroup)
{
  ShapeGroup shapeGroup;

  ASSERT_FALSE(shapeGroup.contains(0, 0));
}

TEST(ShapeGroupTest, Contains_PointInGroup)
{
  ShapeGroup shapeGroup;
  auto circle = new Circle(0, 0, 0);
  shapeGroup.add(circle);

  ASSERT_TRUE(shapeGroup.contains(0, 0));
}

TEST(ShapeGroupTest, Contains_Null)
{
  ShapeGroup shapeGroup;

  ASSERT_FALSE(shapeGroup.contains(NULL));
}

TEST(ShapeGroupTest, Contains_ShapeInGroup)
{
  ShapeGroup shapeGroup;
  Circle *c = new Circle(0, 0, 0);
  shapeGroup.add(c);

  ASSERT_TRUE(shapeGroup.contains(c));
}
