#include "ShapeGroup.h"

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
  xmlString.append("<shapegroup>\n");
  for (int i = 0; i < this->size; i++)
  {
    Shape *shape = this->shapes[i];
    xmlString.append(shape->toXml());
  }
  xmlString.append("</shapegroup>\n");

  return xmlString;
}