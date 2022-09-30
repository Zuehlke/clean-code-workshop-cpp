#include "pch.h"
#include "../SmellyShapes/include/Circle.h"
#define _USE_MATH_DEFINES
#include "math.h"

class CircleTest : public ::testing::Test {
protected:
	Circle circle;

	CircleTest() : circle(0, 0, 1) {}

	void SetUp() override {
		circle.setColor(Color("Red"));
	}

	// void TearDown() override {}
};


TEST_F(CircleTest, Contains) {
	ASSERT_TRUE(circle.contains(0, 0));
	ASSERT_TRUE(circle.contains(0, 1));
	ASSERT_TRUE(circle.contains(1, 0));

	ASSERT_FALSE(circle.contains(1, 1));
	ASSERT_FALSE(circle.contains(-1, -1));
	ASSERT_FALSE(circle.contains(1, -1));
	ASSERT_FALSE(circle.contains(-1, 1));
}

TEST_F(CircleTest, CountContainingPoints)
{
	std::vector<int> x = { 0, 10 };
	std::vector<int> y = { 0, 10 };
	int result = circle.countContainingPoints(&x[0], &y[0], 2);

	ASSERT_EQ(1, result);
}

TEST_F(CircleTest, ToXml)
{
	std::string xml = circle.toXml();
	ASSERT_STREQ("<circle x=\"0\" y=\"0\" radius=\"1\" />\n", xml.c_str());
}

TEST_F(CircleTest, ToString)
{
	ASSERT_STREQ("Circle: (0,0) radius= 1 RGB=255,0,0", circle.toString().c_str());
}

TEST_F(CircleTest, calculateArea)
{
	double expected = M_PI;
	double actual = circle.calculateArea();
	ASSERT_NEAR(expected, actual, 0.01f);
}

TEST_F(CircleTest, calculateArea2)
{
	double expected = 289 * M_PI;
	double actual = Circle(1, 2, 17).calculateArea();
	ASSERT_NEAR(expected, actual, 1.0f);
}

