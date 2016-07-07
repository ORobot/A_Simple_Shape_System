#include "Shape.hpp"

Window::Window(int w, int l) :
  cur(0, 0), str(w, ' '), lvec(l, str)		       
{
  width = w;
  length = l;
}

Point Window::current() const {
  return cur;
}

Point Window::current(const Point& p) {
  cur.x = p.x;
  cur.y = p.y;
  return this->cur;
}

int Window::getWidth() const {
  return width;
}

int Window::getLength() const {
  return length;
}

void Window::draw(Shape& s) {
  vector<Point> Pts = s.getPoint();
  for(auto d : Pts) {
    lvec[d.x][d.y] = '-';
  }
  cur = s.getPd();
}

void Window::show() const {
  for(auto l : lvec) {
    cout << l << endl;
  }
}
