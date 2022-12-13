#include "ShapeGroup.h"
#include "Rectangle.h"
#include "Shape.h"
#include <Circle.h>
#include <Square.h>
#include <algorithm>
#include <stdexcept>

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
  shapes.clear();
}

ShapeGroup::~ShapeGroup()
{
  for (std::vector<Shape *>::iterator it = shapes.begin(); it != shapes.end(); ++it)
  {
    delete *it;
  }
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
  for (int i = 0; i < size; ++i)
  {
    if (shapes[i] == element)
    {
      return true;
    }
  }

  return false;
}

bool ShapeGroup::contains(int x, int y)
{
  for (int i = 0; i < size; ++i)
  {
    Shape *shape = shapes[i];
    if (shape != NULL && shape->contains(x, y))
    {
      return true;
    }
  }

  return false;
}

void ShapeGroup::setReadOnly(bool readOnly)
{
  this->readOnly = readOnly;
}
std::string ShapeGroup::toXml()
{
  std::string xmlString = "";

  if (dynamic_cast<Circle *>(this) != NULL)
  {
    Circle *circle = (Circle *)this;
    xmlString.append("<circle");
    xmlString.append(" x=\"" + std::__cxx11::to_string(circle->getX()) + "\"");
    xmlString.append(" y=\"" + std::__cxx11::to_string(circle->getY()) + "\"");
    xmlString.append(" radius=\"" + std::__cxx11::to_string(circle->getRadius()) + "\"");
    xmlString.append(" />\n");
  }
  else if (dynamic_cast<Square *>(this) != NULL)
  {
    Square *square = (Square *)this;
    xmlString.append("<square");
    xmlString.append(" x=\"" + std::__cxx11::to_string(square->getX()) + "\"");
    xmlString.append(" y=\"" + std::__cxx11::to_string(square->getY()) + "\"");
    xmlString.append(" edgeLength=\"" + std::__cxx11::to_string(square->getWidth()) + "\"");
    xmlString.append(" />\n");
  }
  else if (dynamic_cast<Rectangle *>(this) != NULL)
  {
    Rectangle *rectangle = (Rectangle *)this;
    xmlString.append("<rectangle");
    xmlString.append(" x=\"" + std::__cxx11::to_string(rectangle->getX()) + "\"");
    xmlString.append(" y=\"" + std::__cxx11::to_string(rectangle->getY()) + "\"");
    xmlString.append(" width=\"" + std::__cxx11::to_string(rectangle->getWidth()) + "\"");
    xmlString.append(" height=\"" + std::__cxx11::to_string(rectangle->getHeight()) + "\"");
    xmlString.append(" />\n");
  }
  else if (dynamic_cast<ShapeGroup *>(this) != NULL)
  {
    ShapeGroup *shapeGroup = (ShapeGroup *)this;
    xmlString.append("<shapegroup>\n");
    for (int i = 0; i < shapeGroup->size; i++)
    {
      Shape *shape = shapeGroup->shapes[i];
      xmlString.append(shape->toXml());
    }
    xmlString.append("</shapegroup>\n");
  }
  else
  {
    std::string name = typeid(*this).name();
    throw std::runtime_error(std::string("Unknown shape type: " + name).c_str());
  }

  return xmlString;
}