#pragma once
#include "Color.h"
#include "ShapeGroup.h"

class DrawingBoard : public ShapeGroup
{
public:
  DrawingBoard();
  Color getBackgroundColor();
  void setBackgroundColor(Color backgroundColor);
  void drawOnScreen();

private:
  Color backgroundColor;
  ShapeGroup shapeGroup;
};
