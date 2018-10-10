#define _CRT_SECURE_NO_WARNINGS
#define N 100

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>


int bubbleSort(int ary[N]);
int selectionSort(int ary[N]);
int insertionSort(int ary[N]);

int main()
{
	FILE *fp;
	int ary[N];
	char fn, buff[256];

	//for (size_t i = 0; i < sizeof(ary) / 4; i++)
	//{
	//	fgets(buff, sizeof(buff), stdin);
	//	sscanf(buff, "%d", &(ary[i]));
	//}

	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%s", &fn);
	if ((fp = fopen(&fn, "r")) == NULL)
	{
		printf("File can't open.\n");
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < N; i++)	fscanf(fp, "%d", &(ary[i]));

	for (size_t i = 0; i < sizeof(ary) / 4; i++)	printf("%d ", ary[i]);
	putchar('\n');

	insertionSort(ary);

	for (size_t i = 0; i < sizeof(ary) / 4; i++)	printf("%d ", ary[i]);
	putchar('\n');

	fclose(fp);

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

int insertionSort(int ary[N])
{
	int next, fnd;

	for (size_t i = 1; i < N; i++)
	{
		next = ary[i];
		for (fnd = i; (fnd >= 1) && (ary[fnd - 1] > next); fnd--)	ary[fnd] = ary[fnd - 1];
		ary[fnd] = next;
	}

	return ary[N];
}
