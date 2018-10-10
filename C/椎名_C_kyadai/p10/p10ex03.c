/***  p10ex03.c  ***/
/***  s15092  2J23  椎名 泰之  ***/


#define N 9												//マス数

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


/******************************************************
５×５の盤面でのチェスのknightの移動で盤面すべてのセルを
通過する手順を見つけて表示します。
５×５の配列をつくり，訪問していないところには０を埋め
訪問したところには，訪問順番号を書きます。
ただし盤面端のチェックを簡単にするため，周囲外側に２列
多く配列をつくり，-1を埋めておきます。

  x 0 1 2 3 4 5 6 7 8
y
0  -1-1-1-1-1-1-1-1-1
1  -1-1-1-1-1-1-1-1-1
2  -1-1 0 0 0 0 0-1-1
3  -1-1 0 0 0 0 0-1-1
4  -1-1 0 0 0 0 0-1-1
5  -1-1 0 0 0 0 0-1-1
6  -1-1 0 0 0 0 0-1-1
7  -1-1-1-1-1-1-1-1-1
8  -1-1-1-1-1-1-1-1-1

******************************************************/


typedef struct
{
	long long int x;
	long long int y;
} move_t;											//一手先の移動量を表す型

move_t move[8] =
{
	{ 2, 1 },{ 1, 2 },{ -1, 2 },{ -2, 1 },{ -2, -1 },{ -1, -2 },{ 1, -2 },{ 2, -1 }
};														//一手の移動量の全種類

long long int board[N + 4][N + 4];						//盤面配列
long long int counter;									//手数カウンタ

void initBoard(void);									//盤面の初期化
void knighttour(long long int x, long long int y);		// 盤面の座標(x,y)にknightがいる状態から次の動作を試行する
void printBoard(void);									//盤面の全表示


int main()
{
	long long int x, y;

	initBoard();

	counter = 1;
	x = 2;
	y = 2;
	board[y][x] = counter;
	knighttour(x, y);

	return 0;
}


void initBoard(void)
{
	long long int i, j;

	for (i = 0; i < N + 4; i++)	for (j = 0; j < N + 4; j++)	board[i][j] = -1;
	for (i = 2; i < N + 2; i++)	for (j = 2; j < N + 2; j++)	board[i][j] = 0;
}

void knighttour(long long int x, long long int y)
{
	long long int i;
	long long int nextx, nexty;							//次の座標(nextx,nexty)

	for (i = 0; i < 8; i++)
	{
		nextx = x + move[i].x;
		nexty = y + move[i].y;
		if (board[nexty][nextx] == 0)					//座標(nextx,nexty)は空だったので
		{
			board[nexty][nextx] = ++counter;
			if (counter == pow(N, 2))	printBoard();	//無限呼び出しにならない保障で最後まで埋まったので
			else	knighttour(nextx, nexty);
			board[nexty][nextx] = 0;
			--counter;
		}
	}
}

void printBoard(void)
{
	long long int i, j;
	static long long int found = 0;						//見つけた巡回方法の個数

	printf("Tour #%I64d is found.\n", ++found);
	for (i = 2; i < N + 2; i++)
	{
		for (j = 2; j < N + 2; j++)	printf("%4I64d", board[i][j]);
		putchar('\n');
	}
	if (found == 3)	exit(1);							//３つ見つけたら終了
}


/**************** 実行結果 *****************


Tour #1 is found.
   1  38  59  36  43  48  57  52
  60  35   2  49  58  51  44  47
  39  32  37  42   3  46  53  56
  34  61  40  27  50  55   4  45
  31  10  33  62  41  26  23  54
  18  63  28  11  24  21  14   5
   9  30  19  16   7  12  25  22
  64  17   8  29  20  15   6  13
Tour #2 is found.
   1  46  51  60  41  36  53  58
  50  61   2  35  52  59  40  37
  45  32  47  42   3  38  57  54
  62  49  44  27  34  55   4  39
  31  10  33  48  43  26  23  56
  18  63  28  11  24  21  14   5
   9  30  19  16   7  12  25  22
  64  17   8  29  20  15   6  13
Tour #3 is found.
   1  46  59  50  41  36  57  52
  60  49   2  35  58  51  40  37
  45  32  47  42   3  38  53  56
  48  61  44  27  34  55   4  39
  31  10  33  62  43  26  23  54
  18  63  28  11  24  21  14   5
   9  30  19  16   7  12  25  22
  64  17   8  29  20  15   6  13



*******************************************/
