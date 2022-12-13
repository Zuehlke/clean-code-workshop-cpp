#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include <ShapeGroup.h>
#include <Square.h>
#include <stdexcept>
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

  if (dynamic_cast<Circle *>(this) != NULL)
  {
    Circle *circle = (Circle *)this;
    xmlString.append("<circle");
    xmlString.append(" x=\"" + to_string(circle->getX()) + "\"");
    xmlString.append(" y=\"" + to_string(circle->getY()) + "\"");
    xmlString.append(" radius=\"" + to_string(circle->getRadius()) + "\"");
    xmlString.append(" />\n");
  }
  else if (dynamic_cast<Square *>(this) != NULL)
  {
    Square *square = (Square *)this;
    xmlString.append("<square");
    xmlString.append(" x=\"" + to_string(square->getX()) + "\"");
    xmlString.append(" y=\"" + to_string(square->getY()) + "\"");
    xmlString.append(" edgeLength=\"" + to_string(square->getWidth()) + "\"");
    xmlString.append(" />\n");
  }
  else if (dynamic_cast<Rectangle *>(this) != NULL)
  {
    Rectangle *rectangle = (Rectangle *)this;
    xmlString.append("<rectangle");
    xmlString.append(" x=\"" + to_string(rectangle->getX()) + "\"");
    xmlString.append(" y=\"" + to_string(rectangle->getY()) + "\"");
    xmlString.append(" width=\"" + to_string(rectangle->getWidth()) + "\"");
    xmlString.append(" height=\"" + to_string(rectangle->getHeight()) + "\"");
    xmlString.append(" />\n");
  }
  else if (dynamic_cast<ShapeGroup *>(this) != NULL)
  {
    ShapeGroup *shapeGroup = (ShapeGroup *)this;
    xmlString.append("<shapegroup>\n");
    for (int i = 0; i < shapeGroup->size; i++)
    {
      Shape *shape = shapeGroup->shapes[i];
      xmlString.append(shape->toXml());
    }
    xmlString.append("</shapegroup>\n");
  }
  else
  {
    string name = typeid(*this).name();
    throw runtime_error(string("Unknown shape type: " + name).c_str());
  }

  return xmlString;
}