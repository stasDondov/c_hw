/*
Task 0.0.6
*/

#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int main6() {
	double F, m1, m2, r, y = 6.673e-11;
	printf("m1 = "); scanf("%lf", &m1);
	printf("m2 = ");scanf("%lf", &m2);
	printf("r = "); scanf("%lf", &r);
	printf("F = %e N*m^2/kg^2", (y * m1 * m2) / (r * r));
	return 0;
}
