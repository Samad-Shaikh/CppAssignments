#ifndef SVG_FIGURE_H
#define SVG_FIGURE_H

#include <vector>
#include <memory>
#include "Shape/Shape.h"

typedef std::vector<std::shared_ptr<Shape>> Figure;
typedef struct ShapeCount {
  int circles;
  int lines;
} ShapeCount;

extern ShapeCount countShapes(const Figure &figure);

extern Figure loadFigure(const std::string &filename);

extern void renderFigure(const Figure &figure, const std::string &filename);

#endif //SVG_FIGURE_H
