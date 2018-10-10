#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <tchar.h>

int checkString(char s[]);
int countHit(char s1[], char s2[]);
int countBlow(char s1[], char s2[]);
void generateNumber(char theNumber[]);
void scnIntro(void);

int main()
{
	int cnt, chk, hit, blow;
	char num[100], rnum[10];
	cnt = 0;
	chk = 0;
	srand((unsigned)time(NULL));

	scnIntro();
	
	generateNumber(rnum);

	do
	{
		do
		{
			printf("４つの数字を入力してください = ");
			gets(num);
			chk = checkString(num);
		} while (chk == 1);
		hit = countHit(rnum, num);
		blow = countBlow(rnum, num);
		printf("完全一致数 = %d,不完全一致数 = %d\n\n", hit, blow);
		cnt = cnt++;
	} while (hit != 4);
	printf("一致しました。ゲームクリアです。\n");
	printf("試行回数 = %d\n", cnt);

	return 0;
}

int checkString(char s[])
{
	int ans, i, j;
	ans = 0;
	i = 0;

	while (s[i] != '\0') i++;

	if (i != 4) ans = 1;
	for (i = 0; i < 4; i++)
	{
		if (s[i] < '0' || '9' < s[i]) ans = 1;
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 1 + i; j < 4; j++)
		{
			if (s[i] == s[j]) ans = 1;
		}
	}

	return ans;
}

int countHit(char s1[], char s2[])
{
	short chk;
	chk = 0;

	for (size_t i = 0; i < 4; i++)
	{
		if (s1[i] == s2[i]) chk++;
	}

	return chk;
}

int countBlow(char s1[], char s2[])
{
	int fair;
	fair = 0;

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (i != j && s1[i] == s2[j]) fair++;
		}
	}
	return fair;

	return 0;
}

void generateNumber(char theNumber[])
{
	int chk, n, i;

	do
	{
		for (i = 0; i < 4; i++)
		{
			n = rand() % 10;
			theNumber[i] = n + '0';
		}

		theNumber[i] = '\0';
		chk = checkString(theNumber);

	} while (chk == 1);

	return;
}

void scnIntro(void)
{
	printf("hit 'n' blow\n");

	return;
}
