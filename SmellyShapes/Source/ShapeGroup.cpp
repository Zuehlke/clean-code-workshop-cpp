#include "ShapeGroup.h"
#include <algorithm>

constexpr int INITIAL_CAPACITY = 10;
constexpr int CAPACITY_INCREMENT = 11;

ShapeGroup::ShapeGroup()
    : size(0)
    , readOnly(false)
{
  shapes.resize(INITIAL_CAPACITY, nullptr);
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
  if (readOnly)
  {
    return;
  }

  if (contains(shape))
  {
    return;
  }

  if (capacityExceeded())
  {
    increaseCapacity();
  }

  insertShape(shape);
}

void ShapeGroup::insertShape(Shape *shape) { shapes[size++] = shape; }

void ShapeGroup::increaseCapacity()
{
  std::vector<Shape *> newShapes(size + CAPACITY_INCREMENT);
  for (int i = 0; i < size; ++i)
  {
    newShapes[i] = shapes[i];
  }
  shapes = std::move(newShapes);
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