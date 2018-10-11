// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

#define M 100
#define N 10000


int log[M], guess[M][10], nums[N], index;

void string_finder(char a[])
{
	size_t n;

	if (fgets(a, 5, stdin) == NULL)
		/* エラー処理 */;
	n = strlen(a);
	if (a[n - 1] == '\n')
	{
		a[n - 1] = '\0';
	}
	else
	{
		int c;
		do
		{
			c = getchar();
			if (c == EOF)
			{
				if (feof(stdin))
					break;
				else
					/* エラー処理 */;
			}
		} while (c != '\n');
	}
}

int set_answer()
{
	int tab[10], n, i, a;

	for (i = 0; i < 10; i++)	tab[i] = 0;
	n = 0;
	for (i = 1; i <= 4; i++)
	{
		do
		{
			a = rand() % 10;
		} while (tab[a] != 0);
		tab[a] = 1;
		n = 10 * n + a;
	}

	return n;
}

void make_pos(int y, int *pos)
{
	int i, m;

	for (i = 0; i < 10; i++)	pos[i] = 0;
	for (i = 1; i <= 4; i++)
	{
		m = y % 10;
		y /= 10;
		pos[m] = i;
	}
}

/*int similarity(int x,int y){return hit*10+miss;}*/

int sim(int x, int *pos)
{
	int hit, miss, i, p;
	hit = 0;
	miss = 0;

	for (i = 1; i <= 4; i++)
	{
		p = x % 10;
		x /= 10;

		if (pos[p] != 0)
		{
			if (pos[p] == i)	hit++;
			else miss++;
		}
	}

	return hit * 10 + miss;
}

int make_guess(int k)
{
	int j;
	index++;

	while (1)
	{
		j = 0;
		while (j < k - 1 && sim(nums[index], guess[j]) == log[j])	j++;
		if (j < k - 1)
		{
			index++;
			if (index >= N)	exit(1);
		}
		else return nums[index];
	}
}

void play() {
	int ans, pos_a[10], i, r, g, hit, miss, guess_person;
	int mode;
	char a[5];

	ans = set_answer();
	make_pos(ans, pos_a);
	index = -1;
	i = 1;

	printf("[1]一人用、[2]対戦用-->");
	string_finder(a);
	mode = atoi(a);

	if (mode != 1)
	{
		printf("あなたの数字を決めて下さい。\n");
		puts("saiは既に数字を決めました。\n");
	}
	while (1)
	{
		printf("sai「私の数を当てて下さい（４桁）」-->");
		string_finder(a);
		guess_person = atoi(a);
		r = sim(guess_person, pos_a);
		printf("HIT:%d BLOW:%d\n", r / 10, r % 10);
		if (mode != 1)
		{
			g = make_guess(i);
			printf("saiが推測した数-->%04d\n", g);
			printf("HITはいくつ？-->");
			string_finder(a);
			hit = atoi(a);
			printf("MISSはいくつ？-->");
			string_finder(a);
			miss = atoi(a);
			if (miss == -1)	exit(1);
		}
		if (hit == 4 || r == 40)	break;
		if (mode != 1)
		{
			log[i - 1] = 10 * hit + miss;
			make_pos(g, guess[i - 1]);
			i++;
		}
	}
	if (r == 40 && hit != 4)	puts("You Win!");
	else if (r != 40 && hit == 4)	puts("Com Win!");
	else puts("Draw...");
}

int main()
{
	char r, a[5];
	int i;

	for (i = 0; i < N; i++)	nums[i] = i;
	while (1)
	{
		play();
		printf("ゲームを続けますか？y/n -->");
		string_finder(a);
		r = a[0];
		if (r == 'n')	break;
	}
	return 0;
}
