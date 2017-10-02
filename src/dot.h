#pragma once
#include "point.h"

class Dot{
public:
  Point position;

  Dot(Point position, int direction);

  int GetDirection() { return direction; }

  void PointTo(int direction); // also sets vector
  void PointTo(Point vDir); // also sets clock
  void Turn(int turns); // quarter turns clockwise

  void Move() { position += vDir; } // travel one space in vDir

  bool IsHorizontal() { return (this->direction & 1) == 1; } // odd clock
  bool IsVertical() { return (this->direction & 1) == 0; } // even clock

private:
  int direction; // clock direction (0 up, 1 right, 2 down, 3 left)
  Point vDir { 0, 0 }; // vector direction (x, y)
};
