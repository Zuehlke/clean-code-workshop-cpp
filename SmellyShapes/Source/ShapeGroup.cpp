#include "ShapeGroup.h"
#include "Rectangle.h"
#include "Shape.h"
#include <Circle.h>
#include <Square.h>
#include <algorithm>
#include <stdexcept>

static const int INITIAL_CAPACITY = 10;
static const int CAPACITY_INCREMENT = 10;

ShapeGroup::ShapeGroup()
    : readOnly(false)
{
}

ShapeGroup::ShapeGroup(std::vector<Shape *> &shapes, bool readOnly)
    : readOnly(readOnly)
{
  for (auto* shape : shapes)
  {
    this->shapes.emplace_back(shape);
  }
  shapes.clear();
}

void ShapeGroup::add(Shape *shape)
{
  if (readOnly)
    return;

  if (contains(shape))
  {
    return;
  }

  insertShape(shape);
}

void ShapeGroup::insertShape(Shape *shape)
{
  shapes.emplace_back(shape);
}

bool ShapeGroup::contains(void *element)
{
  return std::any_of(std::begin(shapes), std::end(shapes),
                     [element](auto const &shape)
                     { return shape.get() == element; });
}

bool ShapeGroup::contains(int x, int y)
{
  return std::any_of(std::begin(shapes), std::end(shapes),
                     [x, y](auto const &shape)
                     { return shape && shape->contains(x, y); });

}

void ShapeGroup::setReadOnly(bool readOnly)
{
  this->readOnly = readOnly;
}
std::string ShapeGroup::toXml()
{
  std::string xmlString = "";

  xmlString.append("<shapegroup>\n");
  for (const auto& shape : shapes)
  {
    xmlString.append(shape->toXml());
  }
  xmlString.append("</shapegroup>\n");

  return xmlString;
}

int ShapeGroup::getSize() const
{
  return shapes.size();
}

const std::vector<std::unique_ptr<Shape>> &ShapeGroup::getShapes() const
{
  return shapes;
}
