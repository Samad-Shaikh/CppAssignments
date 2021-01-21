#ifndef SVG_LINE_H
#define SVG_LINE_H


#include "Shape.h"

class Line : public Shape{
private:
  double m_x1, m_y1;
  double m_x2, m_y2;
  double m_width;
public:
  Line(double x1, double y1, double x2, double y2, double width);

  bool isLine() const override;

  void printSVGOn(std::ostream &out) const override;

  struct BoundingBox getBounds() const override;
};


#endif //SVG_LINE_H
