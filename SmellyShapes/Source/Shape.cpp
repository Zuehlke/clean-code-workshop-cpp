#include "Shape.h"
#include <Circle.h>
#include <Square.h>
#include <ShapeGroup.h>
#include <stdexcept>

using namespace std;

std::string Shape::toXml()
{
	string xmlString = "";
	
	if(dynamic_cast<Circle*>(this) != NULL)
	{
		Circle* circle = (Circle*)this;
		xmlString.append("<circle");
		xmlString.append(" x=\"" + to_string(circle->getX()) + "\"");
		xmlString.append(" y=\"" + to_string(circle->getY()) + "\"");
		xmlString.append(" radius=\"" + to_string(circle->getRadius()) + "\"");
		xmlString.append(" />\n");
	}
	else if(dynamic_cast<Square*>(this) != NULL)
	{
		Square* square = (Square*)this;
		xmlString.append("<square");
		xmlString.append(" x=\"" + to_string(square->getX()) + "\"");
		xmlString.append(" y=\"" + to_string(square->getY()) + "\"");
		xmlString.append(" edgeLength=\"" + to_string(square->getWidth()) + "\"");
		xmlString.append(" />\n");
	}
	else if(dynamic_cast<Rectangle*>(this) != NULL)
	{
		Rectangle* rectangle = (Rectangle*)this;
		xmlString.append("<rectangle");
		xmlString.append(" x=\"" + to_string(rectangle->getX()) + "\"");
		xmlString.append(" y=\"" + to_string(rectangle->getY()) + "\"");
		xmlString.append(" width=\"" + to_string(rectangle->getWidth()) + "\"");
		xmlString.append(" height=\"" + to_string(rectangle->getHeight()) + "\"");
		xmlString.append(" />\n");
	}
	else if (dynamic_cast<ShapeGroup*>(this) != NULL)
	{
		ShapeGroup* shapeGroup = (ShapeGroup*)this;
		xmlString.append("<shapegroup>\n");
		for (int i = 0; i < shapeGroup->size; i++)
		{
			Shape* shape = shapeGroup->shapes[i];
			xmlString.append(shape->toXml());
		}
		xmlString.append("</shapegroup>\n");
	}
	else 
	{
		string name = typeid(*this).name();
		throw runtime_error(string("Unknown shape type: " + name).c_str());
	}

	return xmlString;
}
