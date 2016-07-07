#include "Shape.hpp"

Line::Line(Point pps, Point ppd) :
  ps(pps), pd(ppd), Pvec(0)
{
  int max = ps.x < pd.x ? pd.x : ps.x;
  wl = max - (ps.x + pd.x) / 2;
  
  int sz;
  if ( ps.x < pd.x) {
    sz = pd.x - ps.x;
    Pvec = new vector<Point>(sz, Point(0,0));

    int i = ps.x;
    for (auto& P : *Pvec)      
      P.x = i++;
    
    if (ps.y < pd.y) {
      
      int i = ps.y;
      for (auto& P : *Pvec) 
	P.y = i++;
      
    } else if (ps.y > pd.y) {

      int i = ps.y;
      for (auto& P : *Pvec) 
	P.y = i--;
      
    } else {
      for (auto& P : *Pvec)
	P.y = ps.y;
    }
    
  } else if (ps.x > pd.x) {
    sz = ps.x - pd.x;
    Pvec = new vector<Point>(sz, Point(0,0));
    int i = ps.x;
    for (auto& P : *Pvec) 
       P.x = i--;

    if (ps.y < pd.y) {
      
      int i = ps.y;
      for (auto& P : *Pvec) 
	P.y = i++;
      
    } else if (ps.y > pd.y) {

      int i = ps.y;
      for (auto& P : *Pvec) 
	P.y = i--;
      
    } else {
      for (auto& P : *Pvec)
	P.y = ps.y;
    }
    
  } else {
    
    if (ps.y < pd.y) {

      sz = pd.y - ps.y + 1;
      Pvec = new vector<Point>(sz, Point(0,0));

      for(auto& P : *Pvec)
	P.x = ps.x;
      
      int i = ps.y;
      for (auto& P : *Pvec) 
	P.y = i++;
      
    } else if (ps.y > pd.y) {

      sz = ps.y - pd.y + 1;
      Pvec = new vector<Point>(sz, Point(0,0));

      for(auto& P : *Pvec)
	P.x = ps.x;

      int i = ps.y;
      for (auto& P : *Pvec) 
	P.y = i--;
    } 
  }

}

Point Line::e() {
  Point tp = c();
  tp.y += wl;
  return tp;
}

Point Line::w() {
  Point tp = c();
  tp.y -= wl;
  return tp;
}

Point Line::n() {
  Point tp = c();
  tp.x -= wl;
  return tp;
}

Point Line::s() {
  Point tp = c();
  tp.x += wl;
  return tp;
}

Point Line::ne() {
  Point tp = c();
  tp.x -= wl;
  tp.y += wl;
  return tp;
}

Point Line::nw() {
  Point tp = c();
  tp.x -= wl;
  tp.y -= wl;
  return tp;
}

Point Line::se() {
  Point tp = c();
  tp.x += wl;
  tp.y += wl;
}

Point Line::sw() {
  Point tp = c();
  tp.x += wl;
  tp.y -= wl;
  return tp;
}

Point Line::c() {
  Point tp;
  tp.x = (ps.x + pd.x) / 2;
  tp.y = (ps.y + pd.y) / 2;
  return tp;
}


Point Line::getPs() const {
  return ps;
}

Point Line::getPd() const {
  return pd;
}

vector<Point> Line::getPoint() const {
  return *Pvec;
}
