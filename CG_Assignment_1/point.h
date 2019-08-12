/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#ifndef POINT_H
#define POINT_H

#include "color.h"
#include "definitions.h"



class Point
{
  public:
    Point(const int x = 0, const int y = 0);
    Point(const Color color, const int x = 0, const int y = 0);



    bool isValid() const;
    int getMemoryPosition();



    void toString();



    int x;
    int y;
    Color color;
};

#endif
