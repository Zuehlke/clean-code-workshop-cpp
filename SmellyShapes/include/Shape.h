#pragma once
#include <string>

class Shape
{
public:

	virtual ~Shape() {}
	virtual bool contains(int x, int y) = 0;
	std::string toXml();

protected:

	Shape() {}

private:

	Shape(const Shape&);
	Shape& operator= (const Shape&);

};

