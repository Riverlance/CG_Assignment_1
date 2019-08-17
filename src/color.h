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
    Color(uint8_t r, uint8_t g, uint8_t b) : rgba{ r, g, b, 0xFF } {}
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : rgba{ r, g, b, a } {}
    Color(const Color& color)
    {
      std::copy(std::begin(color.rgba), std::end(color.rgba), std::begin(rgba));
    }



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



    inline uint_fast8_t getR() const { return rgba[0]; }
    inline uint_fast8_t getG() const { return rgba[1]; }
    inline uint_fast8_t getB() const { return rgba[2]; }
    inline uint_fast8_t getA() const { return rgba[3]; }
    inline uint_fast8_t getRGBA(uint_fast8_t i) const { return rgba[i]; }

    inline void setR(uint_fast8_t r) { rgba[0] = r; }
    inline void setG(uint_fast8_t g) { rgba[1] = g; }
    inline void setB(uint_fast8_t b) { rgba[2] = b; }
    inline void setA(uint_fast8_t a) { rgba[3] = a; }
    inline void setRGB(uint_fast8_t r = 0x00, uint_fast8_t g = 0x00, uint_fast8_t b = 0x00)
    {
      rgba[0] = r;
      rgba[1] = g;
      rgba[2] = b;
    }
    inline void setRGBA(uint_fast8_t r = 0x00, uint_fast8_t g = 0x00, uint_fast8_t b = 0x00, uint_fast8_t a = 0xFF)
    {
      rgba[0] = r;
      rgba[1] = g;
      rgba[2] = b;
      rgba[3] = a;
    }

    inline void addRGB(uint_fast8_t r = 0x00, uint_fast8_t g = 0x00, uint_fast8_t b = 0x00)
    {
      rgba[0] += r;
      rgba[1] += g;
      rgba[2] += b;
    }
    inline void addRGBA(uint_fast8_t r = 0x00, uint_fast8_t g = 0x00, uint_fast8_t b = 0x00, uint_fast8_t a = 0xFF)
    {
      rgba[0] += r;
      rgba[1] += g;
      rgba[2] += b;
      rgba[3] += a;
    }



    inline void setRandomGreyScale(uint_fast8_t alpha = 0xFF)
    {
      uint_fast8_t lightnessColor = (uint_fast8_t)getRandom(0x00, 0xFF);
      rgba[0] = lightnessColor;
      rgba[1] = lightnessColor;
      rgba[2] = lightnessColor;
      rgba[3] = alpha;
    }
    inline void setRandomRGBA(uint_fast8_t alpha = 0xFF)
    {
      rgba[0] = (uint_fast8_t)getRandom(0x00, 0xFF);
      rgba[1] = (uint_fast8_t)getRandom(0x00, 0xFF);
      rgba[2] = (uint_fast8_t)getRandom(0x00, 0xFF);
      rgba[3] = alpha;
    }



  private:
    uint8_t rgba[4] = { 0x00, 0x00, 0x00, 0xFF};
};

std::ostream& operator<<(std::ostream& os, const Color& obj);

#endif
