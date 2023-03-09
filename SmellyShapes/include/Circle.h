#pragma once
#include "Color.h"
#include "Shape.h"
#include <string>
#include <vector>

class Circle : public Shape
{
public:
  Circle(int x, int y, int radius);
  virtual ~Circle();

  bool contains(int x, int y);
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
  int x;
  int y;
  int radius;
  Color color;
};
