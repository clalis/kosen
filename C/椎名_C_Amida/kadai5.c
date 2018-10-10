/***  kadai5.c  ***/
/***  s15092  2J23  ’Å–¼ ‘×”V  ***/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARY 38


void InitAmd();
void DispAmd();
int GetRwNum();
int GetColNum();
int RmvBar();
int AddBar();
int GenAmd();
int SolvAmd();


int main()
{
	int mode, start, row, col, bar;
	char buff[64], result, map[MAX_ARY][MAX_ARY] =
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

	while (1)
	{
		printf("\n*\t\t\t\tAmidakuji\t\t\t*\n*\t\t\tMenu\t\t\t\t\t*\n");
		printf("*\tMake:1 Show:2 Delete bar:3 Add bar:4 Answer:5 Exit:6\t*\n");

		fgets(buff, 64, stdin);
		sscanf(buff, "%d", &mode);

		if (mode == 1)
		{
			InitAmd(map);

			printf("Enter [row column bar].\n");

			fgets(buff, 64, stdin);
			sscanf(buff, "%d %d %d", &row, &col, &bar);

			if (GenAmd(map, row, col, bar) != -1)	DispAmd(map);
			else	printf("Can not create Amidakuji under the specified parameters.\n");
		}
		else if (mode == 2)	DispAmd(map);
		else if (mode == 3)
		{
			printf("Enter [row column].\n");

			fgets(buff, 64, stdin);
			sscanf(buff, "%d %d", &row, &col);

			if (RmvBar(map, row, col) == 0)	DispAmd(map);
			else	printf("Can not delete bar under the specified parameters.\n");
		}
		else if (mode == 4)
		{
			printf("Enter [row column].\n");

			fgets(buff, 64, stdin);
			sscanf(buff, "%d %d", &row, &col);

			if (AddBar(map, row, col) == 0)	DispAmd(map);
			else	printf("Can not add bar under the specified parameters.\n");
		}
		else if (mode == 5)
		{
			printf("Enter start position.\n");

			fgets(buff, 64, stdin);
			sscanf(buff, "%d", &start);

			result = SolvAmd(map, start);
			if ((result + 65) != 64)	printf("%c\n", result);
			else	printf("Can not solve under the specified parameters.\n");
		}
		else if (mode == 6)
		{
			printf("\tBye.\n");

			exit(1);
		}
		else	printf("It is not implemented.\n");

		fflush(stdin);
		mode = 0;
	}


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
			if (j % 2)	printf("%c%c%c", map[i][j], map[i][j], map[i][j]);
			else if ((map[i][j] == '|') || (map[i][j] == '*') || (map[i][j] == '\0'))	printf("%c", map[i][j]);
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
	else	return -1;

	return 0;
}

int AddBar(char map[][MAX_ARY],int row,int col)
{
	char buff[16];

	col = col * 2 + 1;

	if (((row > 0) && (row < GetRwNum(map) - 1)) && ((col >= 0) && ((col - 1) / 2 + 1 < GetColNum(map))) && (map[row][col] == ' ') && ((map[row][col + 2] != '-') && (map[row][col - 2] != '-')))	map[row][col] = '-';
	else	return -1;

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

int SolvAmd(char map[][MAX_ARY], int start)
{
	char tempmap[MAX_ARY][MAX_ARY];
	int row = 0, col = start * 2;

	memcpy(tempmap, map, sizeof(char) * pow(MAX_ARY, 2));

	if ((start >= 0) && (start < GetColNum(tempmap)))
	{
		do
		{
			tempmap[row][col] = '*';

			if (col && (tempmap[row][col - 2] != '*') && (tempmap[row][col - 1] == '-'))
			{
				tempmap[row][col - 1] = '*';
				col -= 2;
			}
			else if ((tempmap[row][col + 2] != '*') && (col != GetColNum(tempmap)) && (tempmap[row][col + 1] == '-'))
			{
				tempmap[row][col + 1] = '*';
				col += 2;
			}

			tempmap[row][col] = '*';

			row++;
		}
		while (tempmap[row][col]);

		DispAmd(tempmap);

		return col / 2;
	}
	else	return -1;
}


/**************** ŽÀsŒ‹‰Ê *****************



*                               Amidakuji                       *
*                       Menu                                    *
*       Make:1 Show:2 Delete bar:3 Add bar:4 Answer:5 Exit:6    *


*******************************************/
