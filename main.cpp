#include "Shape.hpp"

int main() {
  Window w(51, 21);
  Point ps = Point(0, 25);
  Point pd = Point(10, 15);
  Line sll = Line(ps, pd);
  Line slr = Line(sll.getPs(), Point(10, 35));
  Line sl =  Line(sll.getPd(), slr.getPd());
  Rectangle rect = Rectangle(sl.getPs(), Point(sl.getPd().x + 10,
					       sl.getPd().y));
  Line ll = Line(slr.c(), Point(0, slr.c().y));
  Line ll1 = Line(ll.getPd(), Point(0, slr.getPd().y));
  Line ll2 = Line(ll1.getPd(), slr.getPd());
  Dot d1 = Dot(sll.getPd());
  Dot d2 = Dot(slr.getPd());
  Rectangle winl = Rectangle(Point(d1.se().x+1, d1.se().y+2),
			     Point(d1.se().x+3, d1.se().y+6));
  Rectangle winr = Rectangle(Point(d2.sw().x+1, d2.sw().y-2),
			     Point(d2.sw().x+3, d2.sw().y-6));
  Rectangle door = Rectangle(Point(winl.getPd().x+2, winl.getPd().y),
			     Point(winr.getPd().x+6, winr.getPd().y));
  w.draw(door);
  w.draw(winr);
  w.draw(winl);
  w.draw(ll2);
  w.draw(ll1);
  w.draw(ll);
  w.draw(rect);
  w.draw(sl);
  w.draw(sll);
  w.draw(slr);
  w.show();
}

