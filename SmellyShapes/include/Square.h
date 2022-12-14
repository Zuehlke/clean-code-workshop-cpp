#pragma once
#include "Point.h"
#include "Rectangle.h"

class Square : public Rectangle
{
public:
  Square(Point point, int edgeLength);
  Square(Point point, int edgeLength, Color color);
  virtual ~Square();

  bool ContainsPoint(Point const& point);
  int getHeight() override;
  int calculateArea() override;
  std::string ToString();
  std::string toXml();

  bool ContainsLine(int x1, int y1, int x2, int y2);
};
