#include "Shape.h"

BoundingBox createBounds(double minX, double minY, double maxX, double maxY){
  return {minX, minY, maxX, maxY};
}

Shape::Shape() = default;

Shape::~Shape() = default;

bool Shape::isCircle() const {
  return false;
}

bool Shape::isLine() const {
  return false;
}