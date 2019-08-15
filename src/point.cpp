/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#include "point.h"
#include "core\base\definitions.h"



Point::Point(const int x /*= 0*/, const int y /*= 0*/)
{
  this->x = x;
  this->y = y;
  this->color = Color(0, 0, 0, 0);
}

Point::Point(const Color color, const int x /*= 0*/, const int y /*= 0*/)
{
  this->x = x;
  this->y = y;
  this->color = color;
}



bool Point::isValid() const
{
  return x >= 0 && x <= SCREEN_WIDTH && y >= 0 && y <= SCREEN_HEIGHT;
}

int Point::getMemoryPosition()
{
  return (x + y * SCREEN_WIDTH) * 4;
}

void Point::toString()
{
  std::cout << "XY(" << x << ", " << y << ")" << std::endl;
  //color.toString();
}
