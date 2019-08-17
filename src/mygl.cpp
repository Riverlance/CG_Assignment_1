/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#include "mygl.h"
#include "core\base\definitions.h"



GLuint texture;

unsigned char *frameBuffer;



// Scene id 3
uint16_t linesMargin = 0;
int8_t linesCountDirection = 1;

// Scene id 4
int32_t trianglePointRx = getRandom(0, SCREEN_WIDTH - 1);
int32_t trianglePointGx = getRandom(0, SCREEN_WIDTH - 1);
int32_t trianglePointBx = getRandom(0, SCREEN_WIDTH - 1);
int32_t trianglePointRy = getRandom(0, SCREEN_HEIGHT - 1);
int32_t trianglePointGy = getRandom(0, SCREEN_HEIGHT - 1);
int32_t trianglePointBy = getRandom(0, SCREEN_HEIGHT - 1);

void drawArt(int id)
{
  // Random black and white pixels
  if (id == 0)
  {
    Point pointA;
    Color& colorA = pointA.getColor();

    // Black
    colorA.setRGB();

    // Column
    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
      pointA.setY(y);

      // Row
      for (int x = 0; x < SCREEN_WIDTH; x++)
      {
        pointA.setX(x);

        // Random color for each point
        colorA.setRandomGreyScale();

        MyGL::drawPoint(pointA);
      }
    }
  }



  // Random colored pixels
  else if (id == 1)
  {
    Point pointA;
    Color& colorA = pointA.getColor();

    // Black
    colorA.setRGB();

    // Column
    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
      pointA.setY(y);

      // Row
      for (int x = 0; x < SCREEN_WIDTH; x++)
      {
        pointA.setX(x);

        // Random color for each point
        colorA.setRandomRGBA();

        MyGL::drawPoint(pointA);
      }
    }
  }



  // Dotted lines
  else if (id == 2)
  {
    Point pointA((uint16_t)(SCREEN_WIDTH / 2.), 0);
    Point pointB(0, (uint16_t)(SCREEN_HEIGHT / 2.));

    Color& colorA = pointA.getColor();
    Color& colorB = pointB.getColor();
    
    int pointsDistance = 16;
    int coloredPointsInLine = 7;
    int pointsCountPerLine = (int)(SCREEN_WIDTH / (float)pointsDistance);

    for (int i = 0; i < pointsCountPerLine; i++)
    {
      pointA.addY(pointsDistance);
      pointB.addX(pointsDistance);
      
      // Random color
      colorA.setRandomRGBA();

      // Random color
      colorB.setRandomRGBA();

      MyGL::drawPoint(pointA);
      MyGL::drawPoint(pointB);
    }
  }



  // Lines
  else if (id == 3)
  {
    MyGL::clearTexture();

    int middleWidth = (int)std::floor(SCREEN_WIDTH / 2.);
    if (linesMargin == 1)
      linesCountDirection = 1;
    else if (linesMargin == middleWidth)
      linesCountDirection = -1;
    linesMargin = std::max(1, linesMargin + linesCountDirection);
    
    // Fixed points
    // North-west (red)
    Point pointNW(0, 0, Color(255, 0, 0));
    Color& pointNWColor = pointNW.getColor();
    // North-east (green)
    Point pointNE(SCREEN_WIDTH - 1, 0, Color(0, 255, 0));
    Color& pointNEColor = pointNE.getColor();
    // South-east (blue)
    Point pointSE(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, Color(0, 0, 255));
    Color& pointSEColor = pointSE.getColor();
    // South-west (cyan)
    Point pointSW(0, SCREEN_HEIGHT - 1, Color(0, 255, 255));
    Color& pointSWColor = pointSW.getColor();

    // Horizontal
    Point pointSWtoSE(pointSW);
    Point pointSEtoSW(pointSE);
    Point pointNEtoNW(pointNE);
    Point pointNWtoNE(pointNW);
    pointSWtoSE.setColor(pointNWColor); // Copy color
    pointSWtoSE.getColor().setA(0); // To 0% of color
    pointSEtoSW.setColor(pointNEColor); // Copy color
    pointSEtoSW.getColor().setA(0); // To 0% of color
    pointNEtoNW.setColor(pointSEColor); // Copy color
    pointNEtoNW.getColor().setA(0); // To 0% of color
    pointNWtoNE.setColor(pointSWColor); // Copy color
    pointNWtoNE.getColor().setA(0); // To 0% of color
    // Vertical
    Point pointNEtoSE(pointNE);
    Point pointNWtoSW(pointNW);
    Point pointSWtoNW(pointSW);
    Point pointSEtoNE(pointSE);
    pointNEtoSE.setColor(pointNWColor); // Copy color
    pointNEtoSE.getColor().setA(0); // To 0% of color
    pointNWtoSW.setColor(pointNEColor); // Copy color
    pointNWtoSW.getColor().setA(0); // To 0% of color
    pointSWtoNW.setColor(pointSEColor); // Copy color
    pointSWtoNW.getColor().setA(0); // To 0% of color
    pointSEtoNE.setColor(pointSWColor); // Copy color
    pointSEtoNE.getColor().setA(0); // To 0% of color
    
    // Lines Count
    int linesCountWidth = (int)std::floor(SCREEN_WIDTH / (float)linesMargin);
    int linesCountHeight = (int)std::floor(SCREEN_HEIGHT / (float)linesMargin);

    // Begin: north-west
    for (int i = 0; i < linesCountWidth; i++)
    {
      // End: Moving from south-west to south-east
      pointSWtoSE.addX(linesMargin);
      MyGL::drawLine(pointNW, pointSWtoSE, false);
    }
    for (int i = 0; i < linesCountHeight; i++)
    {
      // End: Moving from north-east to south-east
      pointNEtoSE.addY(linesMargin);
      MyGL::drawLine(pointNW, pointNEtoSE, false);
    }

    // Begin: north-east
    for (int i = 0; i < linesCountWidth; i++)
    {
      // End: Moving from south-east to south-west
      pointSEtoSW.addX(-linesMargin);
      MyGL::drawLine(pointNE, pointSEtoSW, false);
    }
    for (int i = 0; i < linesCountHeight; i++)
    {
      // End: Moving from north-west to south-west
      pointNWtoSW.addY(linesMargin);
      MyGL::drawLine(pointNE, pointNWtoSW, false);
    }

    // Begin: south-east
    for (int i = 0; i < linesCountWidth; i++)
    {
      // End: Moving from north-east to north-west
      pointNEtoNW.addX(-linesMargin);
      MyGL::drawLine(pointSE, pointNEtoNW, false);
    }
    for (int i = 0; i < linesCountHeight; i++)
    {
      // End: Moving from south-west to north-west
      pointSWtoNW.addY(-linesMargin);
      MyGL::drawLine(pointSE, pointSWtoNW, false);
    }

    // Begin: south-west
    for (int i = 0; i < linesCountWidth; i++)
    {
      // End: Moving from north-west to north-east
      pointNWtoNE.addX(linesMargin);
      MyGL::drawLine(pointSW, pointNWtoNE, false);
    }
    for (int i = 0; i < linesCountHeight; i++)
    {
      // End: Moving from south-east to north-east
      pointSEtoNE.addY(-linesMargin);
      MyGL::drawLine(pointSW, pointSEtoNE, false);
    }
  }



  // Triangles
  else if (id == 4)
  {
    MyGL::clearTexture();

    int random;

    // Move points
    // Red point
    random = getRandom(0, 2) == 0 ? -1 : 1;
    trianglePointRx += random;
    random = getRandom(0, 2) == 0 ? -1 : 1;
    trianglePointRy += random;
    // Green point
    random = getRandom(0, 2) == 0 ? -1 : 1;
    trianglePointGx += random;
    random = getRandom(0, 2) == 0 ? -1 : 1;
    trianglePointGy += random;
    // Blue point
    random = getRandom(0, 2) == 0 ? -1 : 1;
    trianglePointBx += random;
    random = getRandom(0, 2) == 0 ? -1 : 1;
    trianglePointBy += random;

    // Ensure triangle within screen
    trianglePointRx = std::max(0, std::min((int)trianglePointRx, SCREEN_WIDTH - 1));
    trianglePointGx = std::max(0, std::min((int)trianglePointGx, SCREEN_WIDTH - 1));
    trianglePointBx = std::max(0, std::min((int)trianglePointBx, SCREEN_WIDTH - 1));
    trianglePointRy = std::max(0, std::min((int)trianglePointRy, SCREEN_HEIGHT - 1));
    trianglePointGy = std::max(0, std::min((int)trianglePointGy, SCREEN_HEIGHT - 1));
    trianglePointBy = std::max(0, std::min((int)trianglePointBy, SCREEN_HEIGHT - 1));

    Point pointR(trianglePointRx, trianglePointRy, Color(255, 0, 0)); // Red
    Point pointG(trianglePointGx, trianglePointGy, Color(0, 255, 0)); // Green
    Point pointB(trianglePointBx, trianglePointBy, Color(0, 0, 255)); // Blue

    MyGL::drawTriangle(pointR, pointG, pointB);
  }
}



