#include "../SmellyShapes/include/Color.h"
#include "pch.h"

TEST(ColorTest, GetErrorMessage_InvalidColor)
{
  Color c("INVALIDColor_N4me");

  ASSERT_STREQ("Color not recognized", c.getErrorMessage().c_str());
}

TEST(ColorTest, GetErrorMessage_Magenta)
{
  Color c("Magenta");

  ASSERT_STREQ("Color not recognized", c.getErrorMessage().c_str());
}

TEST(ColorTest, GetErrorMessage_Cyan)
{
  Color c("Cyan");

  ASSERT_STREQ("Color not recognized", c.getErrorMessage().c_str());
}

TEST(ColorTest, GetColorFormatted_Red)
{
  auto color = Color("Red");
  auto colorFormatted = color.getColorAsText();
  ASSERT_STREQ("Red", colorFormatted.c_str());
}

TEST(ColorTest, GetColorFormatted_Green)
{
  auto color = Color("Green");
  auto colorFormatted = color.getColorAsText();
  ASSERT_STREQ("Green", colorFormatted.c_str());
}

TEST(ColorTest, GetColorFormatted_Red_Incl)
{
  Color c("Red");
  std::string formattedColor = c.getColorWithHexAndRGB();
  ASSERT_STREQ("Red #FF0000 255:0:0", formattedColor.c_str());
}
