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
	FILE *fp;					// ���̓t�@�C��
	ATOPS tab[128];				// a/A�J�n��Ɗe�o����
	ATOPS tmp;					// �\�[�g�ޔ���
	int m = 0;					// �����ސ�
	int n = 0;					// ���ꐔ
	int i, j, k;
	char cs[2048];				// �s���͈�
	char *p;					// ����|�C���^
	char *dlmt = ";:[-],.&' \n";// ��ԕ���	";:[-],.&' \n"

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

		// ����������
		for (i = 0; i < m - 1; i++)	for (j = i + 1; j < m; j++)	if (strcmp(tab[i].name, tab[j].name) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
		}

		// �\��
		printf("���o����(in total %dwords)\n", n);
		for (k = 0; k < m; k++)	printf("%2d: %-12s [%d]\n", k + 1, tab[k].name, tab[k].frq);
	}

	// �I��
	printf("\n# normal end #\n");


	return 0;
}
