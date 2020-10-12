/*
Task 0.1.4
*/

#include <stdio.h>
#pragma warning(disable:4996)

int main104() {
	float a, b, Am, Ah;
	printf("a, b = ");
	scanf("%f %f", &a, &b);
	Am = (a + b) / 2.0;
	Ah = 2.0 / (1.0 / a + 1.0 / b);
	printf("Arithmetic mean = %f = %e\n", Am, Am);
	printf("Axerage harmonic = %f = %e\n", Ah, Ah);
	getchar();
	return 0;
}