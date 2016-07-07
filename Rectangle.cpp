#include "Shape.hpp"

Rectangle::Rectangle(Point lp, Point rp) :
  ps(lp), pd(rp),
  widthl(lp, Point(rp.x, lp.y)), widthr(Point(lp.x, rp.y), rp),
  lengthu(lp, Point(lp.x, rp.y)), lengthd(Point(rp.x, lp.y), rp),
  Pvec(0)
{
  int sz;
  sz = (widthr.getPoint().size() + lengthu.getPoint().size()) * 2;

  Pvec = new vector<Point>(sz, Point(0,0));
  int i = 0;
  for(auto p : widthl.getPoint())
    (*Pvec)[i++] = p;
  for(auto p: widthr.getPoint())
    (*Pvec)[i++] = p;
  for(auto p : lengthu.getPoint())
    (*Pvec)[i++] = p;
  for(auto p : lengthd.getPoint())
    (*Pvec)[i++] = p;
}

Point Rectangle::e() {
  return widthr.c();
}

Point Rectangle::w() {
  return Point(widthl.c());
}

Point Rectangle::n() {
  return lengthu.c();
}

Point Rectangle::s() {
  return lengthd.c();
}

Point Rectangle::ne() {
  return widthr.getPs();
}

Point Rectangle::nw() {
  return widthl.getPs();
}

Point Rectangle::se() {
  return widthr.getPd();
}

Point Rectangle::sw() {
  return widthl.getPd();
}

Point Rectangle::c() {
  return widthl.e();
}

Point Rectangle::getPs() const {
  return Point(ps);
}

Point Rectangle::getPd() const {
  return Point(pd);
}

vector<Point> Rectangle::getPoint() const {
  return *Pvec;
}
