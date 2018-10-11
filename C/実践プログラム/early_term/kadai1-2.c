#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>


int bubbleSort(int ary[N]);
int selectionSort(int ary[N]);

int main()
{
	int ary[N];
	char buff[256];

	for (size_t i = 0; i < sizeof(ary) / 4; i++)
	{
		fgets(buff, sizeof(buff), stdin);
		sscanf(buff, "%d", &(ary[i]));
	}

	for (size_t i = 0; i < sizeof(ary) / 4; i++)	printf("%d", ary[i]);
	putchar('\n');

	selectionSort(ary);

	for (size_t i = 0; i < sizeof(ary) / 4; i++)	printf("%d", ary[i]);
	putchar('\n');

	return 0;
}

int bubbleSort(int ary[N])
{
	int temp;

	for (size_t t = N - 1; 0 < t; t--)	for (size_t i = 0; i < t; i++)	if (ary[i] > ary[i + 1])
	{
		temp = ary[i];
		ary[i] = ary[i + 1];
		ary[i + 1] = temp;
	}

	return ary[N];
}

int selectionSort(int ary[N])
{
	int temp, min;

	for (size_t t = 0; t < N; t++)
	{
		min = t;
		for (size_t i = t + 1; i < N; i++)	if (ary[i] < ary[min])
		{
			min = i;
		}
		temp = ary[t];
		ary[t] = ary[min];
		ary[min] = temp;
	}

	return ary[N];
}
