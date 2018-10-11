#include <stdio.h>	/* dev-c++コンパイラでは，上記の"<"や">"と"stdio.h"との間にスペースを入れると*/
#include <stdlib.h>	/*コンパイル時に不具合が発生することがあるので，スペースは入れないように */
#include <string.h>

#define BF 1
#define KMP 1
#define BM 1
#define TAR 0
#define PYOKO 1
#define ABC 1
#define TEXT_LENGTH 0x40
#define PATN_LENGTH 0x100
#define MAX(a, b) ((a) > (b) ? (a) : (b))



void init_next(char pattern[]);									/* ずらし表を作成する */
void init_skip(unsigned char pattern[]);						/* BM法用のずらし表を作成する */
int brute_force_search(char text[], char pattern[]);			/* 文字列textから文字列patternを検索する(力まかせ法) */
int kmp_search(char text[], char pattern[]);					/* 文字列textから文字列patternを検索する(KMP法) */
int bm_search(unsigned char text[], unsigned char pattern[]);	/* 文字列textから文字列patternを検索する(BM法) */


int next[PATN_LENGTH];
int skip[PATN_LENGTH];

int main(int argc, char *argv[], char *envp[])
{
	char text_tar[TEXT_LENGTH + 1];
	char pattern_tar[PATN_LENGTH + 1];
	char text_pyoko[TEXT_LENGTH + 1];
	char pattern_pyoko[PATN_LENGTH + 1];
	unsigned char text_abc[TEXT_LENGTH + 1];
	unsigned char pattern_abc[PATN_LENGTH + 1];

	int position;

	strcpy(text_tar, "xxxtartartayx");
	strcpy(pattern_tar, "tartay");
	strcpy(text_pyoko, "pyokopyokomipyokopyokomepyokopyokopyokopyokomupyokopyoko");
	strcpy(pattern_pyoko, "pyokopyokomu");
	strcpy((char *)text_abc, "aabbabcabc");
	strcpy((char *)pattern_abc, "abcab");

#if TAR
#if BF
	printf("--- B F ---\n");
	printf("%s\n", text_tar);
	position = brute_force_search(text_tar, pattern_tar);
	printf("position=%d\n\n", position);
#endif

#if KMP
	printf("--- KMP ---\n");
	init_next(pattern_tar);
	printf("%s\n", text_tar);
	position = kmp_search(text_tar, pattern_tar);
	printf("position=%d\n\n", position);
#endif

#if BM
	printf("--- B M ---\n");
	init_skip((unsigned char *)pattern_tar);
	printf("%s\n", text_tar);
	position = bm_search((unsigned char *)text_tar, (unsigned char *)pattern_tar);
	printf("position=%d\n\n", position);
#endif
#endif

#if PYOKO
#if BF
	printf("--- B F ---\n");
	printf("%s\n", text_pyoko);
	position = brute_force_search(text_pyoko, pattern_pyoko);
	printf("position=%d\n\n", position);
#endif

#if KMP
	printf("--- KMP ---\n");
	init_next(pattern_pyoko);
	printf("%s\n", text_pyoko);
	position = kmp_search(text_pyoko, pattern_pyoko);
	printf("position=%d\n\n", position);
#endif

#if BM
	printf("--- B M ---\n");
	init_skip((unsigned char *)pattern_pyoko);
	printf("%s\n", text_pyoko);
	position = bm_search((unsigned char *)text_pyoko, (unsigned char *)pattern_pyoko);
	printf("position=%d\n\n", position);
#endif
#endif

#if ABC
#if BF
	printf("--- B F ---\n");
	printf("%s\n", text_abc);
	position = brute_force_search((char *)text_abc, (char *)pattern_abc);
	printf("position=%d\n\n", position);
#endif

#if KMP
	printf("--- KMP ---\n");
	init_next((char *)pattern_abc);
	printf("%s\n", text_abc);
	position = kmp_search((char *)text_abc, (char *)pattern_abc);
	printf("position=%d\n\n", position);
#endif

#if BM
	printf("--- B M ---\n");
	init_skip(pattern_abc);
	printf("%s\n", text_abc);
	position = bm_search(text_abc, pattern_abc);
	printf("position=%d\n\n", position);
#endif
#endif

	return 0;
}

