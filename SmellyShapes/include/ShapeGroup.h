#pragma once
#include "ComplexShape.h"
#include <memory>
#include <vector>

class ShapeGroup : public ComplexShape
{
public:
  ShapeGroup();
  ShapeGroup(const ShapeGroup &);
  ShapeGroup(std::vector<Shape *> &shapes, bool readOnly);
  virtual ~ShapeGroup();

  void add(Shape *shape);
  bool contains(void *element);
  virtual bool contains(int x, int y) override;
  void setReadOnly(bool readOnly);

  std::vector<Shape *> shapes;
  int size;

private:
  bool readOnly;
  void addToShapes(Shape *shape);
};
