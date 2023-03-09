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

  void add(Shape *shape);
  bool contains(void *element);
  virtual bool contains(int x, int y) override;
  void setReadOnly(bool readOnly);
  std::string toXml() override;

  std::size_t getSize() const;
  std::vector<std::unique_ptr<Shape>> const &getShapes() const;

private:
  std::vector<std::unique_ptr<Shape>> newShapes;
  bool readOnly;
  void insertShape(Shape *shape);
};
