/*
Task 0.1.2
*/

#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int main102() {
	float x, x1;
	printf("x = ");
	scanf("%f", &x);

	printf("Without mathematical functions \n");
	printf("whole part: %d\n", (int)x);
	printf("fractional part: %f\n", x - (int)x);
	printf("the smallest integer greater than given: %d\n", (int)x);
	printf("the largest integer less than given: %d\n", (int)x + 1);
	int av;
	if (x - (int)x >= 0.5) {
		av = (int)x + 1;
	}
	else {
		av = (int)x;
	}
	printf("rouded number: %d\n", av);

	printf("\nWith mathematical functions \n");
	float y = modff(x, &x1);
	printf("whole part: %f\n", x1);
	printf("fractional part: %f\n", y);
	printf("the smallest integer greater than given: %d\n", (int)floor(x));
	printf("the largest integer less than given: %d\n", (int)ceil(x));
	printf("rouded number: %d\n", (int)roundf(x));
	return 0;
}
