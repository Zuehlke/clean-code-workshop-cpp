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
  xmlString.append("<square");
  xmlString.append(" x=\"" + std::__cxx11::to_string(this->getX()) + "\"");
  xmlString.append(" y=\"" + std::__cxx11::to_string(this->getY()) + "\"");
  xmlString.append(" edgeLength=\"" + std::__cxx11::to_string(this->getWidth()) + "\"");
  xmlString.append(" />\n");
  return xmlString;
}

bool Square::ContainsPoint(const Point &point)
{
  return getX() <= point.x && point.x <= getX() + getWidth() && getY() <= point.y && point.y <= getY() + getWidth();
}
