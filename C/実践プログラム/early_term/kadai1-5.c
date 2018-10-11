#define _CRT_SECURE_NO_WARNINGS
#define N 100

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>


int bubbleSort(int ary[N]);
int selectionSort(int ary[N]);
int insertionSort(int ary[N]);
int invBubbleSort(int ary[N]);
int invSelectionSort(int ary[N]);
int invInsertionSort(int ary[N]);

int c = 0;

int main()
{
	FILE *fpi, *fpo;
	int ary[N], mode, len;
	char *fn, *newfn, buff[256];

	fn = (char*)malloc(sizeof(char) * 256);
	newfn = (char*)malloc(sizeof(char) * 256);

	//for (size_t i = 0; i < sizeof(ary) / 4; i++)
	//{
	//	fgets(buff, sizeof(buff), stdin);
	//	sscanf(buff, "%d", &(ary[i]));
	//}

	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%s", fn);
	if ((fpi = fopen(fn, "r")) == NULL)
	{
		printf("File can't open.\n");
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < N; i++)	fscanf(fpi, "%d", &(ary[i]));

	strcpy(newfn, fn);
	len = strlen(fn);
	for (size_t i = len - 1; i > 0; i--)
	{
		if (newfn[i] == '.')
		{
			newfn[i] = '\0';
			break;
		}
	}
	sprintf(newfn, "%s.rtf", newfn);

	if ((fpo = fopen(newfn, "w")) = NULL)
	{
		printf("File can't open.\n");
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < N; i++)	fprintf(fpo, "&d", &(ary[i]));

	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", mode);

	for (size_t i = 0; i < sizeof(ary) / 4; i++)	printf("%d ", ary[i]);
	putchar('\n');

	switch (mode)
	{
	case 0:
		bubbleSort(ary);
	case 1:
		selectionSort(ary);
	case 2:
		insertionSort(ary);
	case 3:
		invBubbleSort(ary);
	case 4:
		invSelectionSort(ary);
	case 5:
		invInsertionSort(ary);
	default:
		break;
	}

	for (size_t i = 0; i < sizeof(ary) / 4; i++)	printf("%d ", ary[i]);
	putchar('\n');

	printf("phase:%d", c);

	fclose(fpi);
	fclose(fpi);
	free(fn);
	free(newfn);

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
		c++;
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
		c++;
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
		c++;
	}

	return ary[N];
}

int invBubbleSort(int ary[N])
{
	int temp;

	for (size_t t = N - 1; 0 < t; t--)	for (size_t i = 0; i < t; i++)	if (ary[i] < ary[i + 1])
	{
		temp = ary[i];
		ary[i] = ary[i + 1];
		ary[i + 1] = temp;
		c++;
	}

	return ary[N];
}

int invSelectionSort(int ary[N])
{
	int temp, max;

	for (size_t t = 0; t < N; t++)
	{
		max = t;
		for (size_t i = t + 1; i < N; i++)	if (ary[i] > ary[max])
		{
			max = i;
		}
		temp = ary[t];
		ary[t] = ary[max];
		ary[max] = temp;
		c++;
	}

	return ary[N];
}

int invInsertionSort(int ary[N])
{
	int next, fnd;

	for (size_t i = 1; i < N; i++)
	{
		next = ary[i];
		for (fnd = i; (fnd >= 1) && (ary[fnd - 1] < next); fnd--)	ary[fnd] = ary[fnd - 1];
		ary[fnd] = next;
		c++;
	}

	return ary[N];
}
