#include <stdio.h>	/* dev-c++コンパイラでは，上記の"<"や">"と"stdio.h"との間にスペースを入れると*/
#include <stdlib.h>	/*コンパイル時に不具合が発生することがあるので，スペースは入れないように */

#define BF 1
#define KMP 1
#define TAR 1
#define PYOKO 1
#define TEXT_LENGTH 64
#define PATN_LENGTH 16


void init_next(char pattern[]);							/* ずらし表を作成する */
int brute_force_search(char text[], char pattern[]);	/* 文字列textから文字列patternを検索する(力まかせ法) */
int kmp_search(char text[], char pattern[]);			/* 文字列textから文字列patternを検索する(KMP法) */
int next[PATN_LENGTH];

int main(int argc, char *argv[], char *envp[])
{
	char text_tar[TEXT_LENGTH+1];
	char pattern_tar[PATN_LENGTH+1];
	char text_pyoko[TEXT_LENGTH+1];
	char pattern_pyoko[PATN_LENGTH+1];
	int position;

	strcpy(text_tar,"xxxtartartayx");
	strcpy(pattern_tar,"tartay");
	strcpy(text_pyoko,"pyokopyokomipyokopyokomepyokopyokopyokopyokomupyokopyoko");
	strcpy(pattern_pyoko,"pyokopyokomu");

#if TAR
	#if BF
		printf("--- B F ---\n");
		printf("%s\n",text_tar);
		position = brute_force_search(text_tar, pattern_tar);
		printf("position=%d\n",position);
	#endif

	#if KMP
		printf("--- KMP ---\n");
		init_next(pattern);
		printf("%s\n",text_tar);
		position = kmp_search(text_tar, pattern_tar);
		printf("position=%d\n",position);
	#endif
#endif

#if PYOKO
	#if BF
		printf("--- B F ---\n");
		printf("%s\n",text_pyoko);
		position = brute_force_search(text_pyoko, pattern_pyoko);
		printf("position=%d\n",position);
	#endif

	#if KMP
		printf("--- KMP ---\n");
		init_next(pattern);
		printf("%s\n",text_pyoko);
		position = kmp_search(text_pyoko, pattern_pyoko);
		printf("position=%d\n",position);
	#endif
#endif

	return 0;
}

int brute_force_search(char text[], char pattern[])
{
	int i = 0;	/* 注目しているテキストの位置 */
	int j = 0;	/* 注目しているパターンの位置 */
	int text_len, patn_len;

	text_len = strlen(text);	/* テキストの長さをセット */
	patn_len = strlen(pattern);	/* パターンの長さをセット */

	while ((i < text_len) && (j < patn_len))
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			i += 1 - j;
			j = 0;
		}
	}

	if (j == patn_len)	return i - j;
	else	return -1;
}

void init_next(char pattern[])
{
	int i, k, m;

	for (i = 0; i < patn_len; i++)
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
	}
}

int kmp_search(char text[], char pattern[])
{
	int i = 0; /* 注目しているテキストの位置 */
	int j = 0; /* 注目しているパターンの位置 */
	int text_len, patn_len;

	text_len = strlen(text);    /* テキストの長さをセット */
	patn_len = strlen(pattern); /* パターンの長さをセット */

	while ((i < text_len) && (j < patn_len))
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			j -= next[j];
			if (j < 0)
			{
				i++;
				j++;
			}
		}
	}

	if (j == patn_len)	return i - j;
	else	return -1;
}
