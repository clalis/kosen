// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#define _CRT_SECURE_NO_WARNINGS
#define N 1000000
#define swap(a, b) a^=b^=a^=b

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

//#include "stdafx.h"


int bubbleSort(int *ary);
int selectionSort(int *ary);
int insertionSort(int *ary);
int shakerSort(int *ary);
int shellSort(int *ary);	//Init. as (ary, 0, N - 1)
int quickSort(int *ary, int l, int r);

int main(int argc, char *argv[])
{
	FILE *fp;
	int *ary;
	char fn, buff[256];

	if ((ary = (int *)malloc(sizeof(int) * N)) == NULL)
	{
		fprintf(stderr, "Fail to insure memories.\n");
		exit(EXIT_FAILURE);
	}

	//for (size_t i = 0; i < sizeof(ary) / 4; i++)
	//{
	//	fgets(buff, sizeof(buff), stdin);
	//	sscanf(buff, "%d", &(ary[i]));
	//}

	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%s", &fn);
	if ((fp = fopen(&fn, "r")) == NULL)
	{
		fprintf(stderr, "File can't open.\n");
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < N; i++)	fscanf(fp, "%d", &ary[i]);

	for (size_t i = 0; i < N; i++)	printf("%d ", ary[i]);
	putchar('\n');

	quickSort(ary, 0, N - 1);

	for (size_t i = 0; i < N; i++)	printf("%d ", ary[i]);
	putchar('\n');

	fclose(fp);
	free(ary);

	return 0;
}

int bubbleSort(int *ary)
{
	int temp;

	for (size_t t = N - 1; 0 < t; t--)	for (size_t i = 0; i < t; i++)	if (ary[i] > ary[i + 1])
	{
		swap(ary[i], ary[i + 1]);
	}

	return *ary;
}

int selectionSort(int *ary)
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

	return *ary;
}

int insertionSort(int *ary)
{
	int next, fnd;

	for (size_t i = 1; i < N; i++)
	{
		next = ary[i];
		for (fnd = i; (fnd >= 1) && (ary[fnd - 1] > next); fnd--)	ary[fnd] = ary[fnd - 1];
		ary[fnd] = next;
	}

	return *ary;
}

int shakerSort(int *ary)
{
	int top = 0;
	int bott = N - 1;

	while (1)
	{
		int last;

		last = top;
		for (size_t i = top; i < bott; i++)
		{
			if (ary[i] > ary[i + 1])
			{
				swap(ary[i], ary[i + 1]);
				last = i;
			}
		}
		bott = last;
		if (top == bott)	break;

		last = bott;
		for (size_t i = bott; i > top; i--)
		{
			if (ary[i] < ary[i - 1])
			{
				swap(ary[i], ary[i - 1]);
				last = i;
			}
		}
		top = last;
		if (top == bott)	break;
	}

	return 0;
}

int shellSort(int *ary)
{
	unsigned int h = 1, n, tmp;

	while (3 * h + 1 <= N / 9)	h = 3 * h + 1;

	while (h > 0)
	{
		for (size_t i = h; i < N; ++i)
		{
			tmp = ary[i];
			for (n = i; (n >= h) && (ary[n - h] > tmp); n -= h)	*ary = ary[n - h];
			*ary = tmp;
		}
		h /= 3;
	}

	return 0;
}

int quickSort(int *ary, int l, int r)
{
	int pivot = ary[l], tmp_l = l, tmp_r = r;

	while (l < r)
	{
		while ((ary[r] >= pivot) && (l < r))	r--;
		if (l != r)
		{
			ary[l] = ary[r];
			l++;
		}
		while ((ary[l] <= pivot) && (l < r))	l++;
		if (l != r)
		{
			ary[r] = ary[l];
			r--;
		}
	}

	ary[l] = pivot;
	pivot = l;
	l = tmp_l;
	r = tmp_r;
	if (l < pivot)	quickSort(ary, l, pivot - 1);
	if (r > pivot)	quickSort(ary, pivot + 1, r);

	return 0;
}
