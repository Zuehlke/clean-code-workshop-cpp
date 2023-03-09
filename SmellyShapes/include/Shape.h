#pragma once
#include "Point.h"
#include <string>

class Shape
{
public:
  virtual ~Shape() {}

  virtual bool containsPoint(Point point) = 0;

  virtual std::string toXml() = 0;

protected:
  Shape() {}

private:
  Shape(const Shape &);
  Shape &operator=(const Shape &);
};
