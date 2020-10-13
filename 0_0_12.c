/*
Task 0.0.12
*/

#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

void tabl() {
	printf("\n  x  |  1  |  2  |  3  |  4  |  5\n");
	printf("-----+-----+-----+-----+-----+-----\n");
	printf(" F(x)");
}

float Fexp(int x) {
	return exp(-x * x);
}

float Fsqrt(int x) {
	return sqrtf(x);
}


int main12() {
	printf("\tTable 1");
	tabl();
	for (int i = 1; i <= 5; ++i) {
		if (Fexp(i) - (float)(int)Fexp(i) >= 0.01) {
			printf("|%5.2f", Fexp(i));
		}
		else {
			printf("|  %d  ", (int)Fexp(i));
		}
	}
	printf("\n\n\tTable 2");
	tabl();
	for (int i = 1; i <= 5; ++i) {
		if (Fsqrt(i) - (float)(int)Fsqrt(i) >= 0.01) {
			printf("|%5.2f", Fsqrt(i));
		}
		else {
			printf("|  %d  ", (int)Fsqrt(i));
		}
	}
	getchar();
	return 0;
}

// отцентровать вывод