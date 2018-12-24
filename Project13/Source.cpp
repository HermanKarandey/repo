#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 5
void selectionSort(int Matrix[][N]);
void outMatrix(int Matrix[][N]);
void ArithmeticMean(int Matrix[][N], int  *Sum);
int main()
{
	int Matrix[N][N] =

	{ 1, 6,  21,  11,   6,
2,  17,  22,  12,   7,
3,  18,  23,  13,   8,
4,  19,  24,  14,   9,
5,  20,  25,  15,  10 };
	int Sum[N - 1] = { 0 };
	int Mul = 1;
	outMatrix(Matrix);
	selectionSort(Matrix);
	ArithmeticMean(Matrix, Sum);

	outMatrix(Matrix);
	printf("\n");
	for (int i = 0; i < N - 1; ++i)
	{
		printf("1st =  %d\n", Sum[i]);
		Mul *= Sum[i];
	}

	printf("Multy = %d\n", Mul);



	system("pause");
	return 0;
}
void selectionSort(int Matrix[][N])
{
	int temp;
	int index;
	int min;
	for (int j = 0;j < N;++j) {
		for (int k = 0;k < N - 1;++k) {
			min = Matrix[j][k];
			index = k;
			for (int i = k + 1;i < N;++i) {
				if (Matrix[j][i] < min)
				{
					min = Matrix[j][i];
					index = i;
				}
			}
			temp = Matrix[j][k];
			Matrix[j][k] = Matrix[j][index];
			Matrix[j][index] = temp;
		}
	}


}

void outMatrix(int Matrix[][N])
{
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j)
			printf("%d\t", Matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}

void ArithmeticMean(int Matrix[][N], int  *Sum)
{

	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N;++j)
		{
			Sum[i] += Matrix[j][i];

		}
		Sum[i] /= N - 1 - i;
	}
}