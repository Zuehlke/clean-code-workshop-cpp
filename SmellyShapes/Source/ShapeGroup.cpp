#include "ShapeGroup.h"
#include <algorithm>

constexpr int INITIAL_CAPACITY = 10;
constexpr int CAPACITY_INCREMENT = 11;

ShapeGroup::ShapeGroup()
    : readOnly(false)
{
}

ShapeGroup::ShapeGroup(std::vector<Shape *> &shapes, bool readOnly)
    : readOnly(readOnly)
{
  for (auto shape : shapes)
  {
    newShapes.emplace_back(shape);
  }

  shapes.clear();
}

void ShapeGroup::add(Shape *shape)
{
  if (readOnly)
  {
    return;
  }

  if (contains(shape))
  {
    return;
  }

  insertShape(shape);
}

void ShapeGroup::insertShape(Shape *shape)
{
  newShapes.emplace_back(shape);
}

bool ShapeGroup::contains(void *element)
{
  return std::any_of(newShapes.begin(), newShapes.end(), [element](auto const &shape)
                     { return shape.get() == element; });
}

bool ShapeGroup::contains(int x, int y)
{
  return std::any_of(newShapes.begin(), newShapes.end(), [x, y](auto const &shape)
                     { return shape->contains(x, y); });
}

void ShapeGroup::setReadOnly(bool readOnly)
{
  this->readOnly = readOnly;
}

std::string ShapeGroup::toXml()
{
  std::string xmlString = "";
  xmlString.append("<shapegroup>\n");

  for (auto const &shape : newShapes)
  {
    xmlString.append(shape->toXml());
  }

  xmlString.append("</shapegroup>\n");
  return xmlString;
}

std::size_t ShapeGroup::getSize() const
{
  return newShapes.size();
}

std::vector<std::unique_ptr<Shape>> const &ShapeGroup::getShapes() const
{
  return newShapes;
}
