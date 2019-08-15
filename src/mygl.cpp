/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#include "mygl.h"
#include "core\base\definitions.h"



GLuint texture;

void(*drawCallback)(void);

unsigned char *frameBuffer;



void drawArt(int id)
{

  // Random black and white pixels
  if (id == 0)
  {
    Point pointA;

    // Black
    pointA.color.setRGB();

    // Column
    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
      pointA.y = y;

      // Row
      for (int x = 0; x < SCREEN_WIDTH; x++)
      {
        pointA.x = x;

        // Random color for each point
        unsigned char lightnessPixel = 1 + std::rand() / ((RAND_MAX + 1u) / 255);
        pointA.color.setRGB(lightnessPixel, lightnessPixel, lightnessPixel);

        MyGL::drawPoint(pointA);
      }
    }

  }
  // Random colored pixels
  else if (id == 1)
  {
    Point pointA;
    Point pointB;

    // Black
    pointA.color.setRGB();

    // Column
    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
      pointA.y = y;

      // Row
      for (int x = 0; x < SCREEN_WIDTH; x++)
      {
        pointA.x = x;

        // Random color for each point
        pointA.color.setRGB(1 + std::rand() / ((RAND_MAX + 1u) / 255), 1 + std::rand() / ((RAND_MAX + 1u) / 255), 1 + std::rand() / ((RAND_MAX + 1u) / 255));

        MyGL::drawPoint(pointA);
      }
    }
  }
  // Dotted lines
  else if (id == 2)
  {
    Point pointA;
    Point pointB;

    pointA.x = 255;
    pointA.y = 0;

    pointB.x = 0;
    pointB.y = 255;

    int windowSize = SCREEN_WIDTH;
    int pointsDistance = 8;
    int pointsCountPerLine = (int)(windowSize / pointsDistance);
    int redPointsInLine = 7;
    int xRedMargin = (int)std::floor((pointsCountPerLine - 1) / 2) - (redPointsInLine + 1);
    int yRedMargin = (int)std::ceil((pointsCountPerLine - 1) / 2) + (redPointsInLine + 1);

    for (int i = 0; i < pointsCountPerLine; i++)
    {
      MyGL::drawPoint(pointA);
      MyGL::drawPoint(pointB);

      pointA.y += 8;
      pointB.x += 8;

      if (i > xRedMargin && i < yRedMargin)
      {
        // Random
        pointA.color.setR(1 + std::rand() / ((RAND_MAX + 1u) / 255));
        pointA.color.setG(1 + std::rand() / ((RAND_MAX + 1u) / 255));
        pointA.color.setB(1 + std::rand() / ((RAND_MAX + 1u) / 255));

        // Random
        pointB.color.setR(1 + std::rand() / ((RAND_MAX + 1u) / 255));
        pointB.color.setG(1 + std::rand() / ((RAND_MAX + 1u) / 255));
        pointB.color.setB(1 + std::rand() / ((RAND_MAX + 1u) / 255));
      }
      else
      {
        // Yellow
        pointA.color.setR(255);
        pointA.color.setG(255);
        pointA.color.setB(0);

        // Yellow
        pointB.color.setR(255);
        pointB.color.setG(255);
        pointB.color.setB(0);
      }
    }
  }
}



void draw()
{
  // Choose an art id
  drawArt(2);
}

void onExitApplication()
{
  // Free frameBuffer memory
  if (!frameBuffer)
    delete[] frameBuffer;

  std::clog << "Exiting..." << std::endl;
}

void update()
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

  // glRotatef(0.7f, 0, 0, 1);

  // 2 triangles for display texture on it
  glBegin(GL_TRIANGLES);
    // North-West Triangle
    // Vertex
    //glColor3f(1.0f, 0.0f, 0.0f); // For drawing this color directly by OpenGL
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    // Vertex
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    // Vertex
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);

    // South-East Triangle
    // Vertex
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    // Vertex
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    // Vertex
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
  unsigned int displayModeFlags = 0;
  displayModeFlags |= GLUT_DOUBLE; // Flag for duplicate color buffer
  displayModeFlags |= GLUT_RGBA; // Flag for create color buffer (duplicated because of previous flag)
  displayModeFlags |= GLUT_DEPTH; // Depth buffer (Z-Buffer)
  glutInitDisplayMode(displayModeFlags);
  glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
  glutInitWindowPosition(400, 300); // Position of window on user's screen
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
  glutDisplayFunc(update);



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
  glutMainLoop(); // Calls display function in loop
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
    frameBuffer[memoryPosition++] = point.color.getRGBA(i);
}

void MyGL::drawLine(Point initialPoint, Point finalPoint)
{
  int xDistance = finalPoint.x - initialPoint.x;
  int yDistance = finalPoint.y - initialPoint.y;

  int xAxisDirection = xDistance < 0 ? -1 : (xDistance > 0 ? 1 : 0);
  int yAxisDirection = yDistance < 0 ? -1 : (yDistance > 0 ? 1 : 0);


  // Coordinate x
  int xInitialIncrement = 0;
  int xFinalIncrement = 0;
  int fAxis = std::abs(xDistance);
  int currentX = initialPoint.x;

  // Coordinate y
  int yInitialIncrement = 0;
  int yFinalIncrement = 0;
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
    (double)(finalPoint.color.getR() - initialPoint.color.getR()) / fAxis,
    (double)(finalPoint.color.getG() - initialPoint.color.getG()) / fAxis,
    (double)(finalPoint.color.getB() - initialPoint.color.getB()) / fAxis,
    (double)(finalPoint.color.getA() - initialPoint.color.getA()) / fAxis
  };

  double newColor[4] =
  {
    (double)initialPoint.color.getR(),
    (double)initialPoint.color.getG(),
    (double)initialPoint.color.getB(),
    (double)initialPoint.color.getA()
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
