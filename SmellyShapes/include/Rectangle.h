#pragma once
#include "SimpleShape.h"
#include "Color.h"

class Rectangle : public SimpleShape
{
public:

	Rectangle(int x, int y, int width, int height);
	virtual ~Rectangle();

	int getX();
	int getY();
	int getWidth();
    virtual int getHeight();
	void getDimensions(int& width, int& height);
	bool contains(int x, int y) override;
	virtual int calculateArea();
	std::string toString();
	
private:

	int x;
	int y;
	int width;
	int height;

	void SetWidth(int width);

protected:

	Color color;
};

