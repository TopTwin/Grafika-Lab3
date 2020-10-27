

#include "Render.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

double t_max = 0;

double fun(double p1, double p2, double p3, double t)
{
	return p1 * (1 - t) * (1 - t) + 2 * p2 * t * (1 - t) + p3 * t * t; //����������� �������
}

void Render(double delta_time)
{
	t_max += delta_time / 5; //t_max ���������� = 1 �� 5 ������
	if (t_max > 1) t_max = 0; //����� ����������
	double P1[] = { 0,0,0 }; //���� �����
	double P2[] = { -4,6,7 };
	double P3[] = { 10,10,0 };
	double P[3];
	glBegin(GL_LINE_STRIP); //�������� ������� P1P2 � P2P3
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glEnd();
	glLineWidth(3); //������ �����
	glColor3d(0, 1, 0);
	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= t_max; t += 0.01)
	{
		P[0] = fun(P1[0], P2[0], P3[0], t);
		P[1] = fun(P1[1], P2[1], P3[1], t);
		P[2] = fun(P1[2], P2[2], P3[2], t);
		glVertex3dv(P); //������ ����� P
	}
	glEnd();
	glColor3d(1, 0, 1);
	glLineWidth(1); //���������� ������ ����� = 1
	//�������� ��� �����
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex3dv(P);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glEnd();

}  

