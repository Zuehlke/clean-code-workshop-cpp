#pragma once
#include "Color.h"
#include "Point.h"
#include "Shape.h"
#include <string>

class Rectangle : public Shape
{
public:
  Rectangle(int x, int y, int width, int height);
  virtual ~Rectangle();

  int getX();
  int getY();
  int getWidth();
  virtual int getHeight();
  void getDimensions(int &width, int &height);
  virtual int calculateArea();
  std::string toString();

  std::string toXml() override;

  bool containsPoint(Point point) override;

  //  bool contains(int x, int y)
  //  {
  //    return containsPoint(Point{x, y});
  //  }
  //
private:
  int x;
  int y;
  int width;
  int height;

  void SetWidth(int width);

protected:
  Color color;
};
