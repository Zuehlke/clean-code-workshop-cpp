#pragma once
#include "Shape.h"
#include <memory>
#include <vector>

class ShapeGroup : public Shape
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
  bool capacityExceeded() const;
  void increaseCapacity();
  void insertShape(Shape *shape);
};
