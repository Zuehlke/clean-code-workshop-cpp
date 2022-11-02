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

string Color::getColorFormatted(bool includeHexAndRGB) const
{
  if (includeHexAndRGB)
  {
    return colorAsText + " " + colorAsHex + " " + colorAsRGB_Red + ":" + colorAsRGB_Green + ":" + colorAsRGB_Blue;
  }

  return colorAsText;
}

string Color::getColorAsHex() const
{
  return colorAsHex;
}

int Color::convertTextValueToRGBAndHex()
{
  // set to Red
  if (colorAsText == RED)
  {
    colorAsRGB_Red = "255";
    colorAsRGB_Blue = "0";
    colorAsRGB_Green = "0";
    colorAsHex = "#FF0000";
  }
  else if (colorAsText == BLUE)
  {
    // set to Blue
    colorAsRGB_Red = "0";
    colorAsRGB_Blue = "255";
    colorAsRGB_Green = "0";
    colorAsHex = "#00FF00";
  }
  else if (colorAsText == GREEN)
  {
    // set to Green
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
