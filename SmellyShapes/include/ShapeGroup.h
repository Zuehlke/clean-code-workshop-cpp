#pragma once
#include "Point.h"
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

  void add(Shape *shape);
  bool contains(void *element);
  void setReadOnly(bool readOnly);
  std::string toXml() override;

  std::size_t getSize() const;
  std::vector<std::unique_ptr<Shape>> const &getShapes() const;

  bool containsPoint(Point point) override;

private:
  std::vector<std::unique_ptr<Shape>> newShapes;
  bool readOnly;
  void insertShape(Shape *shape);
};
