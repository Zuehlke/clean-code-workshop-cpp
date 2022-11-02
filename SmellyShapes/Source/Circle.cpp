#include "Circle.h"
#include <vector>

#define PI 3.14

using namespace std;

namespace
{
int squared(const int i)
{
  return i * i;
}
} // namespace

Circle::Circle(int x, int y, int radius)
    : x(x)
    , y(y)
    , radius(radius)
    , numberOfContainingPoints(0)
    , color("None")
{
}

Circle::~Circle()
{
}

bool Circle::contains(int x, int y)
{
  const auto deltaX = x - this->x;
  const auto deltaY = y - this->y;
  bool result = squared(deltaX) + deltaY * deltaY <= this->radius * this->radius;
  if (result == true)
  {
    numberOfContainingPoints++;
  }
  return result;
}

int Circle::countContainingPoints(int *xCoords, int *yCoords, int size)
{
  numberOfContainingPoints = 0;
  for (int i = 0; i < size; ++i)
  {
    contains(xCoords[i], yCoords[i]);
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