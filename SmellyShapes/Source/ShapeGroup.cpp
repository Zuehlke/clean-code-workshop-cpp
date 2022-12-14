#include "ShapeGroup.h"
#include <algorithm>

constexpr int INITIAL_CAPACITY = 10;
constexpr int CAPACITY_INCREMENT = 10;

ShapeGroup::ShapeGroup()
    : size(0)
    , readOnly(false)
{
  shapes.resize(INITIAL_CAPACITY, NULL);
}

ShapeGroup::ShapeGroup(std::vector<Shape *> &shapes, bool readOnly)
    : readOnly(readOnly)
    , size(shapes.size())
{
  for (std::vector<Shape *>::iterator it = shapes.begin(); it != shapes.end(); ++it)
  {
    this->shapes.push_back(*it);
  }
  for (auto* ptr : shapes)
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
  if (capacityExceeded())
  {
    increaseCapacity();
  }

  shapes[size++] = shape;
  newShapes.emplace_back(shape);
}

void ShapeGroup::increaseCapacity()
{
  std::vector<Shape *> newShapes(size + 1 + CAPACITY_INCREMENT);
  for (int i = 0; i < size; ++i)
  {
    newShapes[i] = shapes[i];
  }
  shapes = newShapes;
}

bool ShapeGroup::capacityExceeded() const { return size + 1 > shapes.size(); }

bool ShapeGroup::contains(void *element)
{
  return std::find_if(newShapes.begin(), newShapes.end(), [element](auto const& shape_ptr)
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
  for (const auto& shape: newShapes)
  {
    xmlString.append(shape->toXml());
  }
  xmlString.append("</shapegroup>\n");

  return xmlString;
}