#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct wrd
{
	char name[32];
	int frq;
} ATOPS;

int main()
{
	FILE *fp;					// 入力ファイル
	ATOPS tab[128];				// a/A開始語と各出現数
	ATOPS tmp;					// ソート退避域
	int m = 0;					// 同上種類数
	int n = 0;					// 総語数
	int i, j, k;
	char cs[2048];				// 行入力域
	char *p;					// 同上ポインタ
	char *dlmt = ";:[-],.&' \n";// 語間文字	";:[-],.&' \n"

	fp = fopen("output.txt", "r");
	while (fgets(cs, 2048, fp) != NULL)
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
		printf("検出結果(in total %dwords)\n", n);
		for (k = 0; k < m; k++)	printf("%2d: %-12s [%d]\n", k + 1, tab[k].name, tab[k].frq);
	}

	// 終了
	printf("\n# normal end #\n");


	return 0;
}
