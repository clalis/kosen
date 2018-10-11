// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#define _CRT_SECURE_NO_WARNINGS
#define N 1000000
#define swap(a, b) a^=b^=a^=b
#define swap_adv(type, a, b) do{type tmp = a; a = b; b = tmp;}	while(0)

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

//#include "stdafx.h"


void bubbleSort(int *ary);
void selectionSort(int *ary);
void insertionSort(int *ary);
void shakerSort(int *ary);
void shellSort(int *ary);	//Init. as (ary, 0, N - 1)
void quickSort(int *ary, int l, int r);
void heapSort(int *ary);
void heap(int *ary, int root, int leaf);
void mergeSort(int *ary, int l, int r);	//Init. as (ary, 0, N - 1)
void merge(int *ary, int l, int m, int r);
void binarySearch(int *ary, int tgt, int nmin, int nmax);	//Init. as (ary, [a number u want], 0, N)

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
	if ((fp = fopen(/*&fn*/"C:\\Users\\TeamET\\Downloads\\kadai-5-2.txt", "r")) == NULL)
	{
		fprintf(stderr, "File can't open.\n");
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < N; i++)	fscanf(fp, "%d", &ary[i]);

	//for (size_t i = 0; i < N; i++)	printf("%d ", ary[i]);
	putchar('\n');

	quickSort(ary, 0, N - 1);
	binarySearch(ary, 644104147, 0, N);

	//for (size_t i = 0; i < N; i++)	printf("%d ", ary[i]);
	putchar('\n');

	fclose(fp);
	free(ary);

	return 0;
}

void bubbleSort(int *ary)
{
	//int temp;

	for (size_t t = N - 1; 0 < t; t--)	for (size_t i = 0; i < t; i++)	if (ary[i] > ary[i + 1])
	{
		swap(ary[i], ary[i + 1]);
	}
}

void selectionSort(int *ary)
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
}

void insertionSort(int *ary)
{
	int next, fnd;

	for (size_t i = 1; i < N; i++)
	{
		next = ary[i];
		for (fnd = i; (fnd >= 1) && (ary[fnd - 1] > next); fnd--)	ary[fnd] = ary[fnd - 1];
		ary[fnd] = next;
	}
}

void shakerSort(int *ary)
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
}

void shellSort(int *ary)
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
}

void quickSort(int *ary, int l, int r)
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
}

void heapSort(int *ary)
{
	for (size_t i = (N - 1) / 2; i >= 0; i--)	heap(ary, i, N - 1);

	for (size_t i = N - 1; i > 0; i--)
	{
		swap_adv(int, ary[0], ary[i]);
		heap(ary, 0, i - 1);
	}
}

void heap(int *ary, int root, int leaf)
{
	int ind_l = (root * 2) + 1;
	int ind_r = (root * 2) + 2;
	int ind_max;	//node_max?

	if ((ind_l <= leaf) && (ary[ind_l] > ary[root]))	ind_max = ind_l;
	else	ind_max = root;

	if ((ind_r <= leaf) && (ary[ind_r] > ary[ind_max]))	ind_max = ind_r;

	if (ind_max != root)
	{
		swap_adv(int, ary[root], ary[ind_max]);
		heap(ary, ind_max, leaf);
	}
}

void mergeSort(int *ary, int l, int r)
{
	int m;

	if (l < r)
	{
		m = (l + r) / 2;
		mergeSort(ary, l, m);
		mergeSort(ary, m + 1, r);

		merge(ary, l, m + 1, r);
	}
}

void merge(int *ary, int l, int m, int r)
{
	int *tmp = { 0 }, tmp_pos, l_end, ary_elmnts;

	l_end = m - 1;
	tmp_pos = l;
	ary_elmnts = r - l + 1;

	while ((m <= r) && (l <= l_end))
	{
		if (ary[l] <= ary[m])
		{
			tmp[tmp_pos] = ary[l];
			tmp_pos++;
			l++;
		}
		else
		{
			tmp[tmp_pos] = ary[m];
			tmp_pos++;
			m++;
		}
	}

	while (l <= l_end)
	{
		tmp[tmp_pos] = ary[l];
		l++;
		tmp_pos++;
	}
	while (m <= r)
	{
		tmp[tmp_pos] = ary[m];
		m++;
		tmp_pos++;
	}

	for (size_t i = 0; i <= ary_elmnts; i++)
	{
		ary[r] = tmp[r];
		r--;
	}
}

void binarySearch(int * ary, int tgt, int nmin, int nmax)
{
	if (nmin > nmax)	printf("Not found.\n");
	else
	{
		int nmid = nmin + (nmax - nmin) / 2;

		if (ary[nmid] > tgt)	return binarySearch(ary, tgt, nmin, nmid - 1);
		else if (ary[nmid] < tgt)	return binarySearch(ary, tgt, nmid + 1, nmax);
		else	printf("No. %d\n", nmid);
	}
}
