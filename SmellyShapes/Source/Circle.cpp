#include "Circle.h"
#include <vector>

#define PI 3.14

using namespace std;

Circle::Circle(int x, int y, int radius)
    : x(x)
    , y(y)
    , radius(radius)
    , color("None")
{
}

namespace
{
int squared(const int xDistance) { return xDistance * xDistance; }
} // namespace

Circle::~Circle()
{
}

bool Circle::contains(int x, int y)
{
  const auto xDistance = x - this->x;
  const auto yDistance = y - this->y;
  const auto squaredDistance = squared(xDistance) + squared(yDistance);

  return squaredDistance <= squared(this->radius);
}

int Circle::countContainingPoints(int *xCoords, int *yCoords, int size)
{
  int numberOfContainingPoints = 0;
  for (int i = 0; i < size; ++i)
  {
    if (contains(xCoords[i], yCoords[i]))
    {
      numberOfContainingPoints++;
    }
  }

  return numberOfContainingPoints;
}

Color Circle::getColor()
{
  return color;
}

void Circle::setColor(Color color)
{
  this->color = color;
}

int Circle::getX() const
{
  return x;
}

int Circle::getY() const
{
  return y;
}

int Circle::getRadius() const
{
  return radius;
}

double Circle::calculateArea() const
{
  return radius * radius * PI;
}

string Circle::toString() const
{
  return "Circle: (" + to_string(x) + "," + to_string(y) + ") radius= " +
         to_string(radius) + " RGB=" +
         color.getColorAsRGBRed() + "," +
         color.getColorAsRGBGreen() + "," +
         color.getColorAsRGBBlue();
}