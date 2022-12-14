#pragma once
#include "Shape.h"
#include <memory>
#include <string>
#include <vector>

class ShapeGroup : public Shape
{
public:
  ShapeGroup();
  ShapeGroup(std::vector<Shape *> &shapes, bool readOnly);

  void add(Shape *shape);
  bool contains(void *element);
  bool contains(int x, int y) override;
  void setReadOnly(bool readOnly);

  std::string toXml() override;

  const std::vector<std::unique_ptr<Shape>> &getShapes() const;
  int getSize() const;

private:
  std::vector<std::unique_ptr<Shape>> shapes;
  bool readOnly;
  void insertShape(Shape *shape);
};
