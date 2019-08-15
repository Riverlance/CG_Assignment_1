/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#include "point.h"
#include "core\base\definitions.h"



std::ostream& operator<<(std::ostream& os, const Point& point)
{
  os << "Point";

  // Position
  os << "(" << std::setw(5) << std::setfill('0') << std::dec << point.getX();
  os << ", " << std::setw(5) << std::setfill('0') << std::dec << point.getY();
  os << ")";

  os << ":";

  // Color
  const Color& color = point.getColor();
  os << point.getColor();

  return os;
}
