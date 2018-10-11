/***  p10ex02.c  ***/
/***  s15092  2J23  椎名 泰之  ***/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


void printBoard(void);
void columnwork(int column);

uint64_t cnt = 0;
char board[8][8] = {0};													//置かれている：「Q」，いない「o」
char rowline[8] = {0};													//行の占有状態を示す配列 0 or 1
char rightupline[15] = {0};												//「左下から右上方向の列」の占有状態を示す配列 0 or 1
char rightdownline[15] = {0};											//「左上から右下方向の列」の占有状態を示す配列 0 or 1

int main()
{
	for (size_t i = 0; i < 8; i++)	for(size_t j = 0; j < 8; j++)	board[i][j] = 'o';

	columnwork(0);

	return 0;
}

void printBoard(void)
{
	printf("No.%I64d\n", cnt);
	cnt++;
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)	printf("%c ", board[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

void columnwork(int column)													//列に関する作業
{
	int row;

	if (column == 8)
	{
		printBoard();
		return;
	}
	for (row = 0; row < 8; row++)
	{
		if ((rowline[row] == 0) && (rightupline[row + column] == 0) && (rightdownline[row - column + 7] == 0))
		{
			rowline[row] = 1;
			rightupline[row + column] = 1;
			rightdownline[row - column + 7] = 1;
			board[row][column] = 'Q';
			columnwork(column + 1);
			rowline[row] = 0;
			rightupline[row + column] = 0;
			rightdownline[row - column + 7] = 0;
			board[row][column] = 'o';
		}
	}
}


/**************** 実行結果 *****************


No.0
Q o o o o o o o 
o o o o o o Q o 
o o o o Q o o o 
o o o o o o o Q 
o Q o o o o o o 
o o o Q o o o o 
o o o o o Q o o 
o o Q o o o o o 

No.1
Q o o o o o o o 
o o o o o o Q o 
o o o Q o o o o 
o o o o o Q o o 
o o o o o o o Q 
o Q o o o o o o 
o o o o Q o o o 
o o Q o o o o o 

No.2
Q o o o o o o o 
o o o o o Q o o 
o o o o o o o Q 
o o Q o o o o o 
o o o o o o Q o 
o o o Q o o o o 
o Q o o o o o o 
o o o o Q o o o 

No.3
Q o o o o o o o 
o o o o Q o o o 
o o o o o o o Q 
o o o o o Q o o 
o o Q o o o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o Q o o o o 

No.4
o o o o o Q o o 
Q o o o o o o o 
o o o o Q o o o 
o Q o o o o o o 
o o o o o o o Q 
o o Q o o o o o 
o o o o o o Q o 
o o o Q o o o o 

No.5
o o o Q o o o o 
Q o o o o o o o 
o o o o Q o o o 
o o o o o o o Q 
o Q o o o o o o 
o o o o o o Q o 
o o Q o o o o o 
o o o o o Q o o 

No.6
o o o o Q o o o 
Q o o o o o o o 
o o o o o o o Q 
o o o Q o o o o 
o Q o o o o o o 
o o o o o o Q o 
o o Q o o o o o 
o o o o o Q o o 

No.7
o o Q o o o o o 
Q o o o o o o o 
o o o o o o Q o 
o o o o Q o o o 
o o o o o o o Q 
o Q o o o o o o 
o o o Q o o o o 
o o o o o Q o o 

No.8
o o o o Q o o o 
Q o o o o o o o 
o o o Q o o o o 
o o o o o Q o o 
o o o o o o o Q 
o Q o o o o o o 
o o o o o o Q o 
o o Q o o o o o 

No.9
o o o o o o Q o 
Q o o o o o o o 
o o Q o o o o o 
o o o o o o o Q 
o o o o o Q o o 
o o o Q o o o o 
o Q o o o o o o 
o o o o Q o o o 

No.10
o o o o Q o o o 
Q o o o o o o o 
o o o o o o o Q 
o o o o o Q o o 
o o Q o o o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o Q o o o o 

No.11
o o o Q o o o o 
Q o o o o o o o 
o o o o Q o o o 
o o o o o o o Q 
o o o o o Q o o 
o o Q o o o o o 
o o o o o o Q o 
o Q o o o o o o 

No.12
o Q o o o o o o 
o o o o o Q o o 
Q o o o o o o o 
o o o o o o Q o 
o o o Q o o o o 
o o o o o o o Q 
o o Q o o o o o 
o o o o Q o o o 

No.13
o o o o Q o o o 
o o Q o o o o o 
Q o o o o o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o o o o o Q 
o o o o o Q o o 
o o o Q o o o o 

No.14
o o o o o o o Q 
o o Q o o o o o 
Q o o o o o o o 
o o o o o Q o o 
o Q o o o o o o 
o o o o Q o o o 
o o o o o o Q o 
o o o Q o o o o 

No.15
o o o Q o o o o 
o o o o o Q o o 
Q o o o o o o o 
o o o o Q o o o 
o Q o o o o o o 
o o o o o o o Q 
o o Q o o o o o 
o o o o o o Q o 

No.16
o o o o Q o o o 
o o o o o o Q o 
Q o o o o o o o 
o o o Q o o o o 
o Q o o o o o o 
o o o o o o o Q 
o o o o o Q o o 
o o Q o o o o o 

No.17
o o o o o Q o o 
o o Q o o o o o 
Q o o o o o o o 
o o o o o o o Q 
o o o Q o o o o 
o Q o o o o o o 
o o o o o o Q o 
o o o o Q o o o 

No.18
o o o o Q o o o 
o o Q o o o o o 
Q o o o o o o o 
o o o o o Q o o 
o o o o o o o Q 
o Q o o o o o o 
o o o Q o o o o 
o o o o o o Q o 

No.19
o o o o o Q o o 
o o Q o o o o o 
Q o o o o o o o 
o o o o o o o Q 
o o o o Q o o o 
o Q o o o o o o 
o o o Q o o o o 
o o o o o o Q o 

No.20
o o o Q o o o o 
o o o o o o o Q 
Q o o o o o o o 
o o Q o o o o o 
o o o o o Q o o 
o Q o o o o o o 
o o o o o o Q o 
o o o o Q o o o 

No.21
o o o o o o o Q 
o o o Q o o o o 
Q o o o o o o o 
o o Q o o o o o 
o o o o o Q o o 
o Q o o o o o o 
o o o o o o Q o 
o o o o Q o o o 

No.22
o o o Q o o o o 
o o o o o o o Q 
Q o o o o o o o 
o o o o Q o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o o o Q o o 
o o Q o o o o o 

No.23
o o o Q o o o o 
o o o o o o Q o 
Q o o o o o o o 
o o o o o o o Q 
o o o o Q o o o 
o Q o o o o o o 
o o o o o Q o o 
o o Q o o o o o 

No.24
o o o o o Q o o 
o o o Q o o o o 
Q o o o o o o o 
o o o o Q o o o 
o o o o o o o Q 
o Q o o o o o o 
o o o o o o Q o 
o o Q o o o o o 

No.25
o o o o o Q o o 
o o Q o o o o o 
Q o o o o o o o 
o o o o o o Q o 
o o o o Q o o o 
o o o o o o o Q 
o Q o o o o o o 
o o o Q o o o o 

No.26
o o o o o o Q o 
o o Q o o o o o 
Q o o o o o o o 
o o o o o Q o o 
o o o o o o o Q 
o o o o Q o o o 
o Q o o o o o o 
o o o Q o o o o 

No.27
o o o o Q o o o 
o o o o o o Q o 
Q o o o o o o o 
o o Q o o o o o 
o o o o o o o Q 
o o o o o Q o o 
o o o Q o o o o 
o Q o o o o o o 

No.28
o Q o o o o o o 
o o o o Q o o o 
o o o o o o Q o 
Q o o o o o o o 
o o Q o o o o o 
o o o o o o o Q 
o o o o o Q o o 
o o o Q o o o o 

No.29
o Q o o o o o o 
o o o o o o o Q 
o o o o o Q o o 
Q o o o o o o o 
o o Q o o o o o 
o o o o Q o o o 
o o o o o o Q o 
o o o Q o o o o 

No.30
o o o o o Q o o 
o Q o o o o o o 
o o o o o o Q o 
Q o o o o o o o 
o o Q o o o o o 
o o o o Q o o o 
o o o o o o o Q 
o o o Q o o o o 

No.31
o o o o o o Q o 
o Q o o o o o o 
o o o Q o o o o 
Q o o o o o o o 
o o o o o o o Q 
o o o o Q o o o 
o o Q o o o o o 
o o o o o Q o o 

No.32
o o o o o o o Q 
o Q o o o o o o 
o o o Q o o o o 
Q o o o o o o o 
o o o o o o Q o 
o o o o Q o o o 
o o Q o o o o o 
o o o o o Q o o 

No.33
o o o o Q o o o 
o Q o o o o o o 
o o o o o o o Q 
Q o o o o o o o 
o o o Q o o o o 
o o o o o o Q o 
o o Q o o o o o 
o o o o o Q o o 

No.34
o o o o o Q o o 
o Q o o o o o o 
o o o o o o Q o 
Q o o o o o o o 
o o o Q o o o o 
o o o o o o o Q 
o o o o Q o o o 
o o Q o o o o o 

No.35
o o o o Q o o o 
o Q o o o o o o 
o o o o o Q o o 
Q o o o o o o o 
o o o o o o Q o 
o o o Q o o o o 
o o o o o o o Q 
o o Q o o o o o 

No.36
o o Q o o o o o 
o o o o Q o o o 
o o o o o o Q o 
Q o o o o o o o 
o o o Q o o o o 
o Q o o o o o o 
o o o o o o o Q 
o o o o o Q o o 

No.37
o o o o o Q o o 
o o o Q o o o o 
o o o o o o Q o 
Q o o o o o o o 
o o o o o o o Q 
o Q o o o o o o 
o o o o Q o o o 
o o Q o o o o o 

No.38
o o o o Q o o o 
o o o o o o o Q 
o o o Q o o o o 
Q o o o o o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o o o Q o o 
o o Q o o o o o 

No.39
o o Q o o o o o 
o o o o o Q o o 
o o o o o o o Q 
Q o o o o o o o 
o o o o Q o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o Q o o o o 

No.40
o o o o o o Q o 
o o o o Q o o o 
o o Q o o o o o 
Q o o o o o o o 
o o o o o Q o o 
o o o o o o o Q 
o Q o o o o o o 
o o o Q o o o o 

No.41
o o o o o Q o o 
o o o Q o o o o 
o o o o o o Q o 
Q o o o o o o o 
o o Q o o o o o 
o o o o Q o o o 
o Q o o o o o o 
o o o o o o o Q 

No.42
o o o o Q o o o 
o o o o o o o Q 
o o o Q o o o o 
Q o o o o o o o 
o o Q o o o o o 
o o o o o Q o o 
o Q o o o o o o 
o o o o o o Q o 

No.43
o o Q o o o o o 
o o o o o Q o o 
o o o Q o o o o 
Q o o o o o o o 
o o o o o o o Q 
o o o o Q o o o 
o o o o o o Q o 
o Q o o o o o o 

No.44
o o Q o o o o o 
o o o o o Q o o 
o o o o o o o Q 
Q o o o o o o o 
o o o Q o o o o 
o o o o o o Q o 
o o o o Q o o o 
o Q o o o o o o 

No.45
o o o o Q o o o 
o o o o o o Q o 
o o o Q o o o o 
Q o o o o o o o 
o o Q o o o o o 
o o o o o o o Q 
o o o o o Q o o 
o Q o o o o o o 

No.46
o Q o o o o o o 
o o o o o Q o o 
o o o o o o o Q 
o o Q o o o o o 
Q o o o o o o o 
o o o Q o o o o 
o o o o o o Q o 
o o o o Q o o o 

No.47
o Q o o o o o o 
o o o o Q o o o 
o o o o o o Q o 
o o o Q o o o o 
Q o o o o o o o 
o o o o o o o Q 
o o o o o Q o o 
o o Q o o o o o 

No.48
o Q o o o o o o 
o o o o o o Q o 
o o o o Q o o o 
o o o o o o o Q 
Q o o o o o o o 
o o o Q o o o o 
o o o o o Q o o 
o o Q o o o o o 

No.49
o o o o o o Q o 
o Q o o o o o o 
o o o o o Q o o 
o o Q o o o o o 
Q o o o o o o o 
o o o Q o o o o 
o o o o o o o Q 
o o o o Q o o o 

No.50
o o o o o o o Q 
o Q o o o o o o 
o o o o Q o o o 
o o Q o o o o o 
Q o o o o o o o 
o o o o o o Q o 
o o o Q o o o o 
o o o o o Q o o 

No.51
o o o Q o o o o 
o Q o o o o o o 
o o o o o o o Q 
o o o o o Q o o 
Q o o o o o o o 
o o Q o o o o o 
o o o o Q o o o 
o o o o o o Q o 

No.52
o o o Q o o o o 
o Q o o o o o o 
o o o o o o Q o 
o o o o Q o o o 
Q o o o o o o o 
o o o o o o o Q 
o o o o o Q o o 
o o Q o o o o o 

No.53
o o Q o o o o o 
o o o o o Q o o 
o Q o o o o o o 
o o o o o o Q o 
Q o o o o o o o 
o o o Q o o o o 
o o o o o o o Q 
o o o o Q o o o 

No.54
o o Q o o o o o 
o o o o Q o o o 
o Q o o o o o o 
o o o o o o o Q 
Q o o o o o o o 
o o o o o o Q o 
o o o Q o o o o 
o o o o o Q o o 

No.55
o o o o o Q o o 
o o o o o o o Q 
o Q o o o o o o 
o o o Q o o o o 
Q o o o o o o o 
o o o o o o Q o 
o o o o Q o o o 
o o Q o o o o o 

No.56
o o Q o o o o o 
o o o o o o o Q 
o o o Q o o o o 
o o o o o o Q o 
Q o o o o o o o 
o o o o o Q o o 
o Q o o o o o o 
o o o o Q o o o 

No.57
o o Q o o o o o 
o o o o Q o o o 
o o o o o o o Q 
o o o Q o o o o 
Q o o o o o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o o o Q o o 

No.58
o o o o o Q o o 
o o Q o o o o o 
o o o o o o Q o 
o o o Q o o o o 
Q o o o o o o o 
o o o o o o o Q 
o Q o o o o o o 
o o o o Q o o o 

No.59
o o o o o Q o o 
o o Q o o o o o 
o o o o Q o o o 
o o o o o o Q o 
Q o o o o o o o 
o o o Q o o o o 
o Q o o o o o o 
o o o o o o o Q 

No.60
o o o o o Q o o 
o o Q o o o o o 
o o o o Q o o o 
o o o o o o o Q 
Q o o o o o o o 
o o o Q o o o o 
o Q o o o o o o 
o o o o o o Q o 

No.61
o o o Q o o o o 
o o o o o o o Q 
o o o o Q o o o 
o o Q o o o o o 
Q o o o o o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o o o Q o o 

No.62
o o o Q o o o o 
o o o o o o Q o 
o o o o Q o o o 
o o Q o o o o o 
Q o o o o o o o 
o o o o o Q o o 
o o o o o o o Q 
o Q o o o o o o 

No.63
o o o Q o o o o 
o o o o o Q o o 
o o o o o o o Q 
o o Q o o o o o 
Q o o o o o o o 
o o o o o o Q o 
o o o o Q o o o 
o Q o o o o o o 

No.64
o Q o o o o o o 
o o o Q o o o o 
o o o o o Q o o 
o o o o o o o Q 
o o Q o o o o o 
Q o o o o o o o 
o o o o o o Q o 
o o o o Q o o o 

No.65
o o o Q o o o o 
o Q o o o o o o 
o o o o Q o o o 
o o o o o o o Q 
o o o o o Q o o 
Q o o o o o o o 
o o Q o o o o o 
o o o o o o Q o 

No.66
o o o Q o o o o 
o Q o o o o o o 
o o o o o o o Q 
o o o o Q o o o 
o o o o o o Q o 
Q o o o o o o o 
o o Q o o o o o 
o o o o o Q o o 

No.67
o o Q o o o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o o o o o Q 
o o o o Q o o o 
Q o o o o o o o 
o o o Q o o o o 
o o o o o Q o o 

No.68
o o Q o o o o o 
o o o o o Q o o 
o Q o o o o o o 
o o o o Q o o o 
o o o o o o o Q 
Q o o o o o o o 
o o o o o o Q o 
o o o Q o o o o 

No.69
o o Q o o o o o 
o o o o o Q o o 
o Q o o o o o o 
o o o o o o Q o 
o o o o Q o o o 
Q o o o o o o o 
o o o o o o o Q 
o o o Q o o o o 

No.70
o o o o Q o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o o o Q o o 
o o Q o o o o o 
Q o o o o o o o 
o o o Q o o o o 
o o o o o o o Q 

No.71
o o o o Q o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o o o Q o o 
o o Q o o o o o 
Q o o o o o o o 
o o o o o o o Q 
o o o Q o o o o 

No.72
o o o o o o Q o 
o o o Q o o o o 
o Q o o o o o o 
o o o o Q o o o 
o o o o o o o Q 
Q o o o o o o o 
o o Q o o o o o 
o o o o o Q o o 

No.73
o o o o o o Q o 
o o o Q o o o o 
o Q o o o o o o 
o o o o o o o Q 
o o o o o Q o o 
Q o o o o o o o 
o o Q o o o o o 
o o o o Q o o o 

No.74
o o o o Q o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o Q o o o o 
o o o o o o o Q 
Q o o o o o o o 
o o Q o o o o o 
o o o o o Q o o 

No.75
o o Q o o o o o 
o o o o o Q o o 
o o o o o o o Q 
o Q o o o o o o 
o o o Q o o o o 
Q o o o o o o o 
o o o o o o Q o 
o o o o Q o o o 

No.76
o o o o o o Q o 
o o Q o o o o o 
o o o o o o o Q 
o Q o o o o o o 
o o o o Q o o o 
Q o o o o o o o 
o o o o o Q o o 
o o o Q o o o o 

No.77
o o o Q o o o o 
o o o o o o Q o 
o o o o Q o o o 
o Q o o o o o o 
o o o o o Q o o 
Q o o o o o o o 
o o Q o o o o o 
o o o o o o o Q 

No.78
o o o Q o o o o 
o o o o o Q o o 
o o o o o o o Q 
o Q o o o o o o 
o o o o o o Q o 
Q o o o o o o o 
o o Q o o o o o 
o o o o Q o o o 

No.79
o o o o Q o o o 
o o Q o o o o o 
o o o o o o o Q 
o o o Q o o o o 
o o o o o o Q o 
Q o o o o o o o 
o o o o o Q o o 
o Q o o o o o o 

No.80
o Q o o o o o o 
o o o o o o Q o 
o o Q o o o o o 
o o o o o Q o o 
o o o o o o o Q 
o o o o Q o o o 
Q o o o o o o o 
o o o Q o o o o 

No.81
o o o Q o o o o 
o Q o o o o o o 
o o o o o o Q o 
o o Q o o o o o 
o o o o o Q o o 
o o o o o o o Q 
Q o o o o o o o 
o o o o Q o o o 

No.82
o o o o Q o o o 
o Q o o o o o o 
o o o Q o o o o 
o o o o o Q o o 
o o o o o o o Q 
o o Q o o o o o 
Q o o o o o o o 
o o o o o o Q o 

No.83
o o Q o o o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o o o o o Q 
o o o o o Q o o 
o o o Q o o o o 
Q o o o o o o o 
o o o o Q o o o 

No.84
o o o o o Q o o 
o o o Q o o o o 
o Q o o o o o o 
o o o o o o o Q 
o o o o Q o o o 
o o o o o o Q o 
Q o o o o o o o 
o o Q o o o o o 

No.85
o o o o o Q o o 
o o Q o o o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o Q o o o o 
o o o o o o o Q 
Q o o o o o o o 
o o o o Q o o o 

No.86
o o o o o Q o o 
o o Q o o o o o 
o o o o o o Q o 
o Q o o o o o o 
o o o o o o o Q 
o o o o Q o o o 
Q o o o o o o o 
o o o Q o o o o 

No.87
o o o Q o o o o 
o o o o o o Q o 
o o Q o o o o o 
o o o o o o o Q 
o Q o o o o o o 
o o o o Q o o o 
Q o o o o o o o 
o o o o o Q o o 

No.88
o o o Q o o o o 
o Q o o o o o o 
o o o o o o Q o 
o o Q o o o o o 
o o o o o Q o o 
o o o o o o o Q 
o o o o Q o o o 
Q o o o o o o o 

No.89
o o o o Q o o o 
o Q o o o o o o 
o o o Q o o o o 
o o o o o o Q o 
o o Q o o o o o 
o o o o o o o Q 
o o o o o Q o o 
Q o o o o o o o 

No.90
o o Q o o o o o 
o o o o Q o o o 
o Q o o o o o o 
o o o o o o o Q 
o o o o o Q o o 
o o o Q o o o o 
o o o o o o Q o 
Q o o o o o o o 

No.91
o o Q o o o o o 
o o o o o Q o o 
o o o Q o o o o 
o Q o o o o o o 
o o o o o o o Q 
o o o o Q o o o 
o o o o o o Q o 
Q o o o o o o o 


*******************************************/
