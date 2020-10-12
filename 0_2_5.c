/*
Task 0.2.5
*/

#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

double bisector(double x, double y, double z) // x - �������, �� ��� ���� ���������
{										  // y, z - 2 ����� �������
	double p = (x + y + z) / 2.0;            // p - ����������
	return 2.0 * sqrtf(y * z * p * (p - x)) / (y + z);
}

double median(double x, double y, double z) // x - ������� �� ��� ���� ������
{										// y, z - 2 ����� �������
	return sqrtf((2.0 * y * y + 2.0 * z * z - x * x) / 4.0);
}

double height(double x, double y, double z) // x - ������� �� ��� ���� ������
{
	double p = (x + y + z) / 2;
	double S = sqrtf(p * (p - x) * (p - y) * (p - z));
	return 2.0 * S / x;
}

int main106() {
	float a, b, c;
	printf("A = "); scanf("%f", &a);
	printf("B = "); scanf("%f", &b);
	printf("C = "); scanf("%f", &c);
	printf("\nSide A:\n"); // �� ������� � �������
	printf("bisector = %lf\n", bisector(a, b, c));
	printf("median = %lf\n", median(a, b, c));
	printf("height = %lf\n", height(a, b, c));

	printf("\nSide B:\n"); // �� ������� b �������
	printf("bisector = %lf\n", bisector(b, a, c));
	printf("median = %lf\n", median(b, a, c));
	printf("height = %lf\n", height(b, a, c));

	printf("\nSide C:\n"); // �� ������� c �������
	printf("bisector = %lf\n", bisector(c, b, a));
	printf("median = %lf\n", median(c, b, a));
	printf("height = %lf\n", height(c, b, a));
	return 0;
}
