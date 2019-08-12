/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#include "color.h"
#include "definitions.h"



Color::Color(const unsigned char r /*= 0*/, const unsigned char g /*= 0*/, const unsigned char b /*= 0*/, const unsigned char a /*= 0*/)
{
  rgba[0] = r;
  rgba[1] = g;
  rgba[2] = b;
  rgba[3] = a;
}

Color& Color::operator+(const Color& other)
{
  rgba[0] += other.rgba[0];
  rgba[1] += other.rgba[1];
  rgba[2] += other.rgba[2];
  rgba[3] += other.rgba[3];
  return *this;
}



void Color::toString()
{
  std::cout << "RGBA(" << (uint16_t)rgba[0] << ", " << (uint16_t)rgba[1] << ", " << (uint16_t)rgba[2] << ", " << (uint16_t)rgba[3] << ")" << std::endl;
}
