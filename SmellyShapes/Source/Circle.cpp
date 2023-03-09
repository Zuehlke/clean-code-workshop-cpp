#include "Circle.h"
#include <vector>

#define PI 3.14

using namespace std;

Circle::Circle(Point center, int radius)
    : center(center)
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

int Circle::countContainingPoints(int *xCoords, int *yCoords, int size)
{
  int numberOfContainingPoints = 0;
  for (int i = 0; i < size; ++i)
  {
    if (containsPoint(Point{xCoords[i], yCoords[i]}))
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
  return center.x;
}

int Circle::getY() const
{
  return center.y;
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
  return "Circle: (" + to_string(center.x) + "," + to_string(center.y) + ") radius= " +
         to_string(radius) + " RGB=" +
         color.getColorAsRGBRed() + "," +
         color.getColorAsRGBGreen() + "," +
         color.getColorAsRGBBlue();
}

string Circle::toXml()
{
  string xmlString = "";
  xmlString.append("<circle");
  xmlString.append(" x=\"" + to_string(getX()) + "\"");
  xmlString.append(" y=\"" + to_string(getY()) + "\"");
  xmlString.append(" radius=\"" + to_string(getRadius()) + "\"");
  xmlString.append(" />\n");
  return xmlString;
}
bool Circle::containsPoint(Point point)
{
  const auto xDistance = point.x - center.x;
  const auto yDistance = point.y - center.y;
  const auto squaredDistance = squared(xDistance) + squared(yDistance);

  return squaredDistance <= squared(radius);
}
