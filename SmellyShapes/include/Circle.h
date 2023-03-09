#pragma once
#include "Color.h"
#include "Point.h"
#include "Shape.h"
#include <string>
#include <vector>

class Circle : public Shape
{
public:
  Circle(Point center, int radius);
  virtual ~Circle();

  bool containsPoint(Point point) override;
  int countContainingPoints(int *xCoords, int *yCoords, int size);

  /*!
          \brief	This method returns the shape color.
          \return	the shape color
  */
  Color getColor();

  /*!
          \brief	Sets the shape color
          \param color The color to set
          \return	color the new color of the shape
  */
  void setColor(Color color);
  int getX() const;
  int getY() const;
  int getRadius() const;
  double calculateArea() const;
  std::string toString() const;

  std::string toXml() override;

private:
  Point center;

  int radius;
  Color color;
};
