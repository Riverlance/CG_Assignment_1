/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#ifndef COLOR_H
#define COLOR_H

#include "core\base\definitions.h"
#include "core\base\global.h"



struct Color
{
  public:
    Color() = default;
    Color(unsigned char r, unsigned char g, unsigned char b) : rgba{ r, g, b, 0x00 } {}
    Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : rgba{ r, g, b, a } {}



    bool operator==(const Color& color) const
    {
      return rgba[0] == color.rgba[0] && rgba[1] == color.rgba[1] && rgba[2] == color.rgba[2] /*&& rgba[3] == color.rgba[3]*/;
    }

    bool operator!=(const Color& color) const
    {
      return rgba[0] != color.rgba[0] || rgba[1] != color.rgba[1] || rgba[2] != color.rgba[2] /*|| rgba[3] != color.rgba[3]*/;
    }

    Color& operator+(const Color& color)
    {
      return Color(rgba[0] + color.rgba[0], rgba[1] + color.rgba[1], rgba[2] + color.rgba[2], rgba[3] /*+ color.rgba[3]*/);
    }

    Color& operator-(const Color& color)
    {
      return Color(rgba[0] - color.rgba[0], rgba[1] - color.rgba[1], rgba[2] - color.rgba[2], rgba[3] /*- color.rgba[3]*/);
    }



    inline unsigned char getR() const { return rgba[0]; }
    inline unsigned char getG() const { return rgba[1]; }
    inline unsigned char getB() const { return rgba[2]; }
    inline unsigned char getA() const { return rgba[3]; }
    inline unsigned char getRGBA(uint_fast8_t i) const { return rgba[i]; }

    inline void setR(unsigned char r) { rgba[0] = r; }
    inline void setG(unsigned char g) { rgba[1] = g; }
    inline void setB(unsigned char b) { rgba[2] = b; }
    inline void setA(unsigned char a) { rgba[3] = a; }
    inline void setRGB(unsigned char r = 0x00, unsigned char g = 0x00, unsigned char b = 0x00)
    {
      rgba[0] = r;
      rgba[1] = g;
      rgba[2] = b;
    }
    inline void setRGBA(unsigned char r = 0x00, unsigned char g = 0x00, unsigned char b = 0x00, unsigned char a = 0x00)
    {
      rgba[0] = r;
      rgba[1] = g;
      rgba[2] = b;
      rgba[3] = a;
    }



  private:
    unsigned char rgba[4] = {};
};

std::ostream& operator<<(std::ostream& os, const Color& obj);

#endif
