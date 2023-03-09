#pragma once
#include <string>

class Color
{
public:
  Color();
  Color(const std::string colorAsText);
  ~Color();

  std::string getColorAsRGBBlue() const;
  std::string getColorAsRGBGreen() const;
  std::string getColorAsRGBRed() const;
  std::string getErrorMessage() const;
  std::string getColorAsHex() const;
  std::string getColorWithHexAndRGB() const;
  const std::string &getColorAsText() const;

private:
  std::string colorAsHex;
  std::string colorAsText;
  std::string colorAsRGB_Red;
  std::string colorAsRGB_Green;
  std::string colorAsRGB_Blue;
  std::string errorMessage;

  int convertTextValueToRGBAndHex();
};
