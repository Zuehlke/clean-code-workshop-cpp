#pragma once
#include <string>

struct Point
{
  int x;
  int y;
};

class Shape
{
public:
  virtual ~Shape() {}
  virtual bool contains(int x, int y) = 0;

  virtual std::string toXml() = 0;


protected:
  Shape() {}

private:
  Shape(const Shape &);
  Shape &operator=(const Shape &);
};
