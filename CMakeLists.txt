cmake_minimum_required(VERSION 3.12)
project(smelly_shapes_cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(GoogleTestProject)
include_directories(SmellyShapes/include)


set(SOURCE_FILES
        SmellyShapes/include/Circle.h
        SmellyShapes/include/Color.h
        SmellyShapes/include/DrawingBoard.h
        SmellyShapes/include/Rectangle.h
        SmellyShapes/include/Shape.h
        SmellyShapes/include/ShapeGroup.h
        SmellyShapes/include/Square.h
        SmellyShapes/Source/Circle.cpp
        SmellyShapes/Source/Color.cpp
        SmellyShapes/Source/DrawingBoard.cpp
        SmellyShapes/Source/Rectangle.cpp
        SmellyShapes/Source/Shape.cpp
        SmellyShapes/Source/ShapeGroup.cpp
        SmellyShapes/Source/Square.cpp)

set(TEST_SOURCE_FILES
        GoogleTestProject/CircleTest.cpp
        GoogleTestProject/ColorTest.cpp
        GoogleTestProject/pch.cpp
        GoogleTestProject/pch.h
        GoogleTestProject/RectangleTest.cpp
        GoogleTestProject/ShapeGroupTest.cpp
        GoogleTestProject/SquareTest.cpp
        GoogleTestProject/gtest.h
        GoogleTestProject/gtest-all.cc)

add_executable(smelly_shapes_cpp
        ${SOURCE_FILES}
        SmellyShapes/SmellyShapes.cpp
        )

add_executable(google_tests
        ${SOURCE_FILES}
        ${TEST_SOURCE_FILES}
        GoogleTestProject/main.cpp)

# turn off pthread use in gtest as it's not available on all platforms and not needed for the project
target_compile_definitions(google_tests PUBLIC GTEST_HAS_PTHREAD=0)
