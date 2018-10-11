#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>


int bubbleSort(int ary[N]);

int main()
{
	int ary[N];
	char buff[256];

	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d %d %d %d %d %d %d %d %d %d", &ary, &ary, &ary, &ary, &ary, &ary, &ary, &ary, &ary, &ary);

	for (size_t i = 0; i < sizeof(ary); i++)	printf("%d", ary[i]);
	putchar('\n');

	bubbleSort(ary);

	for (size_t i = 0; i < sizeof(ary); i++)	printf("%d", ary[i]);
	putchar('\n');

	return 0;
}

int bubbleSort(int ary[N])
{
	int temp;

	for (size_t t = N - 1; 0 < t; t--)	for (size_t i = 0; t < i; t++)	if (ary[i] < ary[i + 1])
	{
		temp = ary[i];
		ary[i] = ary[i + 1];
		ary[i + 1] = temp;
	}

	return ary[N];
}
