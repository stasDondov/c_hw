/*
Task 0.1.1
*/

#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int main101() {
	float C, F;
	printf("Input a float number of degrees Celsius: ");
	scanf("%f", &C);
	printf("Deegrees Fahrenheit: F = %g", (9.0 * C / 5.0) + 32.0);
	return 0;
}
