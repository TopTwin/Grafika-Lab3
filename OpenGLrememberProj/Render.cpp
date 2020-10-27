

#include "Render.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

double t_max = 0;


double fun(double p1, double p2, double p3, double t)
{
	return p1 * (1 - t) * (1 - t) + 2 * p2 * t * (1 - t) + p3 * t * t; //посчитанная формула
}

void DrawningFigure(double[]);
void Render(double delta_time)
{
	t_max += delta_time / 5; //t_max становится = 1 за 5 секунд
	if (t_max > 1) t_max = 0; //после обнуляется
	double P1[] = { 0,0,0 }; //Наши точки
	double P2[] = { 0,5,0 };
	double P3[] = { 5,0,0 };
	double P[3];
	double pastP[3];

	glBegin(GL_LINE_STRIP); //построим отрезки P1P2 и P2P3
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glEnd();
	glLineWidth(3); //ширина линии
	glColor3d(0, 1, 0);
	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= t_max; t += 0.01)
	{
		P[0] = fun(P1[0], P2[0], P3[0], t);
		P[1] = fun(P1[1], P2[1], P3[1], t);
		P[2] = fun(P1[2], P2[2], P3[2], t);
		glVertex3dv(P); //Рисуем точку P
	}
	glEnd();

	glColor3d(1, 0, 1);
	glLineWidth(1); //возвращаем ширину линии = 1
	//нарисуем все точки
	glPointSize(10);
	//glBegin(GL_POINTS);
	//glVertex3dv(P);
	//glEnd();

	DrawningFigure(P);

	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glEnd();

}  

void DrawningFigure(double P[])
{
	glBegin(GL_QUADS);
	glColor3d(0.8, 0, 0);
	glVertex3d(P[0] - 0.1, P[1] + 0.1, 0);
	glVertex3d(P[0] + 0.1, P[1] + 0.1, 0);
	glVertex3d(P[0] + 0.1, P[1] - 0.1, 0);
	glVertex3d(P[0] - 0.1, P[1] - 0.1, 0);

	glColor3d(0, 0.8, 0);
	glVertex3d(P[0] - 0.1, P[1] + 0.1, 0.1);
	glVertex3d(P[0] + 0.1, P[1] + 0.1, 0.1);
	glVertex3d(P[0] + 0.1, P[1] - 0.1, 0.1);
	glVertex3d(P[0] - 0.1, P[1] - 0.1, 0.1);

	glColor3d(0, 0, 0.8);
	glVertex3d(P[0] - 0.1, P[1] + 0.1, 0);
	glVertex3d(P[0] - 0.1, P[1] + 0.1, 0.1);
	glVertex3d(P[0] - 0.1, P[1] - 0.1, 0.1);
	glVertex3d(P[0] - 0.1, P[1] - 0.1, 0);
	
	glColor3d(0, 0.8, 0.8);
	glVertex3d(P[0] - 0.1, P[1] + 0.1, 0);
	glVertex3d(P[0] - 0.1, P[1] + 0.1, 0.1);
	glVertex3d(P[0] + 0.1, P[1] + 0.1, 0.1);
	glVertex3d(P[0] + 0.1, P[1] + 0.1, 0);

	glColor3d(0.8, 0.8, 0);
	glVertex3d(P[0] + 0.1, P[1] + 0.1, 0);
	glVertex3d(P[0] + 0.1, P[1] + 0.1, 0.1);
	glVertex3d(P[0] + 0.1, P[1] - 0.1, 0.1);
	glVertex3d(P[0] + 0.1, P[1] - 0.1, 0);

	glColor3d(0.8, 0, 0.8);
	glVertex3d(P[0] + 0.1, P[1] - 0.1, 0);
	glVertex3d(P[0] + 0.1, P[1] - 0.1, 0.1);
	glVertex3d(P[0] - 0.1, P[1] - 0.1, 0.1);
	glVertex3d(P[0] - 0.1, P[1] - 0.1, 0);
	glEnd();
};