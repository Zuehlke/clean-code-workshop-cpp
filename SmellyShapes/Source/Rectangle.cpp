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
  xmlString.append(" x=\"" + std::to_string(getX()) + "\"");
  xmlString.append(" y=\"" + std::to_string(getY()) + "\"");
  xmlString.append(" width=\"" + std::to_string(getWidth()) + "\"");
  xmlString.append(" height=\"" + std::to_string(getHeight()) + "\"");
  xmlString.append(" />\n");
  return xmlString;
}

bool Rectangle::containsPoint(Point point)
{
  return getX() <= point.x && point.x <= getX() + getWidth() && getY() <= point.y && point.y <= getY() + getHeight();
}