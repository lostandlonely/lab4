#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lim 100
int main() {
	int matr[50][50], m,n,srs=0,srsmax=0, random,zerocol=0;
	printf("Input 1 for random or 2 for manual\n");
	while (scanf_s("%d", &random) != 1 || (random != 1 && random != 2) || getchar() != '\n') {
		printf("wrong input\n");
		rewind(stdin);
	}
	printf("Input number of rows\n");
	while (scanf_s("%d", &m) != 1 || m < 1 || m > 50 || getchar() != '\n') {
		printf("wrong input\n");
		rewind(stdin);
	}
	printf("Input number of columns\n");
	while (scanf_s("%d", &n) != 1 || n < 1 || n > 50 || getchar() != '\n') {
		printf("wrong input\n");
		rewind(stdin);
	}
	if (random == 1) {
		for (int row = 0; row < m; row++) {
			for (int col = 0; col < n; col++) {
				matr[row][col] = rand() % (2 * lim + 1) - lim;
				printf("%4d ", matr[row][col]);
			}
			printf("\n");
		}
	}
	else
		for (int row = 0; row < m; row++) {
			for (int col = 0; col < n; col++) {
				printf("%d row %d col element", row, col);
				while (scanf_s("%d", &matr[row][col]) != 1 || getchar() != '\n') {
					printf("wrong input\n");
					rewind(stdin);
				}
			}
		}
	for (int col = 0; col < n; col++) {
		for (int row = 0; row < m; row++) {
			if (matr[row][col] == 0) {
				zerocol++;
				break;
			} 
		}
	}
	printf("%d columns with zero element\n",zerocol);
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			srs = 0;
			for (int col1 = col; col1 < n; col1++) {
				if (matr[row][col]==matr[row][col1]) {
					srs++;
				}
			}
			if (srs>srsmax)
				srsmax = srs;
		}
	}
	printf("Number(s) of row(s) with max series of same elements:");
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			srs = 0;
			for (int col1 = col; col1 < n; col1++) {
				if (matr[row][col] == matr[row][col1]) {
					srs++;
				}
			}
			if (srs == srsmax) {
				printf("%d ",row+1);
				srs = 0;
				break;
			}
		}
	}
	printf("\n");
	return 0;
}