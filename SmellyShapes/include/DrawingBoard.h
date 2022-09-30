#pragma once
#include "ShapeGroup.h"
#include "Color.h"

class DrawingBoard : public ShapeGroup
{
public:
    DrawingBoard();
    Color getBackgroundColor();
    void setBackgroundColor(Color backgroundColor);
    void drawOnScreen();

private:
    Color backgroundColor;
};

