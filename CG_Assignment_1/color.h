/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#ifndef COLOR_H
#define COLOR_H

#include "definitions.h"
#include "global.h"



struct Color
{
  public:
    Color() = default;
    Color(const unsigned char r, const unsigned char g, const unsigned char b) : rgba{ r, g, b, 0x00 } {}
    Color(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) : rgba{ r, g, b, a } {}

    bool operator==(const Color& color) const {
      return rgba[0] == color.rgba[0] && rgba[1] == color.rgba[1] && rgba[2] == color.rgba[2] /*&& rgba[3] == color.rgba[3]*/;
    }

    bool operator!=(const Color& color) const {
      return rgba[0] != color.rgba[0] && rgba[1] != color.rgba[1] && rgba[2] != color.rgba[2] /*&& rgba[3] != color.rgba[3]*/;
    }

    Color& operator+(const Color& p1) {
      rgba[0] += p1.rgba[0];
      rgba[1] += p1.rgba[1];
      rgba[2] += p1.rgba[2];
      rgba[3] += p1.rgba[3];
      return *this;
    }

    Color& operator-(const Color& p1) {
      rgba[0] -= p1.rgba[0];
      rgba[1] -= p1.rgba[1];
      rgba[2] -= p1.rgba[2];
      rgba[3] -= p1.rgba[3];
      return *this;
    }

    inline const unsigned char getR() const { return rgba[0]; }
    inline const unsigned char getG() const { return rgba[1]; }
    inline const unsigned char getB() const { return rgba[2]; }
    inline const unsigned char getA() const { return rgba[3]; }
    inline const unsigned char getRGBA(uint_fast8_t i) const { return rgba[i]; }
    inline void setR(const unsigned char r) { rgba[0] = r; }
    inline void setG(const unsigned char g) { rgba[1] = g; }
    inline void setB(const unsigned char b) { rgba[2] = b; }
    inline void setA(const unsigned char a) { rgba[3] = a; }
    inline void setRGB(const unsigned char r = 0x00, const unsigned char g = 0x00, const unsigned char b = 0x00)
    {
      rgba[0] = r;
      rgba[1] = g;
      rgba[2] = b;
    }
    inline void setRGBA(const unsigned char r = 0x00, const unsigned char g = 0x00, const unsigned char b = 0x00, const unsigned char a = 0x00)
    {
      rgba[0] = r;
      rgba[1] = g;
      rgba[2] = b;
      rgba[3] = a;
    }



  private:
    unsigned char rgba[4];
};

std::ostream& operator<<(std::ostream& os, const Color& obj);

#endif
