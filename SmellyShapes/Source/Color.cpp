#include "Color.h"

using namespace std;

Color::Color()
{
}

Color::Color(const std::string colorAsText)
    : colorAsText(colorAsText)
{
  int error = convertTextValueToRGBAndHex();
  if (error)
  {
    errorMessage = "Color not recognized";
  }
}

Color::~Color()
{
}

string Color::getColorAsRGBBlue() const
{
  return colorAsRGB_Blue;
}

string Color::getColorAsRGBGreen() const
{
  return colorAsRGB_Green;
}

string Color::getColorAsRGBRed() const
{
  return colorAsRGB_Red;
}

string Color::getErrorMessage() const
{
  return errorMessage;
}

string Color::getColorFormatted() const
{
  return colorAsText + " " + colorAsHex + " " + colorAsRGB_Red + ":" + colorAsRGB_Green + ":" + colorAsRGB_Blue;
}

const string &Color::getColorAsText() const
{
  return colorAsText;
}

string Color::getColorAsHex() const
{
  return colorAsHex;
}

int Color::convertTextValueToRGBAndHex()
{
  if (colorAsText == RED)
  {
    colorAsRGB_Red = "255";
    colorAsRGB_Blue = "0";
    colorAsRGB_Green = "0";
    colorAsHex = "#FF0000";
  }
  else if (colorAsText == BLUE)
  {
    colorAsRGB_Red = "0";
    colorAsRGB_Blue = "255";
    colorAsRGB_Green = "0";
    colorAsHex = "#00FF00";
  }
  else if (colorAsText == GREEN)
  {
    colorAsRGB_Red = "0";
    colorAsRGB_Blue = "0";
    colorAsRGB_Green = "255";
    colorAsHex = "#0000FF";
  }
  else
  {
    return -1;
  }
  return 0;
}
