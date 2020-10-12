/*
Task 0.0.8
*/

#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int main8() {
	double x;
	printf("x = ");
	scanf("%lf", &x);
	double y = log10(x);
	printf("log10(%.3lf) = %.3lf", x, y);
	return 0;
}
