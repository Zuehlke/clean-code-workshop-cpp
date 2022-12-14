#pragma once
#include <string>

class Color
{
public:
  inline static const std::string RED = "Red";
  inline static const std::string BLUE = "Blue";
  inline static const std::string GREEN = "Green";

  Color();
  Color(const std::string colorAsText);
  ~Color();

  std::string getColorAsRGBBlue() const;
  std::string getColorAsRGBGreen() const;
  std::string getColorAsRGBRed() const;
  std::string getErrorMessage() const;
  std::string getColorFormatted(bool includeHexAndRGB) const;
  std::string getColorAsHex() const;

private:
  std::string colorAsHex;
  std::string colorAsText;
  std::string colorAsRGB_Red;
  std::string colorAsRGB_Green;
  std::string colorAsRGB_Blue;
  std::string errorMessage;

  int convertTextValueToRGBAndHex();
  const std::string &getColorAsText() const;
  std::string getColorFormatted() const;
};
