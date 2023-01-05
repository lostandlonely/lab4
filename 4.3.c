#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lim 100
int main() {
	int matr[50][50], N, random,min,flag=0;
	printf("Input 1 for random or 2 for manual\n");
	while (scanf_s("%d", &random) != 1 || (random != 1 && random != 2) || getchar() != '\n') {
		printf("wrong input\n");
		rewind(stdin);
	}
	printf("Input size of square matrix\n");
	while (scanf_s("%d", &N) != 1 || N < 1 || N > 50 || getchar() != '\n') {
		printf("wrong input\n");
		rewind(stdin);
	}
	if (random == 1)
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				matr[row][col] = rand() % (2 * lim + 1) - lim;
				printf("%4d ", matr[row][col]);
			}
			printf("\n");
		}
	else
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				printf("%d row %d col element", row, col);
				while (scanf_s("%d", &matr[row][col]) != 1 || getchar() != '\n') {
					printf("wrong input\n");
					rewind(stdin);
				}
			}
		}
	for (int row = N-N/2-1; row < N; row++) {
		for (int col = N-1-row; col <= row; col++) {
			if (matr[row][col] % 2 == 0) {
				min = matr[row][col];
				flag = 1;
				break;
			}
		}
		if (flag == 1)	
			break;
	}
	if (flag == 1) {
		for (int row = N - N / 2 - 1; row < N; row++) {
			for (int col = N - 1 - row; col <= row; col++) {
				if (matr[row][col] % 2 == 0 &&matr[row][col]<min) {
					min = matr[row][col];
				}
			}
		}
		printf("minimal even is %d\n", min);
	}
	else
		printf("No even numbers in area 3\n");
	return 0;
}