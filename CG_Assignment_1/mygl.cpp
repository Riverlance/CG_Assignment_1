/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#include "mygl.h"
#include "definitions.h"



GLuint texture;

void(*drawCallback)(void);

unsigned char *frameBuffer;



void draw()
{
  Point pointA;
  Point pointB;

  pointA.x = 255;
  pointA.y = 0;

  pointB.x = 0;
  pointB.y = 255;
  
  for (int i = 1; i < 51; i++)
  {
    MyGL::drawPoint(pointA);
    MyGL::drawPoint(pointB);

    pointA.y += 10;
    pointB.x += 10;
    
    if (i > 18 && i < 33)
    {
      // Red
      pointA.color.rgba[0] = 255;
      pointA.color.rgba[1] = 0;
      pointA.color.rgba[2] = 0;
      pointA.color.rgba[3] = 0;

      // Red
      pointB.color.rgba[0] = 255;
      pointB.color.rgba[1] = 0;
      pointB.color.rgba[2] = 0;
      pointB.color.rgba[3] = 0;
    }
    else
    {
      // Yellow
      pointA.color.rgba[0] = 255;
      pointA.color.rgba[1] = 255;
      pointA.color.rgba[2] = 0;
      pointA.color.rgba[3] = 0;

      // Yellow
      pointB.color.rgba[0] = 255;
      pointB.color.rgba[1] = 255;
      pointB.color.rgba[2] = 0;
      pointB.color.rgba[3] = 0;
    }
  }
}

void onExitApplication()
{
  // Free frameBuffer memory
  if (!frameBuffer)
    delete[] frameBuffer;

  std::clog << "Exiting..." << std::endl;
}

void onDisplay()
{
  // Custom function to draw
  draw();

  // Copy frameBuffer into texture
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, SCREEN_WIDTH, SCREEN_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, frameBuffer);

  // Enable 2D texture
  glEnable(GL_TEXTURE_2D);

  // Draw the quad with the mapped texture
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // Set background color
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  // Set view port
  glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

  glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
  glEnd();

  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);

  // Flush memory
  glFlush();

  glutSwapBuffers();
  glutPostRedisplay();
}



MyGL::MyGL(int* argc, char* argv[])
{
  /* Glut */

  glutInit(argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
  glutInitWindowPosition(0, 0); // 100, 100
  glutCreateWindow("My OpenGL");



  /* OpenGL */

  glMatrixMode(GL_PROJECTION); // Initialize the Projection matrix
  glLoadIdentity();
  glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

  glMatrixMode(GL_MODELVIEW); // Initialize the ModelView matrix
  glLoadIdentity();

  //Check for error
  GLenum error = glGetError();
  if (error != GL_NO_ERROR)
  {
    std::cerr << "Error initializing OpenGL!\nOpenGL error: " << gluErrorString(error);
    return;
  }



  /* Callbacks */

  // Set exit callback
  atexit(onExitApplication);

  // Set display callback
  glutDisplayFunc(onDisplay);



  /* Init data structs */

  // Allocate framebuffer and initializes its position with 0
  frameBuffer = new unsigned char[SCREEN_WIDTH * SCREEN_HEIGHT * 5];

  for (unsigned int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
  {
    unsigned int position = i * 4;
    frameBuffer[position] = 0;
    frameBuffer[position + 1] = 0;
    frameBuffer[position + 2] = 0;
    frameBuffer[position + 3] = 255;
  }

  // Create a 2D texture, RGBA (8 bits per component)
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBindTexture(GL_TEXTURE_2D, 0);



  /* Loop */

  // Framebuffer scan loop
  glutMainLoop();
}

MyGL::~MyGL()
{
  // Nothing
}



void MyGL::drawPoint(Point point)
{
  if (!point.isValid())
  {
    //std::cerr << "Point of coordinates XY(" << point.x << ", " << point.y << ")" << std::endl;
    return;
  }

  int memoryPosition = point.getMemoryPosition();
  for (int i = 0; i < 4; i++)
    frameBuffer[memoryPosition++] = point.color.rgba[i];
}

void MyGL::drawLine(Point initialPoint, Point finalPoint)
{
  // Coordinate x
  int xInitialIncrement = 0;
  int xFinalIncrement = 0;
  int xDistance = finalPoint.x - initialPoint.x;
  int fAxis = std::abs(xDistance);
  int currentX = initialPoint.x;
  xInitialIncrement = xFinalIncrement = (xDistance < 0 ? -1 : (xDistance > 0 ? 1 : 0));

  // Coordinate y
  int yInitialIncrement = 0;
  int yFinalIncrement = 0;
  int yDistance = finalPoint.y - initialPoint.y;
  int sAxis = std::abs(yDistance);
  int currentY = initialPoint.y;
  yInitialIncrement = (yDistance < 0 ? -1 : (yDistance > 0 ? 1 : 0));

  if (fAxis < sAxis)
  {
    std::swap(fAxis, sAxis);
    yFinalIncrement = (yDistance < 0 ? -1 : (yDistance > 0 ? 1 : 0));
    xFinalIncrement = 0;
  }

  int baseDistance = fAxis << 1;

  double variance[4] =
  {
    (double)(finalPoint.color.rgba[0] - initialPoint.color.rgba[0]) / fAxis,
    (double)(finalPoint.color.rgba[1] - initialPoint.color.rgba[1]) / fAxis,
    (double)(finalPoint.color.rgba[2] - initialPoint.color.rgba[2]) / fAxis,
    (double)(finalPoint.color.rgba[3] - initialPoint.color.rgba[3]) / fAxis
  };

  double newColor[4] =
  {
    (double)initialPoint.color.rgba[0],
    (double)initialPoint.color.rgba[1],
    (double)initialPoint.color.rgba[2],
    (double)initialPoint.color.rgba[3]
  };

  for (int i = 0; i <= fAxis; ++i)
  {
    drawPoint(Point(Color((const unsigned char)newColor[0], (const unsigned char)newColor[1], (const unsigned char)newColor[2], (const unsigned char)newColor[3]), currentX, currentY));

    newColor[0] += variance[0];
    newColor[1] += variance[1];
    newColor[2] += variance[2];
    newColor[3] += variance[3];

    baseDistance += sAxis;

    if (baseDistance <= fAxis)
    {
      currentX += xFinalIncrement;
      currentY += yFinalIncrement;
    }
    else
    {
      baseDistance -= fAxis;
      currentX += xInitialIncrement;
      currentY += yInitialIncrement;
    }
  }
}

void MyGL::drawTriangle(Point pointA, Point pointB, Point pointC)
{
  drawLine(pointA, pointB);
  drawLine(pointB, pointC);
  drawLine(pointC, pointA);
}