void draw()
{
  // Choose an art id
  drawArt(3);
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
  // Clear color buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Custom function to draw
  draw();

  // Copy frameBuffer into texture
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, SCREEN_WIDTH, SCREEN_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, frameBuffer);

  // Enable 2D texture
  glEnable(GL_TEXTURE_2D);

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

  // Execute OpenGL commands
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
  glutInitWindowPosition(200, 150); // Position of window on user's screen
  glutCreateWindow("My OpenGL");



  /* OpenGL */

  glMatrixMode(GL_PROJECTION); // Initialize the Projection matrix
  glLoadIdentity();
  glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

  glMatrixMode(GL_MODELVIEW); // Initialize the ModelView matrix
  glLoadIdentity();

  // Set background color
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  // Enable color blending
  glEnable(GL_BLEND);
  // Enable alpha color
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  //Check for error
  GLenum error = glGetError();
  if (error != GL_NO_ERROR)
  {
    std::cerr << "Error initializing OpenGL!\nOpenGL error: " << gluErrorString(error);
    return;
  }



  /* Callbacks */

  // Set display callback
  glutDisplayFunc(update);

  //glutReshapeFunc(resizeWindow);

  // Set exit callback
  atexit(onExitApplication);



  /* Init data structs */

  // Allocate framebuffer and initializes its position with 0
  frameBuffer = new unsigned char[SCREEN_WIDTH * SCREEN_HEIGHT * 5];

  for (unsigned int i = 0; i < (unsigned int)SCREEN_WIDTH * SCREEN_HEIGHT; i++)
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



