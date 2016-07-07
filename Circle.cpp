#include "Shape.hpp"

Circle::Circle(Point cp, int r) :
  Rectangle(Point(cp.x - r, cp.y-r), Point(cp.x+r, cp.y+r))
{
  
  
}

