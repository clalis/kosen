/***  kadai3.c  ***/
/***  s15092  2J23  ’Å–¼ ‘×”V  ***/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARY 38


void InitAmd();
void DispAmd();
int GetRwNum();
int GetColNum();
int RmvBar();
int AddBar();
int GenAmd();


int main()
{
	int row, col, bar;
	char map[MAX_ARY][MAX_ARY], buff[64];

	InitAmd(map);

	fgets(buff, 64, stdin);
	sscanf(buff, "%d %d %d", &row, &col, &bar);

	if (GenAmd(map, row, col, bar) != -1)	DispAmd(map);


	return 0;
}


void InitAmd(char map[][MAX_ARY])
{
	time_t t;
	static char isRndInit = 0;

	for (size_t i = 0; i < MAX_ARY; i++)	for (size_t j = 0; j < MAX_ARY; j++)	map[i][j] = '\0';
	if (!isRndInit)
	{
		srand((unsigned)time(&t));
		isRndInit = 1;
	}
}

void DispAmd(char map[][MAX_ARY])
{
	if (map[0][1] != ' ')	return;

	putchar('\t');
	for (size_t num = 0; num < GetColNum(map); num++)	printf("%2d  ", num);
	putchar('\n');

	for (size_t i = 0; i < GetRwNum(map); i++)
	{
		printf("%2d\t ", i);
		for (size_t j = 0; j < GetColNum(map) * 2; j++)
		{
			if (map[i][j] == ' ' || map[i][j] == '-')	printf("%c%c%c", map[i][j], map[i][j], map[i][j]);
			else if (map[i][j] == '|' || map[i][j] == '\0')	printf("%c", map[i][j]);
			else	return;
		}
		putchar('\n');
	}

	putchar('\t');
	for (size_t ch = 0x41; ch < GetColNum(map) + 0x41; ch++)	printf("%2c  ", ch);
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

int RmvBar(char map[][MAX_ARY],int row,int col)
{
	char buff[16];

	col = col * 2 + 1;

	if (((row > 0) && (row < GetRwNum(map) - 1)) && ((col >= 0) && (col <= GetColNum(map))) && (map[row][col] == '-'))	map[row][col] = ' ';
	else return -1;

	return 0;
}

int AddBar(char map[][MAX_ARY],int row,int col)
{
	char buff[16];

	col = col * 2 + 1;

	if (((row > 0) && (row < GetRwNum(map) - 1)) && ((col >= 0) && ((col - 1) / 2 + 1 < GetColNum(map))) && (map[row][col] == ' ') && ((map[row][col + 2] != '-') && (map[row][col - 2] != '-')))	map[row][col] = '-';
	else return -1;

	return 0;
}

int GenAmd(char map[][MAX_ARY], int row, int col, int bar)
{
	int i, j, k;

	if (((row >= 3) && (row < MAX_ARY)) && ((col >= 2) && (col * 2 - 1 < MAX_ARY)) && ((bar > 0) && (bar <= (row - 2) * (col - 1) / 2)))
	{
		for (i = 0; i < row; i++)	for (j = 0; j < col; j++)
		{
			map[i][j * 2] = '|';
			if (j * 2 + 1 >= MAX_ARY)	break;
			map[i][j * 2 + 1] = ' ';
		}

		for (k = 0; k < bar; k++)
		{
			if (!AddBar(map, (unsigned)rand() % row, (unsigned)rand() % col));
			
			else	k--;
		}

		return k;
	}

	return -1;
}


/**************** ŽÀsŒ‹‰Ê *****************


5 5 6
         0   1   2   3   4
 0       |   |   |   |   |
 1       |   |---|   |---|
 2       |---|   |   |---|
 3       |---|   |   |---|
 4       |   |   |   |   |
         A   B   C   D   E

5 6 6
         0   1   2   3   4   5
 0       |   |   |   |   |   |
 1       |---|   |   |   |---|
 2       |---|   |   |---|   |
 3       |   |---|   |---|   |
 4       |   |   |   |   |   |
         A   B   C   D   E   F

2 4 1

38 5 6

5 1 1

5 20 6

5 4 -1

5 5 7

5 6 8


*******************************************/
