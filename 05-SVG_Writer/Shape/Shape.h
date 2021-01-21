#ifndef SVG_SHAPE_H
#define SVG_SHAPE_H

#include <ostream>

typedef struct BoundingBox {
  double minX;
  double minY;
  double maxX;
  double maxY;
} BoundingBox;

extern BoundingBox createBounds(double minX, double minY, double maxX, double maxY);

class Shape {
public:
  Shape();

  virtual ~Shape();

  virtual bool isCircle() const;

  virtual bool isLine() const;

  virtual void printSVGOn(std::ostream &out) const = 0; // 0 -> abstract

  virtual BoundingBox getBounds() const = 0;
};

#endif //SVG_SHAPE_H
