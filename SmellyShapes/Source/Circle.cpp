#include "Circle.h"

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
    : Circle(Point{x, y}, radius)
{
}

Circle::Circle(Point point, int radius)
    : x(point.x)
    , y(point.y)
    , radius(radius)
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
  const auto squaredDistance = squared(deltaX) + squared(deltaY);
  return squaredDistance <= squared(this->radius);
}

int Circle::countContainingPoints(int *xCoords, int *yCoords, int size)
{
  auto numberOfContainingPoints = 0;
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
string Circle::toXml()
{
  string xmlString = "";

  xmlString.append("<circle");
  xmlString.append(" x=\"" + to_string(this->getX()) + "\"");
  xmlString.append(" y=\"" + to_string(this->getY()) + "\"");
  xmlString.append(" radius=\"" + to_string(this->getRadius()) + "\"");
  xmlString.append(" />\n");
  return xmlString;
}
