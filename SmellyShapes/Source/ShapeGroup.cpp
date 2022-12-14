#include "ShapeGroup.h"
#include <algorithm>

constexpr int INITIAL_CAPACITY = 10;
constexpr int CAPACITY_INCREMENT = 10;

ShapeGroup::ShapeGroup()
    : readOnly(false)
{
}

ShapeGroup::ShapeGroup(std::vector<Shape *> &shapes, bool readOnly)
    : readOnly(readOnly)
{
  for (auto *ptr : shapes)
  {
    newShapes.emplace_back(ptr);
  }
  shapes.clear();
}

void ShapeGroup::add(Shape *shape)
{
  if (readOnly || contains(shape))
    return;

  addToShapes(shape);
}

void ShapeGroup::addToShapes(Shape *shape)
{
  newShapes.emplace_back(shape);
}

bool ShapeGroup::contains(void *element)
{
  return std::find_if(newShapes.begin(), newShapes.end(), [element](auto const &shape_ptr)
                      { return shape_ptr.get() == element; }) != newShapes.end();
}

bool ShapeGroup::contains(int x, int y)
{
  return std::any_of(newShapes.begin(), newShapes.end(), [x, y](auto const &shape_ptr)
                     { return shape_ptr && shape_ptr->contains(x, y); });
}

void ShapeGroup::setReadOnly(bool readOnly)
{
  this->readOnly = readOnly;
}
std::string ShapeGroup::toXml()
{
  std::string xmlString = "";
  xmlString.append("<shapegroup>\n");
  for (const auto &shape : newShapes)
  {
    xmlString.append(shape->toXml());
  }
  xmlString.append("</shapegroup>\n");

  return xmlString;
}

std::vector<Shape *> ShapeGroup::getShapes() const
{
  std::vector<Shape *> shapes(newShapes.size(), nullptr);
  std::transform(newShapes.begin(), newShapes.end(), shapes.begin(), [](const auto &shape)
                 { return shape.get(); });
  return shapes;
}

int ShapeGroup::getSize() const
{
  return newShapes.size();
}
