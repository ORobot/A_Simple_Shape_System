#include "Shape.hpp"

Point Dot::e() {
  return Point(p.x, p.y+1);
}

Point Dot::w() {
  return Point(p.x, p.y - 1);
}

Point Dot::n() {
  return Point(p.x - 1, p.y);
}

Point Dot::s() {
  return Point(p.x + 1, p.y);
}

Point Dot::ne() {
  return Point(p.x - 1, p.y + 1);
}

Point Dot::nw() {
  return Point(p.x - 1, p.y - 1);
}

Point Dot::se() {
  return Point(p.x + 1, p.y + 1);
}

Point Dot::sw() {
  return Point(p.x + 1, p.y - 1);
}

Point Dot::c() {
  return Point(p);
}

Point Dot::getPs() const {
  return Point(p);
}

Point Dot::getPd() const {
  return Point(p);
}
