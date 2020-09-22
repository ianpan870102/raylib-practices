#include "../../../raylib-cpp/include/raylib-cpp.hpp"
#include "raylib.h"

#include <iostream>
#include <ostream>

// Compile command:  g++ primitive.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -std=c++17

const int WIDTH = 900;
const int HEIGHT = 600;

void drawPulsingSquare(float posX, float posY, raylib::Color color)
{
  static float length = 80;
  static float sizeChange = 3.0f;

  if (length > 100)
  {
    sizeChange = -1.0f;
  }
  else if (length < 80)
  {
    sizeChange = 3.0f;
  }

  length += sizeChange;

  DrawRectangleRec(raylib::Rectangle{posX - length / 2, posY - length / 2, length, length}, color);
}

void drawRotateRectangle(float posX, float posY, raylib::Color color)
{
  static float recWidth = 60.0f;
  static float recHeight = 50.0f;
  static float rotationAngle = 0.0f;
  static float sizeChange = 3.0f;

  recWidth += sizeChange;
  recHeight += sizeChange;

  if (recWidth > 120 || recWidth < 60)
  {
    sizeChange *= -1.0f;
  }

  rotationAngle += 1.5f;
  DrawRectanglePro(raylib::Rectangle{posX, posY, recWidth, recHeight}, raylib::Vector2{recHeight / 10, recWidth / 3},
                   rotationAngle, color);
}

int main()
{
  raylib::Window window(WIDTH, HEIGHT, "Raylib Tutorial 2");

  SetTargetFPS(60);

  while (!window.ShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();

    raylib::Color::RayWhite.ClearBackground();

    // use static so that updates at each loop is "remembered"
    static int xPosition = 200;
    static int step = -5;

    if (xPosition < 10 || xPosition > 600) // change direction at border
    {
      step *= -1;
    }

    xPosition += step;
    DrawText("Rip And Tear", xPosition, 20, 30, raylib::Color::Maroon);

    drawPulsingSquare(100, 200, raylib::Color::Blue);

    drawRotateRectangle(500, 200, raylib::Color::Maroon);

    EndDrawing();
  }

  return 0;
}
