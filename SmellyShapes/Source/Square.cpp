#include "Square.h"
#include <stdexcept>

using namespace std;

Square::Square(int x, int y, int edgeLength)
    : Rectangle(x, y, edgeLength, edgeLength)
{
}

Square::Square(int x, int y, int edgeLength, Color color)
    : Rectangle(x, y, edgeLength, edgeLength)
{
  this->color = color;
}

Square::~Square()
{
}

bool Square::ContainsPoint(int x, int y)
{
  return getX() <= x && x <= getX() + getWidth() && getY() <= y && y <= getY() + getWidth();
}

int Square::getHeight()
{
  throw runtime_error("Square does not have a height, only edgeLength");
}

int Square::calculateArea()
{
  return getWidth() * getWidth();
}

std::string Square::ToString()
{
  char text[64];
  snprintf(text, 64, "Square: (%d:%d) edgeLength=%d color=%s", getX(), getY(), getWidth(), color.getColorAsHex().c_str());
  return text;
}

bool Square::ContainsLine(int x1, int y1, int x2, int y2)
{
  return contains(x1, y1) && contains(x2, y2);
}

std::string Square::toXml()
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