/***  p10ex03.c  ***/
/***  s15092  2J23  �Ŗ� �הV  ***/


#define N 9												//�}�X��

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


/******************************************************
�T�~�T�̔Ֆʂł̃`�F�X��knight�̈ړ��ŔՖʂ��ׂẴZ����
�ʉ߂���菇�������ĕ\�����܂��B
�T�~�T�̔z�������C�K�₵�Ă��Ȃ��Ƃ���ɂ͂O�𖄂�
�K�₵���Ƃ���ɂ́C�K�⏇�ԍ��������܂��B
�������Ֆʒ[�̃`�F�b�N���ȒP�ɂ��邽�߁C���͊O���ɂQ��
�����z�������C-1�𖄂߂Ă����܂��B

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
} move_t;											//����̈ړ��ʂ�\���^

move_t move[8] =
{
	{ 2, 1 },{ 1, 2 },{ -1, 2 },{ -2, 1 },{ -2, -1 },{ -1, -2 },{ 1, -2 },{ 2, -1 }
};														//���̈ړ��ʂ̑S���

long long int board[N + 4][N + 4];						//�Ֆʔz��
long long int counter;									//�萔�J�E���^

void initBoard(void);									//�Ֆʂ̏�����
void knighttour(long long int x, long long int y);		// �Ֆʂ̍��W(x,y)��knight�������Ԃ��玟�̓�������s����
void printBoard(void);									//�Ֆʂ̑S�\��


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
	long long int nextx, nexty;							//���̍��W(nextx,nexty)

	for (i = 0; i < 8; i++)
	{
		nextx = x + move[i].x;
		nexty = y + move[i].y;
		if (board[nexty][nextx] == 0)					//���W(nextx,nexty)�͋󂾂����̂�
		{
			board[nexty][nextx] = ++counter;
			if (counter == pow(N, 2))	printBoard();	//�����Ăяo���ɂȂ�Ȃ��ۏ�ōŌ�܂Ŗ��܂����̂�
			else	knighttour(nextx, nexty);
			board[nexty][nextx] = 0;
			--counter;
		}
	}
}

void printBoard(void)
{
	long long int i, j;
	static long long int found = 0;						//������������@�̌�

	printf("Tour #%I64d is found.\n", ++found);
	for (i = 2; i < N + 2; i++)
	{
		for (j = 2; j < N + 2; j++)	printf("%4I64d", board[i][j]);
		putchar('\n');
	}
	if (found == 3)	exit(1);							//�R��������I��
}


/**************** ���s���� *****************


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
