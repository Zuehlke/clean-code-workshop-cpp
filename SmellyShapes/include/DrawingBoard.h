#pragma once
#include "Color.h"
#include "ShapeGroup.h"

class DrawingBoard
{
public:
  DrawingBoard();
  Color getBackgroundColor();
  void setBackgroundColor(Color backgroundColor);
  void drawOnScreen();

  void add(Shape *shape);

private:
  Color backgroundColor;
  ShapeGroup shapeGroup;
};
