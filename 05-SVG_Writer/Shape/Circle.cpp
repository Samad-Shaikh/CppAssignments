#include "Circle.h"

Circle::Circle(double x, double y, double radius)
          : m_x(x), m_y(y), m_radius(radius){}

void Circle::printSVGOn(std::ostream &out) const {
  out << "<circle "
      << "cx=\"" << m_x << "\" "
      << "cy=\"" << m_y << "\" "
      << "r=\"" << m_radius << "\" "
      << "stroke=\"black\" "
      << "strokewidth=\"1\" "
      << "fill=\"white\" "
      << "/>" << std::endl;
}

BoundingBox Circle::getBounds() const {
  return createBounds(
          m_x - m_radius,
          m_y - m_radius,
          m_x + m_radius,
          m_x + m_radius
          );
}

bool Circle::isCircle() const {
  return true;
}
