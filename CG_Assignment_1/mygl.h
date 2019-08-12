/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#ifndef MYGL_H
#define MYGL_H

// #include <GL/gl.h>
// #include <GL/glu.h>
#include <GL/glut.h>
#include "point.h"



#define GL_CLAMP_TO_EDGE 0x812F



class MyGL
{
  public:
    // Initialize variables
    MyGL(int* argc, char* argv[]);

    // Deallocate memory
    ~MyGL();

    // Prevent clone this object
    MyGL(const MyGL&) = delete; // Prevent construction by copying
    MyGL& operator=(const MyGL&) = delete; // Prevent assignment

    /**
      * Singleton implementation.
      */
    static MyGL* getInstance(int* argc, char* argv[])
    {
      static MyGL instance(argc, argv);
      return &instance;
    };



    // Draw
    static void drawPoint(Point point);
    static void drawLine(Point initialPoint, Point finalPoint);
    static void drawTriangle(Point pointA, Point pointB, Point pointC);
};

#endif
