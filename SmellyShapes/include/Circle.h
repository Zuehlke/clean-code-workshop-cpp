#pragma once
#include "Color.h"
#include "SimpleShape.h"
#include <vector>

class Circle : public SimpleShape
{
public:
  Circle(int x, int y, int radius);
  virtual ~Circle();

  bool contains(int x, int y);
  int countContainingPoints(int *xCoords, int *yCoords, int size);

  Color getColor();
  void setColor(Color color);
  int getX() const;
  int getY() const;
  int getRadius() const;
  double calculateArea() const;
  std::string toString() const;

private:
  int x;
  int y;
  int radius;
  Color color;
};
