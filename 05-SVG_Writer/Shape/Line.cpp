#include "Line.h"

Line::Line(double x1, double y1, double x2, double y2, double width)
        : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_width(width){
}

void Line::printSVGOn(std::ostream &out) const {
  out << "<line "
      << "x1=\"" << m_x1 << "\" "
      << "y1=\"" << m_y1 << "\" "
      << "x2=\"" << m_x2 << "\" "
      << "y2=\"" << m_y2 << "\" "
      << "style=\"stroke:rgb(255,0,0);stroke-width:" << m_width << "\""
      << "/>" << std::endl;
}

BoundingBox Line::getBounds() const {
  return createBounds(
          std::min(m_x1, m_x2),
          std::min(m_y1, m_y2),
          std::max(m_x1, m_x2),
          std::max(m_y1, m_y2)
          );
}

bool Line::isLine() const {
  return true;
}
