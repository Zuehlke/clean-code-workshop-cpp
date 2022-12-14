#pragma once
#include "Point.h"
#include "Rectangle.h"

class Square : public Rectangle
{
public:
  Square(int x, int y, int edgeLength);
  Square(int x, int y, int edgeLength, Color color);
  virtual ~Square();

  bool ContainsPoint(Point const& point);
  int getHeight() override;
  int calculateArea() override;
  std::string ToString();
  std::string toXml();

  bool ContainsLine(int x1, int y1, int x2, int y2);
};
