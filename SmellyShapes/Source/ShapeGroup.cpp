#include "ShapeGroup.h"
#include <algorithm>

ShapeGroup::ShapeGroup() :
	size(0),
	readOnly(false)
{
	shapes.resize(10, NULL);
}

ShapeGroup::ShapeGroup(std::vector<Shape*>& shapes, bool readOnly) :
	readOnly(readOnly),
	size(shapes.size())
{
	for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it)
	{
		this->shapes.push_back(*it);
	}
	shapes.clear();
}

ShapeGroup::~ShapeGroup()
{
	for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it)
	{
		delete *it;
	}
}

void ShapeGroup::add(Shape* shape)
{
	if (!readOnly)
	{
		size_t newSize = size + 1;
		if (newSize > shapes.size())
		{
			std::vector<Shape*> newShapes(newSize + 10);
			for (int i = 0; i < size; ++i)
			{
				newShapes[i] = shapes[i];
			}
			shapes = newShapes;
		}

		if (contains(shape))
		{
			return;
		}
		shapes[size++] = shape;
	}
}

bool ShapeGroup::contains(void* element)
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
		Shape* shape = shapes[i];
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