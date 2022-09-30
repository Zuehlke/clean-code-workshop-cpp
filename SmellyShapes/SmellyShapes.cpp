#include "include/Square.h"
#include "include/DrawingBoard.h"

int main(int argc, char* argv[])
{
	printf("Start: %s %d", __FUNCTION__, __LINE__);
	DrawingBoard drawingBoard;
	drawingBoard.setBackgroundColor(Color("Green"));
	auto square = new Square(-10, -10, 20);
	drawingBoard.add(square);
	drawingBoard.drawOnScreen();
	return 0;
}