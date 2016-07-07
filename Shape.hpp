#ifndef __SHAPE__
#define __SHAPE__

#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

struct Point {
  int x;
  int y;
  Point() { x = 0; y = 0; }
  Point(int xx, int yy) { x = xx; y = yy;}
  Point(const Point& p) { x = p.x; y = p.y; }
};


class Shape {
public:
  virtual Point e() = 0;
  virtual Point w() = 0;
  virtual Point n() = 0;
  virtual Point s() = 0;
  virtual Point ne() = 0;
  virtual Point nw() = 0;
  virtual Point se() = 0;
  virtual Point sw() = 0;
  virtual Point c() = 0;
  virtual Point getPs() const = 0;
  virtual Point getPd() const = 0;
  virtual vector<Point> getPoint() const = 0;
  virtual ~Shape() {}
};

class Dot : public Shape {
public:
  Dot(Point pp) : p(pp) {}
  ~Dot() {}
  Point e();
  Point w();
  Point n();
  Point s();
  Point ne();
  Point nw();
  Point se();
  Point sw();
  Point c();
  Point getPs() const;
  Point getPd() const;
  vector<Point> getPoint() const {};

private:
  Point p;
};

class Line : public Shape {
public:
  Line(Point pps, Point ppd);
  ~Line() { delete Pvec; }
  Point e();
  Point w();
  Point n();
  Point s();
  Point ne();
  Point nw();
  Point se();
  Point sw();
  Point c();
  Point getPs() const;
  Point getPd() const;
  vector<Point> getPoint() const;

private:
  Point ps;
  Point pd;
  int wl;
  vector<Point>* Pvec;
};

class Rectangle : public Shape {
public:
  Rectangle(Point lp, Point rp);
  ~Rectangle() { delete Pvec; }
  Point e();
  Point w();
  Point n();
  Point s();
  Point ne();
  Point nw();
  Point se();
  Point sw();
  Point c();
  Point getPs() const;
  Point getPd() const;
  vector<Point> getPoint() const;

private:
  Point ps;
  Point pd;
  Line widthl;
  Line widthr;
  Line lengthu;
  Line lengthd;
  vector<Point>* Pvec;
};

class Circle : public Rectangle {

public:
  Circle(Point cp, int r);
  ~Circle() {  }
  /*
  Point e();
  Point w();
  Point s();
  Point n();
  Point ne();
  Point nw();
  Point se();
  Point sw();
  Point c();
  Point getPs() const;
  Point getPd() const;
  vector<Point>* getPoint() const;
  */
};

class Window {
public:
  Window(int w, int l);
  ~Window() {}
  Point current() const;
  Point current(const Point& p);
  int getWidth() const;
  int getLength() const;
  void draw(Shape& s);
  void show() const;

private:
  int width;
  int length;
  Point cur;
  string str;
  vector<string> lvec;
};

#endif
