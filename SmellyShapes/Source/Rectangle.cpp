#include "Rectangle.h"
#include <sstream>

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
  xmlString.append("<rectangle");
  xmlString.append(" x=\"" + std::__cxx11::to_string(this->getX()) + "\"");
  xmlString.append(" y=\"" + std::__cxx11::to_string(this->getY()) + "\"");
  xmlString.append(" width=\"" + std::__cxx11::to_string(this->getWidth()) + "\"");
  xmlString.append(" height=\"" + std::__cxx11::to_string(this->getHeight()) + "\"");
  xmlString.append(" />\n");
  return xmlString;
}