int brute_force_search(char text[], char pattern[])
{
	int i = 0;	/* 注目しているテキストの位置 */
	int j = 0;	/* 注目しているパターンの位置 */
	int text_len, patn_len, flag, in;
	flag = 1;

	text_len = strlen(text);	/* テキストの長さをセット */
	patn_len = strlen(pattern);	/* パターンの長さをセット */

	while ((i < text_len) && (j < patn_len))
	{
		if (flag)	for (in = 0; in < i; in++)	putchar(' ');
		putchar(pattern[j]);
		if (text[i] == pattern[j])
		{
			i++;
			j++;
			flag = 0;
		}
		else
		{
			i += 1 - j;
			j = 0;
			printf("\t\t...failed.\n");
			flag = 1;
		}
	}

	if (j == patn_len)
	{
		printf("\tsucceeded.\n");
		return i - j;
	}
	else	return -1;
}

void init_next(char pattern[])
{
	int i, k, m;

	for (i = 0; i < strlen(pattern); i++)
	{
		if (i < 1)	next[i] = 1;
		else
		{
			for (k = 1; k < i; k++)
			{
				for (m = k; (m < i) && (pattern[m] == pattern[m - k]); m++);
				if (m == i)	break;
			}
			next[i] = k;
		}
		printf("next[%2d] = %2d\n", i, next[i]);
	}
}

int kmp_search(char text[], char pattern[])
{
	int i = 0; /* 注目しているテキストの位置 */
	int j = 0; /* 注目しているパターンの位置 */
	int text_len, patn_len, flag, in;
	flag = 1;

	text_len = strlen(text);    /* テキストの長さをセット */
	patn_len = strlen(pattern); /* パターンの長さをセット */

	while ((i < text_len) && (j < patn_len))
	{
		if (flag)	for (in = 0; in < i; in++)	putchar(' ');
		putchar(pattern[j]);
		if (text[i] == pattern[j])
		{
			i++;
			j++;
			flag = 0;
		}
		else
		{
			j -= next[j];
			if (j < 0)
			{
				i++;
				j++;
			}
			printf("\t\t...failed.\n");
			flag = 1;
		}
	}

	if (j == patn_len)
	{
		printf("\t...succeeded.\n");
		return i - j;
	}
	else	return -1;
}

void init_skip(unsigned char pattern[])
{
	int i;

	for (i = 0; i < PATN_LENGTH; i++)	skip[i] = strlen((char *)pattern);
	for (i = 0; i < strlen((char *)pattern); i++)	skip[pattern[i]] = strlen((char *)pattern) - i - 1;
	for (i = 0; i < strlen((char *)pattern); i++)	printf("%c : skip[%3d] = %d\n", pattern[i], pattern[i], skip[pattern[i]]);
}

int bm_search(unsigned char text[], unsigned char pattern[])
{
	int i;	/* 注目しているテキストの位置 */
	int j;	/* 注目しているパターンの位置 */
	int text_len, patn_len, flag, in;
	flag = 1;

	text_len = strlen((char *)text);    /* テキストの長さをセット */
	patn_len = strlen((char *)pattern); /* パターンの長さをセット */

	i = patn_len - 1;	/* iにテキストの最初の注目位置をセット */

	while (i < text_len)
	{
		j = patn_len - 1;	/* jにパターンの最初の注目位置をセット */

		for (in = 0; in < i; in++)	putchar('>');

		while (text[i] == pattern[j])	/* テキストとパターンを１文字比較 */
		{
			if (j == 0)	/* すべての文字が一致したら */
			{
				printf("%c\t...succeeded.\n", pattern[j]);	/* パターンが見つかった位置を返す */
				return i;
			}

			printf("%c\n", pattern[j]);

			i--;	/* テキストの位置を１文字戻す */
			j--;	/* パターンの位置を１文字戻す */

			for (in = 0; in < i; in++)	putchar(' ');
		}

		i += MAX(patn_len - j, skip[text[i]]);	/* テキストの注目点(i)を，不一致になった文字に応じた分量だけずらす */
		printf("%c\t\t...failed.\n", pattern[j]);
	}

	return -1;
}
