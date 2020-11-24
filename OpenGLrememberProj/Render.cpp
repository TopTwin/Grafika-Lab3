

#include "Render.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

double t_max = 0;

double f(double p0, double p1, double p2, double p3, double t)// формула кривой Безье
{
	return (p0 * (1 - t) * (1 - t) * (1 - t)) + (3 * t * (1 - t) * (1 - t) * p1) + (3 * t * t * (1 - t) * p2) + t * t * t * p3; //посчитанная формула
}

double f2(double p1, double p4, double R1, double R4, double t) // формула кривой Эрмита
{

	return (p1 * (2 * t * t * t - 3 * t * t + 1) + p4 * (-2 * t * t * t + 3 * t * t) + R1 * (t * t * t - 2 * t * t + t) + R4 * (t * t * t - t * t));
}

void DrawningFigure(double[]);

void Bez1()
{
	double P1[] = { 0,0,0 }; //Наши точки
	double P2[] = { 2,2,4 };
	double P3[] = { 8,1,13 };
	double P4[] = { 4,0,0 };
	double P[4];
	glBegin(GL_LINE_STRIP); //построим отрезки P1P2 и P2P3
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glVertex3dv(P4);
	glEnd();
	glLineWidth(3); //ширина линии
	glColor3d(0, 1, 0);
	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.001; t += 0.01)
	{
		P[0] = f(P1[0], P2[0], P3[0], P4[0], t);
		P[1] = f(P1[1], P2[1], P3[1], P4[1], t);
		P[2] = f(P1[2], P2[2], P3[2], P4[2], t);
		P[3] = f(P1[3], P2[3], P3[3], P4[3], t);
		glVertex3dv(P); //Рисуем точку P
	}
	glEnd();
	glColor3d(1, 0, 1);
	glLineWidth(1); //возвращаем ширину линии = 1
	//нарисуем все точки
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex3dv(P);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glVertex3dv(P4);
	glEnd();
}
void Bez2()
{
	double P1[] = { 0,0,0 }; //Наши точки
	double P2[] = { 0,6,0 };
	double P3[] = { 3,0,0 };
	double P4[] = { 3,10,0 };
	double P[4];
	glBegin(GL_LINE_STRIP); //построим отрезки P1P2 и P2P3
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glVertex3dv(P4);
	glEnd();
	glLineWidth(3); //ширина линии
	glColor3d(0, 1, 0);
	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.001; t += 0.01)
	{
		P[0] = f(P1[0], P2[0], P3[0], P4[0], t);
		P[1] = f(P1[1], P2[1], P3[1], P4[1], t);
		P[2] = f(P1[2], P2[2], P3[2], P4[2], t);
		P[3] = f(P1[3], P2[3], P3[3], P4[3], t);
		glVertex3dv(P); //Рисуем точку P
	}
	glEnd();
	glColor3d(1, 0, 1);
	glLineWidth(1); //возвращаем ширину линии = 1
	//нарисуем все точки
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex3dv(P);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glVertex3dv(P4);
	glEnd();
}
void Erm1()
{
	double P1[] = { -10, 0, 0 }; //Наши точки
	double P2[] = { -8,6, 2 };
	double P3[] = { -6,-2, 4 };
	double P4[] = { -2, 8 ,0 };


	double R1[] = { 0, 0, 0 };
	double R4[] = { 0, 0, 0 };

	R1[0] = P2[0] - P1[0]; //нахождение векторов
	R1[1] = P2[1] - P1[1];
	R1[2] = P2[2] - P1[2];

	R4[0] = P4[0] - P3[0];
	R4[1] = P4[1] - P3[1];
	R4[2] = P4[2] - P3[2];

	glLineWidth(1); //ширина линии

	glBegin(GL_LINE_STRIP);
	glVertex3dv(P2); //отрисовка векторов
	glVertex3dv(P1);
	glEnd();

	glLineWidth(3); //ширина линии

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01) //отрисовка кривой Эрмита
	{
		double P[4];
		P[0] = f2(P1[0], P4[0], R1[0], R4[0], t);
		P[1] = f2(P1[1], P4[1], R1[1], R4[1], t);
		P[2] = f2(P1[2], P4[2], R1[2], R4[2], t);
		P[3] = f2(P1[3], P4[3], R1[3], R4[3], t);
		glVertex3dv(P); //Рисуем точку P
	}
	glEnd();

	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	glVertex3dv(P3);
	glVertex3dv(P4);
	glEnd();

}
void Erm2()
{
	double P1[] = { 0, -5, 0 }; //Наши точки
	double P2[] = { 5 ,-5, 20 };
	double P3[] = { 0, -5, 0 };
	double P4[] = { -8, -5 ,2 };


	double R1[] = { 0, 0, 0 };
	double R4[] = { 0, 0, 0 };

	R1[0] = P2[0] - P1[0]; //нахождение векторов
	R1[1] = P2[1] - P1[1];
	R1[2] = P2[2] - P1[2];

	R4[0] = P4[0] - P3[0];
	R4[1] = P4[1] - P3[1];
	R4[2] = P4[2] - P3[2];

	glLineWidth(1); //ширина линии

	glBegin(GL_LINE_STRIP);
	glVertex3dv(P2); //отрисовка векторов
	glVertex3dv(P1);
	glEnd();

	glLineWidth(3); //ширина линии

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01) //отрисовка кривой Эрмита
	{
		double P[4];
		P[0] = f2(P1[0], P4[0], R1[0], R4[0], t);
		P[1] = f2(P1[1], P4[1], R1[1], R4[1], t);
		P[2] = f2(P1[2], P4[2], R1[2], R4[2], t);
		P[3] = f2(P1[3], P4[3], R1[3], R4[3], t);
		glVertex3dv(P); //Рисуем точку P
	}
	glEnd();

	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	glVertex3dv(P3);
	glVertex3dv(P4);
	glEnd();

}
void Bez3(double delta_time)
{
	t_max += delta_time / 5; //t_max становится = 1 за 5 секунд
	if (t_max > 1) t_max = 0; //после обнуляется

	double P1[] = { 0,0,0 }; //Наши точки
	double P2[] = { 0,6,0 };
	double P3[] = { 3,0,0 };
	double P4[] = { 3,10,0 };
	double P[4];
	glBegin(GL_LINE_STRIP); //построим отрезки P1P2 и P2P3
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glVertex3dv(P4);
	glEnd();
	glLineWidth(3); //ширина линии
	glColor3d(0, 1, 0);
	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= t_max; t += 0.01)
	{
		P[0] = f(P1[0], P2[0], P3[0], P4[0], t);
		P[1] = f(P1[1], P2[1], P3[1], P4[1], t);
		P[2] = f(P1[2], P2[2], P3[2], P4[2], t);
		P[3] = f(P1[3], P2[3], P3[3], P4[3], t);
		glVertex3dv(P); //Рисуем точку P
	}
	glEnd();
	glColor3d(1, 0, 1);
	glLineWidth(1); //возвращаем ширину линии = 1
	//нарисуем все точки
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex3dv(P);
	glEnd();

	DrawningFigure(P);

	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glVertex3dv(P4);
	glEnd();
}
void Render(double delta_time)
{
	Bez1();
	Bez2();
	Bez3(delta_time);

	Erm1();
	Erm2();
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