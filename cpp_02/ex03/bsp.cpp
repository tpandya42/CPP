#include "Point.hpp"

float	areaTri(Point a, Point b, Point c) {
  float x0 = a.get_x().toFloat();
  float x1 = b.get_x().toFloat();
  float x2 = c.get_x().toFloat();
  float y0 = a.get_y().toFloat();
  float y1 = b.get_y().toFloat();
  float y2 = c.get_y().toFloat();
  float result = (x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1)) / 2;
  result = fabs(result);
  return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  float const A1 = areaTri(a, b, point);
  float const A2 = areaTri(a, c, point);
  float const A3 = areaTri(c, b, point);
  float const Total = areaTri(a, b, c);

  if (!A1 || !A2 || !A3)
    return false;
  else if (A1 + A2 + A3 == Total)
    return true;
  else
    return false;
}
