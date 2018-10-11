/***  p07ex06.c  ***/
/***  s15092  2J23  椎名 泰之  ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define B 256


typedef struct wrd
{
	char name[32];
	int frq;
} ATOPS;

void GetWordNum();

int main()
{
	FILE *fpi, *fpo;

	
	int cnt = 0, stat = 1;	//stat = 0:imgnary prog, 1:not word, other:now in progress
	char buff[B], str, laststr = 0;

	fgets(buff, B, stdin);
	sscanf(buff, "%s", &buff);


	if (((fpi = fopen((char*)buff, "r")) == NULL) || ((fpo = fopen("output.txt", "w+")) == NULL))
	{
		printf("Error has occured.\n");
		exit(EXIT_FAILURE);
	}

	while ((str = fgetc(fpi)) != EOF)
	{
		if (stat == 2)
		{
			if (isalnum(str) || (str == '_'))	fprintf(fpo, "%c", str);
			else
			{
				stat = 1;
				cnt++;
				if (cnt % 8 == 0)	fprintf(fpo, "\n");
				else	fprintf(fpo, " ");
			}
		}
		else if (stat == 0)
		{
			if (isalnum(str) || (str == '_'))	{}
			else	stat = 1;
		}
		else
		{
			if (isalpha(str))
			{
				if (isdigit(laststr))	stat = 0;
				else
				{
					stat = 2;
					fprintf(fpo, "%c", str);
				}
			}
		}

		laststr = str;
	}

	fclose(fpi);
	fclose(fpo);

	GetWordNum();


	return 0;
}

void GetWordNum(void)
{
	FILE *fpi, *fpo;				// 入出力ファイル
	ATOPS tab[1024];				// a/A開始語と各出現数
	ATOPS tmp;					// ソート退避域
	long long int m = 0;					// 同上種類数
	long long int n = 0;					// 総語数
	long long int i, j, k;
	char cs[2048];				// 行入力域
	char *p;					// 同上ポインタ
	char *dlmt = ";:[-],.&' \n";// 語間文字	";:[-],.&' \n"

	if (((fpi = fopen("output.txt", "r")) == NULL) || ((fpo = fopen("output_(sorted).txt", "w+")) == NULL))
	{
		printf("Error has occured.\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(cs, 2048, fpi) != NULL)
	{
		p = cs;
		while ((p = strtok(p, dlmt)) != NULL)
		{
			n++;
			if (isalnum(*p)/*(*p == 'a') || (*p == 'A')*/)
			{
				for (k = 0; k < m; k++)	if (strcmp(tab[k].name, p) == 0)	break;
				if (k < m)	tab[k].frq++;
				else
				{
					tab[m].frq = 1;
					strcpy(tab[m].name, p);
					m++;
				}
			}
			p = NULL;
		}

		// 辞書順整列
		for (i = 0; i < m - 1; i++)	for (j = i + 1; j < m; j++)	if (strcmp(tab[i].name, tab[j].name) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
		}

		// 表示
		fprintf(fpo, "検出結果(in total %lldwords)\n", n);
		for (k = 0; k < m; k++)	fprintf(fpo, "%2lld: %-12s [%d]\n", k + 1, tab[k].name, tab[k].frq);
	}

	// 終了
	printf("\n# normal end #\n");

	fclose(fpi);
	fclose(fpo);
}


/**************** 実行結果 *****************


検出結果(in total 8words)
 1: ctype        [1]
 2: h            [2]
 3: include      [3]
 4: stdio        [1]
 5: stdlib       [1]
検出結果(in total 16words)
 1: FILE         [1]
 2: argc         [1]
 3: argv         [1]
 4: char         [1]
 5: ctype        [1]
 6: h            [3]
 7: include      [3]
 8: int          [1]
 9: main         [1]
10: stdio        [1]
11: stdlib       [1]
12: void         [1]
検出結果(in total 24words)
 1: FILE         [1]
 2: argc         [2]
 3: argv         [1]
 4: ch           [1]
 5: char         [1]
 6: ctype        [1]
 7: f1           [1]
 8: f2           [1]
 9: h            [3]
10: if           [1]
11: include      [3]
12: int          [2]
13: main         [1]
14: printf       [1]
15: short        [1]
16: stdio        [1]
17: stdlib       [1]
18: void         [1]


*******************************************/
