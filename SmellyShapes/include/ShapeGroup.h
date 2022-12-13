#pragma once
#include "Shape.h"
#include <memory>
#include <string>
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

  std::string toXml() override;

private:
  bool readOnly;
  void addToShapes(Shape *shape);
  bool capacityExceeded() const;
  void increaseCapacity();
};
