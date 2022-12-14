#include "DrawingBoard.h"
#include <Rectangle.h>
#include "Circle.h"

DrawingBoard::DrawingBoard() :
	backgroundColor("White")
{
	add(new Circle(5, 6, 7));
	add(new Rectangle(1, 1, 20, 20));
}

Color DrawingBoard::getBackgroundColor()
{
	return backgroundColor;
}

void DrawingBoard::setBackgroundColor(Color backgroundColor)
{
	this->backgroundColor = backgroundColor;
}

void DrawingBoard::drawOnScreen()
{
	for (auto shape : shapes)
	{
	    // draw shape on screen
	}
}

