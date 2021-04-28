//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Suhair Shareef
//


#include "RenderWidget.h"
#include <glut.h>
#include <QPainter>

RenderWidget::RenderWidget(QWidget *parent) : QGLWidget(parent)
{

}


RenderWidget::~RenderWidget()
{

}


QSize RenderWidget::minimumSizeHint() const
{
    return QSize(1000, 700);
}


QSize RenderWidget::sizeHint() const
{
    return QSize(1000, 700);
}


void RenderWidget::initializeGL()
{
    glClearColor(0.95, 0.908, 0.7, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 700.0, 0.0);
}


void RenderWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // gradiant quade
    glBegin(GL_QUADS);
        glColor3f(0.208, 0.216, 0.212); // Dark Gray
        glVertex2f(42, 27);
        glColor3f(1.0, 1.0, 1.0); // White
        glVertex2f(420, 27);
        glColor3f(0.208, 0.216, 0.212); // Dark Gray
        glVertex2f(420, 392);
        glColor3f(1.0, 1.0, 1.0); // White
        glVertex2f(42, 392);
    glEnd();

    glBegin(GL_TRIANGLES);
      // Yellow triangle
      glColor3f(254, 242, 0);   // yellow
      glVertex2f(158, 317);
      glVertex2f(158, 582);
      glVertex2f(467, 582);

      // Triangle on top right
      glColor3f(1.0, 0.0, 0.0);   // red
      glVertex2f(542, 283);
      glColor3f(0.0, 1.0, 0.0);   // green
      glVertex2f(721, 18);
      glColor3f(0.0, 0.0, 1.0);   // blue
      glVertex2f(900, 283);
      
    glEnd();

    // Blue polygon
    glBegin(GL_POLYGON);
        glColor3f(0.252, 0.284, 0.816); // blue
        glVertex2f(756, 298);
        glVertex2f(534, 440);
        glVertex2f(618, 670);
        glVertex2f(893, 670);
        glVertex2f(977, 440);
    glEnd();

    // Triangle inside the polygon
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(631, 602);
        glVertex2f(742, 404);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(742, 540);

        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(742, 404);
        glVertex2f(854, 602);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(742, 540);

        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(854, 602);
        glVertex2f(631, 602);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(742, 540);
    glEnd();

    glFlush();
}


void RenderWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

//    glViewport(0, 0, width, height);
}


