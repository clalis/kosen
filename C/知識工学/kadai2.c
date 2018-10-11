// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


void printImg(unsigned char data[0x200]);
void expandImg(unsigned char data[0x200], unsigned char ptrn[0x40][0x40]);
void compressImg(unsigned char data[0x200], unsigned char ptrn[0x40][0x40]);

int main()
{
	FILE *fp;
	unsigned char data[0x200], msk = 0x80, pattern[0x40][0x40];
	char *fname = "C:/Users/TeamET/Downloads/all/01.img";

	if ((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "\"%s\" can't open.\n", fname);
		exit(EXIT_FAILURE);
	}

	for (size_t cnt = 0; cnt < 20; cnt++)
	{
		system("PAUSE");
		fread(data, 0x200, 1, fp);

		printImg(data);

		expandImg(data, pattern);
		for (size_t r = 0; r < 0x40; r++)
		{
			for (size_t c = 0; c < 0x8; c++)	printf("%d\t\t", pattern[r][c]);
			putchar('\n');
		}
		compressImg(data, pattern);

		printImg(data);
	}

	fclose(fp);

	return 0;
}

void printImg(unsigned char data[0x200])
{
	unsigned char msk = 0x80;

	for (size_t r = 0; r < 0x40; r++)
	{
		for (size_t c = 0; c < 0x8; c++)
		{
			msk = 0x80;
			for (size_t i = 0; i < 0x8; i++)
			{
				putchar(' ');
				if (data[r * 0x8 + c] & msk)	putchar('*');
				else	putchar('.');
				msk >>= 1;
			}
		}
		putchar('\n');
	}
	putchar('\n');
}

void expandImg(unsigned char data[0x200], unsigned char ptrn[0x40][0x40])
{
	unsigned char msk = 0x80;

	for (size_t r = 0; r < 0x40; r++)	for (size_t c = 0; c < 0x8; c++)
	{
		msk = 0x80;
		for (size_t i = 0; i < 0x8; i++)
		{
			if (data[r * 0x8 + c] & msk)	ptrn[r][c] = 1;
			else	ptrn[r][c] = 0;
			msk >>= 1;
		}
	}
}

void compressImg(unsigned char data[0x200], unsigned char ptrn[0x40][0x40])
{
	for (size_t i = 0; i < 0x40; i++)	for (size_t l = 0; l < 0x40; l++)
	{
		if (!ptrn[i][l])	data[i * l / 8] = 0;
		else if (ptrn[i][l] == 1)	data[i * l / 8] = 1;
	}
}
