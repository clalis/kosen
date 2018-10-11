/***  kadai1.c  ***/
/***  s15092  2J23  í≈ñº ë◊îV  ***/

#include <stdio.h>

#define MAX_ARY 38


void DispAmd();
int GetRwNum();
int GetColNum();


int main()
{
	char map[MAX_ARY][MAX_ARY] =
	{
		{ '|',' ','|',' ','|',' ','|',' ','|','\0' },			//0
		{ '|','-','|',' ','|','-','|',' ','|','\0' },			//1
		{ '|',' ','|',' ','|',' ','|','-','|','\0' },			//2
		{ '|',' ','|','-','|',' ','|',' ','|','\0' },			//3
		{ '|',' ','|','-','|',' ','|','-','|','\0' },			//4
		{ '|','-','|',' ','|','-','|',' ','|','\0' },			//5
		{ '|',' ','|',' ','|',' ','|',' ','|','\0' },			//6
		{ '|','-','|',' ','|',' ','|','-','|','\0' },			//7
		{ '|',' ','|','-','|',' ','|',' ','|','\0' },			//8
		{ '|',' ','|',' ','|','-','|',' ','|','\0' },			//9
		{ '|',' ','|','-','|',' ','|','-','|','\0' },			//10
		{ '|','-','|',' ','|','-','|',' ','|','\0' },			//11
		{ '|',' ','|',' ','|',' ','|',' ','|','\0' },			//12
		{ '|',' ','|','-','|',' ','|','-','|','\0' },			//13
		{ '|','-','|',' ','|',' ','|',' ','|','\0' },			//14
		{ '|',' ','|',' ','|',' ','|',' ','|','\0' },			//15
		{ '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' }	//16
	};

	printf("%d\n", GetRwNum(map));
	printf("%d\n", GetColNum(map));
	DispAmd(map);

	for (size_t i = 0; i < MAX_ARY; i++)	for (size_t j = 0; j < MAX_ARY; j++)	map[i][j] = '|';

	printf("%d\n", GetRwNum(map));
	printf("%d\n", GetColNum(map));
	DispAmd(map);

	return 0;
}


void DispAmd(char map[][MAX_ARY])
{
	if (map[0][1] != ' ')	return;

	putchar('\t');
	for (size_t num = 0; num < GetColNum(map); num++)	printf("%d   ", num);
	putchar('\n');

	for (size_t i = 0; i < GetRwNum(map); i++)
	{
		printf("%2d\t", i);
		for (size_t j = 0; j < GetColNum(map) * 2; j++)
		{
			if (map[i][j] == ' ' || map[i][j] == '-')	printf("%c%c%c", map[i][j], map[i][j], map[i][j]);
			else if (map[i][j] == '|' || map[i][j] == '\0')	printf("%c", map[i][j]);
			else	return;
		}
		putchar('\n');
	}

	putchar('\t');
	for (size_t ch = 0x41; ch < GetColNum(map) + 0x41; ch++)	printf("%c   ", ch);
	putchar('\n');
}

int GetRwNum(char map[][MAX_ARY])
{
	int i = 0;
	while (map[i][0] != '\0')
	{
		i++;
		if (i > MAX_ARY)	return -1;
	}

	return i;
}

int GetColNum(char map[][MAX_ARY])
{
	int i = 0;
	while (map[0][i] != '\0')
	{
		i++;
		if (i > MAX_ARY)	return -1;
	}

	return (i + 1) / 2;
}


/**************** é¿çsåãâ  *****************


16
5
        0   1   2   3   4
 0      |   |   |   |   |
 1      |---|   |---|   |
 2      |   |   |   |---|
 3      |   |---|   |   |
 4      |   |---|   |---|
 5      |---|   |---|   |
 6      |   |   |   |   |
 7      |---|   |   |---|
 8      |   |---|   |   |
 9      |   |   |---|   |
10      |   |---|   |---|
11      |---|   |---|   |
12      |   |   |   |   |
13      |   |---|   |---|
14      |---|   |   |   |
15      |   |   |   |   |
        A   B   C   D   E
-1
-1


*******************************************/
