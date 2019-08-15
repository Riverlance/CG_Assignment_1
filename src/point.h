/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#ifndef POINT_H
#define POINT_H

#include "color.h"
#include "core\base\definitions.h"



struct Point
{
  public:
    Point() = default;
    Point(uint16_t x, uint16_t y) : x(x), y(y) {};
    Point(uint16_t x, uint16_t y, const Color& color) : x(x), y(y), color(color) {};



    bool operator==(const Point& point) const
    {
      return x == point.x && y == point.y;
    }

    bool operator!=(const Point& point) const
    {
      return x != point.x || y != point.y;
    }

    Point operator+(const Point& point)
    {
      return Point(x + point.x, y + point.y, color + point.color);
    }

    Point& operator-(const Point& point)
    {
      return Point(x - point.x, y - point.y, color - point.color);
    }

    bool operator<(const Point& point) const
    {
      if (y < point.y)
        return true;
      if (y > point.y)
        return false;

      if (x < point.x)
        return true;
      if (x > point.x)
        return false;

      return false;
    }

    bool operator>(const Point& point) const
    {
      if (y > point.y)
        return true;
      if (y < point.y)
        return false;

      if (x > point.x)
        return true;
      if (x < point.x)
        return false;

      return false;
    }



    inline static int_fast32_t getOffsetX(const Point& point1, const Point& point2)
    {
      return point1.getX() - point2.getX();
    }
    inline static int_fast32_t getOffsetY(const Point& point1, const Point& point2)
    {
      return point1.getY() - point2.getY();
    }

    inline static int32_t getDistanceX(const Point& point1, const Point& point2)
    {
      return std::abs(Point::getOffsetX(point1, point2));
    }
    inline static int32_t getDistanceY(const Point& point1, const Point& point2)
    {
      return std::abs(Point::getOffsetY(point1, point2));
    }

    template<int_fast32_t deltax, int_fast32_t deltay>
    inline static bool areInRange(const Point& point1, const Point& point2)
    {
      return Point::getDistanceX(point1, point2) <= deltax && Point::getDistanceY(point1, point2) <= deltay;
    }



    inline uint_fast16_t getX() const { return x; }
    inline uint_fast16_t getY() const { return y; }
    inline Color& getColor() { return color; }
    inline const Color& getColor() const { return color; }

    inline void setX(uint_fast16_t x) { this->x = x; }
    inline void setY(uint_fast16_t y) { this->y = y; }
    inline void setXY(uint_fast16_t x, uint_fast16_t y)
    {
      this->x = x;
      this->y = y;
    }
    inline void setColor(const Color& color) { this->color = color; }



    inline bool isValid() const
    {
      return x >= 0 && x <= SCREEN_WIDTH && y >= 0 && y <= SCREEN_HEIGHT;
    }
    inline uint_fast16_t getMemoryPosition()
    {
      return (x + y * SCREEN_WIDTH) * 4;
    }



  private:

    uint16_t x = 0;
    uint16_t y = 0;
    Color color;
};

std::ostream& operator<<(std::ostream& os, const Point& obj);

#endif
