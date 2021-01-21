#include <limits>
#include <fstream>
#include "Figure.h"
#include "Shape/Line.h"
#include "Shape/Circle.h"

ShapeCount countShapes(const Figure &figure){
  ShapeCount count{0, 0};
  for(const std::shared_ptr<Shape> &shape : figure) {
    if(shape->isCircle()) {
      ++count.circles;
    } else if(shape->isLine()) {
      ++count.lines;
    }
  }
  return count;
}

void addLine(Figure &shapes, double fromX, double fromY, double toX, double toY, double width){
  std::shared_ptr<Line> line = std::make_shared<Line>(fromX, fromY, toX, toY, width);
  shapes.push_back(line);
}

void addCircle(Figure &shapes, double x, double y, double radius) {
  std::shared_ptr<Circle> circle = std::make_shared<Circle>(x, y, radius);
  shapes.push_back(circle);
}

double readDouble(std::ifstream &input) {
  double value;
  input >> value;
  if(input.eof()) {
    throw std::runtime_error("Unexpected EOF");
  }
  if(input.fail()) {
    throw std::runtime_error("Failed to parse File");
  }
  return value;
}

BoundingBox getFigureBounds(const Figure &figure){
  double max = std::numeric_limits<double>::max();
  double min = std::numeric_limits<double>::lowest();
  BoundingBox figureBounds = createBounds(max, max, min, min);
  for(const auto &shape: figure){
    struct BoundingBox shapeBounds = shape->getBounds();
    figureBounds.minX = std::min(figureBounds.minX, shapeBounds.minX);
    figureBounds.minY = std::min(figureBounds.minY, shapeBounds.minY);
    figureBounds.maxX = std::min(figureBounds.maxX, shapeBounds.maxX);
    figureBounds.maxY = std::min(figureBounds.maxY, shapeBounds.maxY);
  }
  return figureBounds;
}

Figure loadFigure(const std::string &fileName){
  Figure shapes;
  std::ifstream input(fileName);
  if(!input.is_open()) {
    throw std::runtime_error("Failed to open file");
  }
  for(;;) {
    std::string shapeType;
    input >> shapeType;
    if(input.eof()) break;
    if(input.fail()) throw std::runtime_error("Failed to parse shape type");
    if(shapeType == "circle") {
      double x = readDouble(input), y = readDouble(input), radius = readDouble(input);
      addCircle(shapes, x, y, radius);
    } else if(shapeType == "line") {
      double fromX = readDouble(input), fromY = readDouble(input);
      double toX = readDouble(input), toY = readDouble(input);
      double width = readDouble(input);
      addLine(shapes, fromX, fromY, toX, toY, width);
    } else {
      throw std::runtime_error("Unknown Shape");
    }
  }
  return shapes;
}

void renderFigure(const Figure &figure, const std::string &fileName){
  std::ofstream output(fileName);
  if(!output.is_open()) {
    throw std::runtime_error("Failed to open SVG file");
  }
  BoundingBox figureBounds = getFigureBounds(figure);
  output << R"(<?xml version="1.0"?>
  <!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">
  <svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" viewbox=")"
         << figureBounds.minX << " "
         << figureBounds.minY << " "
         << (figureBounds.maxX - figureBounds.minX) << " "
         << (figureBounds.maxY - figureBounds.minY) << "\">"
         << std::endl;
  for(const auto &shape: figure) {
    shape->printSVGOn(output);
  }
  output << "</svg>" << std::endl;
}