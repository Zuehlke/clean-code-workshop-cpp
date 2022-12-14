#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include <ShapeGroup.h>
#include <Square.h>
#include <stdexcept>

#define PI 3.14

using namespace std;
namespace
{
int squared(const int i)
{
  return i * i;
}
} // namespace

Circle::Circle(Point point, int radius)
  : center(point), radius(radius), color("None")
{
}

Circle::~Circle()
{
}

bool Circle::contains(int x, int y)
{
  const int xDistance = x - center.x;
  const int yDistance = y - center.y;
  const int squaredDistancePythagoras = squared(xDistance) + squared(yDistance);
  const bool isInCircle = squaredDistancePythagoras <= squared(this->radius);
  return isInCircle;
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

  Circle *circle = (Circle *)this;
  xmlString.append("<circle");
  xmlString.append(" x=\"" + to_string(circle->getX()) + "\"");
  xmlString.append(" y=\"" + to_string(circle->getY()) + "\"");
  xmlString.append(" radius=\"" + to_string(circle->getRadius()) + "\"");
  xmlString.append(" />\n");

  return xmlString;
}
