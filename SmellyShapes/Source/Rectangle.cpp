#include "Rectangle.h"
#include "Shape.h"
#include <Circle.h>
#include <ShapeGroup.h>
#include <Square.h>
#include <sstream>
#include <stdexcept>

Rectangle::Rectangle(int x, int y, int width, int height)
    : x(x)
    , y(y)
    , width(width)
    , height(height)
    , color("None")
{
}

Rectangle::~Rectangle()
{
}

int Rectangle::getWidth()
{
  return width;
}

int Rectangle::getHeight()
{
  return height;
}

int Rectangle::getY()
{
  return y;
}

void Rectangle::getDimensions(int &width, int &height)
{
  width = this->width;
  height = this->height;
}

int Rectangle::getX()
{
  return x;
}

bool Rectangle::contains(int x, int y)
{
  return getX() <= x && x <= getX() + getWidth() && getY() <= y && y <= getY() + getHeight();
}

int Rectangle::calculateArea()
{
  return getWidth() * getHeight();
}

std::string Rectangle::toString()
{
  std::stringstream stream;
  stream << "Rectangle (" << x << ":" << y << ") edgeLength=" << width << " color=" << color.getColorAsHex();
  return stream.str();
}

void Rectangle::SetWidth(int width)
{
  this->width = width;
}
std::string Rectangle::toXml()
{
  std::string xmlString = "";
  if (dynamic_cast<Square *>(this) != NULL)
  {
    Square *square = (Square *)this;
    xmlString.append("<square");
    xmlString.append(" x=\"" + std::__cxx11::to_string(square->getX()) + "\"");
    xmlString.append(" y=\"" + std::__cxx11::to_string(square->getY()) + "\"");
    xmlString.append(" edgeLength=\"" + std::__cxx11::to_string(square->getWidth()) + "\"");
    xmlString.append(" />\n");
  }
  else if (dynamic_cast<Rectangle *>(this) != NULL)
  {
    Rectangle *rectangle = (Rectangle *)this;
    xmlString.append("<rectangle");
    xmlString.append(" x=\"" + std::__cxx11::to_string(rectangle->getX()) + "\"");
    xmlString.append(" y=\"" + std::__cxx11::to_string(rectangle->getY()) + "\"");
    xmlString.append(" width=\"" + std::__cxx11::to_string(rectangle->getWidth()) + "\"");
    xmlString.append(" height=\"" + std::__cxx11::to_string(rectangle->getHeight()) + "\"");
    xmlString.append(" />\n");
  }
  return xmlString;
}