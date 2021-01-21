#ifndef SVG_CIRCLE_H
#define SVG_CIRCLE_H


#include "Shape.h"

class Circle : public Shape {
private:
  double m_x, m_y, m_radius;

public:
  Circle(double x, double y, double radius);

  bool isCircle() const override;

  void printSVGOn(std::ostream &out) const override;

  struct BoundingBox getBounds() const override;

};


#endif //SVG_CIRCLE_H