// The glClear serves only for clear the screen from models, not from textures
// If you draw a triangle model in OpenGL and move it, it will draw the triangle moving
// But if it has no movement and we draw inside this triangle (texture), you should clear the texture of this triangle
void MyGL::clearTexture()
{
  Point begin, end(SCREEN_WIDTH - 1, 0);
  for (int height = 0; height < SCREEN_HEIGHT - 1; height++)
  {
    begin.setY(height);
    end.setY(height);
    MyGL::drawLine(begin, end);
  }
}

void MyGL::drawPoint(Point point)
{
  if (!point.isValid())
  {
    //std::cerr << "Point of coordinates XY(" << point.x << ", " << point.y << ")" << std::endl;
    return;
  }

  uint_fast16_t memoryPosition = point.getMemoryPosition();
  const Color& color = point.getColor();
  for (int i = 0; i < 4; i++)
    frameBuffer[memoryPosition++] = color.getRGBA(i);
}

void MyGL::drawLine(Point beginPoint, Point endPoint, bool initialPointColor /*= true*/)
{
  /// Declaration

  // Point
  Point point(beginPoint);

  // Color
  Color& color = point.getColor();
  Color& endColor = endPoint.getColor();

  // Position
  uint_fast16_t beginX = beginPoint.getX();
  uint_fast16_t beginY = beginPoint.getY();
  uint_fast16_t endX = endPoint.getX();
  uint_fast16_t endY = endPoint.getY();

  // Axis distance
  int_fast32_t distanceX = endPoint.getX() - beginPoint.getX();
  int_fast32_t distanceY = endPoint.getY() - beginPoint.getY();

  /// Octante handling

  // Axis direction
  int_fast32_t beginXAxisDirection = distanceX > 0 ? 1 : (distanceX < 0 ? -1 : 0);
  int_fast32_t beginYAxisDirection = distanceY > 0 ? 1 : (distanceY < 0 ? -1 : 0);
  int_fast32_t endXAxisDirection = beginXAxisDirection;
  int_fast32_t endYAxisDirection = 0;

  // Higher and lower axis
  uint_fast16_t higherAxis = std::abs(distanceX);
  uint_fast16_t lowerAxis = std::abs(distanceY);
  // If higher was supposed to be the lower, switch them
  if (higherAxis < lowerAxis) // X Axis < Y Axis
  {
    // Switch the higher to the lower
    std::swap(higherAxis, lowerAxis);

    // Since now the Y Axis is the higher, 
    endXAxisDirection = 0;
    endYAxisDirection = distanceY > 0 ? 1 : (distanceY < 0 ? -1 : 0);
  }

  /// Bresenham

  // Y rounding correction
  // This should prevent Y from being rounded to each integer rather than midway
  uint_fast16_t fractionNumerator = (uint_fast16_t) (higherAxis / 2.);

  // Color
  double newColor[4] =
  {
    (double)color.getR(),
    (double)color.getG(),
    (double)color.getB(),
    (double)color.getA(),
  };
  double higherAxisDouble = (double)higherAxis;
  double colorDirection[4] =
  {
    ((int16_t)endColor.getR() - color.getR()) / higherAxisDouble,
    ((int16_t)endColor.getG() - color.getG()) / higherAxisDouble,
    ((int16_t)endColor.getB() - color.getB()) / higherAxisDouble,
    ((int16_t)endColor.getA() - color.getA()) / higherAxisDouble,
  };

  for (uint_fast16_t i = 0; i < higherAxis; i++)
  {
    // Position
    point.setXY(beginX, beginY);

    // Gradient color
    if (!initialPointColor)
    {
      newColor[0] += colorDirection[0];
      newColor[1] += colorDirection[1];
      newColor[2] += colorDirection[2];
      newColor[3] += colorDirection[3];

      color.setRGBA((uint8_t)newColor[0], (uint8_t)newColor[1], (uint8_t)newColor[2], (uint8_t)newColor[3]);
    }

    // Draw point
    MyGL::drawPoint(point);

    // Increment numerator based on lowerAxis variation
    fractionNumerator += lowerAxis;

    // If numerator is higher than denominator
    if (fractionNumerator > higherAxis)
    {
      // Remove the denominator variation from numerator
      fractionNumerator -= higherAxis;

      beginX += beginXAxisDirection;
      beginY += beginYAxisDirection;
    }
    else
    {
      beginX += endXAxisDirection;
      beginY += endYAxisDirection;
    }
  }
}

void MyGL::drawTriangle(Point pointA, Point pointB, Point pointC)
{
  MyGL::drawLine(pointA, pointB, false);
  MyGL::drawLine(pointB, pointC, false);
  MyGL::drawLine(pointC, pointA, false);
}
