/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#ifndef COLOR_H
#define COLOR_H



#include "definitions.h"



class Color
{
  public:
    Color(const unsigned char r = 0, const unsigned char g = 0, const unsigned char b = 0, const unsigned char a = 0);

    Color& operator+(const Color& color);



    void toString();

    unsigned char rgba[4];
};

#endif
