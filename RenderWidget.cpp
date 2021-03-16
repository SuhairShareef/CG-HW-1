//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Suhair Shareef, on 15.03.2021
//


#include "RenderWidget.h"
#include <QPainter>

#define PI 3.14159265

RenderWidget::RenderWidget(QWidget *parent) : QWidget(parent)
{
  // to be implemeted later
}

QSize RenderWidget::minimumSizeHint() const
{
  return QSize(600, 1000);
}

QSize RenderWidget::sizeHint() const
{
  return QSize(600, 1000);
}

void RenderWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

 //    painter.setRenderHint(QPainter::Antialiasing, false);
  QPen pen;

  pen.setStyle(Qt::DashDotLine);
  pen.setWidth(3);
  pen.setBrush(Qt::black);

  painter.setPen(pen);

  painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

  // lowwer part
  drawLine(100, 850, 500, 850);
  drawLine(100, 825, 100, 850);
  drawLine(500, 825, 500, 850);
  drawArc(300, 850, 180, 360, 100);
  drawLine(100, 825, 203, 800);
  drawLine(397, 825, 500, 800);
  drawCircle(300, 790, 20);

  // arcs section
  //drawCircle(300, 300, 190);
  drawArc(300, 600, -50, 68, 190);
  drawArc(300, 600, 112, 137, 190);
  drawArc(300, 600, -50, 120, 150);

  drawLine(125, 699, 260, 699);
  drawLine(125, 729, 260, 729);

  drawLine(125, 699, 125, 729);
  drawLine(260, 699, 260, 729);

  // upper circles
  drawCircle(383, 450, 40);
  drawCircle(383, 450, 20);

  // upper section
  myDrawLine(390, 410, 465, 300);
  myDrawLine(275, 586, 350, 476);
  myDrawLine(195, 526, 385, 240);

  drawLine(195, 526, 275, 586);
  drawLine(385, 240, 465, 300);

  drawLine(195, 566, 235, 596);
  myDrawLine(195, 566, 213, 540);
  myDrawLine(235, 596, 253, 570);

  drawLine(425, 230, 465, 260);
  myDrawLine(407, 256, 425, 230);
  myDrawLine(447, 286, 465, 260);

}


void RenderWidget::myDrawLine(float x1, float y1, float x2, float y2)
{
    QPainter painter(this);
    QPen pen;

    pen.setStyle(Qt::DashDotLine);
    pen.setWidth(3);
    pen.setBrush(Qt::black);

    painter.setPen(pen);

  float m = (y2 - y1) / (x2 - x1);
  //  SetPixel(x1, y1, color);   // first point
  painter.drawPoint(x1, y1);

  if (m < 1)
  {
    float y = y1;
    for (int i = x1 + 1; i < x2; ++i)
    {
      y = y + m;
      //      SetPixel(i, round(y), color);
      painter.drawPoint(i, round(y));
    }
  }
  else     // i.e., m > 1
  {
    float mm = 1 / m;
    float x = x1;
    for (int i = y1 + 1; i < y2; ++i)
    {
      x = x + mm;
      //      SetPixel(round(x), i, color);
      painter.drawPoint(round(x), i);
    }
  }

  //  SetPixel(x2, y2, color);   // last point
  painter.drawPoint(x2, y2);
}

// drawLine function
void RenderWidget::drawLine(int x1, int y1, int x2, int y2)
{
	QPainter painter(this);
	QPen pen;

	pen.setStyle(Qt::DashDotLine);
	pen.setWidth(3);
	pen.setBrush(Qt::black);

    painter.setPen(pen);

    int dx, dy, p, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

	x = x1;
    y = y1;

    p = 2 * dy - dx;
	
	if (x1 == x2) {
		for (int i = y1; i <= y2; i++)
			painter.drawPoint(x, i);
	}

    else
        while (x < x2)
        {
            if (p >= 0)
            {
                painter.drawPoint(x, y);
                y = y + 1;
                p = p + 2 * dy - 2 * dx;
            }
            else
            {
                painter.drawPoint(x, y);
                p = p + 2 * dy;
            }
            x = x + 1;
        }
}

// drawCircle function
void RenderWidget::drawCircle(int xc, int yc, int r)
{
	QPainter painter(this);
	QPen pen;

	pen.setStyle(Qt::DashDotLine);
	pen.setWidth(3);
	pen.setBrush(Qt::black);

	painter.setPen(pen);

	double x, y;
	double theta, dtheta;

	theta = 0;
	dtheta = 0.1;

	while (theta < 360) {
		x = xc + r * cos(theta * PI / 180.0);
		y = yc + r * sin(theta * PI / 180.0);

		painter.drawPoint(x, y);
		theta = theta + dtheta;
	}
}

// drawArc function
void RenderWidget::drawArc(int xc, int yc, int t1, int t2, int r) {
	QPainter painter(this);
	QPen pen;

	pen.setStyle(Qt::DashDotLine);
	pen.setWidth(3);
	pen.setBrush(Qt::black);

	painter.setPen(pen);

	double x, y;
	double theta, dtheta;

	theta = t1;
	dtheta = 0.01;

	while (theta < t2) {
		x = xc + r * cos(theta * PI / 180.0);
		y = yc + r * sin(theta * PI / 180.0);
		painter.drawPoint(x, y);
		theta = theta + dtheta;
	}
}
