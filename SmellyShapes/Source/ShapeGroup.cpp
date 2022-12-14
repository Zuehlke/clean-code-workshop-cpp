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
    this->shapes.emplace_back(ptr);
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
  shapes.emplace_back(shape);
}

bool ShapeGroup::contains(void *element)
{
  return std::find_if(shapes.begin(), shapes.end(), [element](auto const &shape_ptr)
                      { return shape_ptr.get() == element; }) != shapes.end();
}

bool ShapeGroup::contains(int x, int y)
{
  return std::any_of(shapes.begin(), shapes.end(), [x, y](auto const &shape_ptr)
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
  for (const auto &shape : shapes)
  {
    xmlString.append(shape->toXml());
  }
  xmlString.append("</shapegroup>\n");

  return xmlString;
}

std::vector<Shape *> ShapeGroup::getShapes() const
{
  std::vector<Shape *> theShapes(shapes.size(), nullptr);
  std::transform(shapes.begin(), shapes.end(), theShapes.begin(), [](const auto &shape)
                 { return shape.get(); });
  return theShapes;
}

int ShapeGroup::getSize() const
{
  return shapes.size();
}
