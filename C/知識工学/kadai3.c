// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

//#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>


void printImg(unsigned char data[0x200]);
void expandImg(unsigned char data[0x200], unsigned char ptrn[0x40][0x40]);
void compressImg(unsigned char data[0x200], unsigned char ptrn[0x40][0x40]);
void outline(unsigned char ptrn[0x40][0x40]);
void smooth(unsigned char ptrn[0x40][0x40]);
void normalize(unsigned char ptrn[0x40][0x40]);
void label(unsigned char ptrn[0x40][0x40]);
int labeling(unsigned char ptrn[0x40][0x40], int r, int c, int cursor);
void noise(unsigned char ptrn[0x40][0x40], int size);
void thinning(unsigned char ptrn[0x40][0x40]);
int cconc(unsigned int inb[9]);
void correction(unsigned char ptrn[0x40][0x40]);

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

		for (size_t y = 0; y < 0x40; y++)
		{
			for (size_t x = 0; x < 0x40; x++)
			{
				printf("%d ", pattern[y][x]);
			}
			putchar('\n');
		}
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
			if (data[r * 0x8 + c] & msk)	ptrn[r][c * 0x8 + i] = 1;
			else	ptrn[r][c * 0x8 + i] = 0;
			msk >>= 1;
		}
	}
}

void compressImg(unsigned char data[0x200], unsigned char ptrn[0x40][0x40])
{
	for (size_t i = 0; i < 0x200; i++)	for (size_t l = 0x7; l >= 0; l--)
	{
		if (ptrn[i / 0x8][(i % 0x8 + 1) * 0x8 - (l + 1)])	data[i] |= (1 << l);
	}
}

void outline(unsigned char ptrn[0x40][0x40])
{
	for (size_t y = 0; y < 0x40; y++)	for (size_t x = 0; x < 0x40; x++)	if ((ptrn[y][x] == 1) && (((ptrn[y + 1][x] == 1) || (ptrn[y + 1][x] == 2)) && ((ptrn[y - 1][x] == 1) || (ptrn[y - 1][x] == 2)) && ((ptrn[y][x + 1] == 1) || (ptrn[y][x + 1] == 2)) && ((ptrn[y][x - 1] == 1) || (ptrn[y][x - 1] == 2))))	ptrn[y][x] = 2;
	for (size_t y = 0; y < 0x40; y++)	for (size_t x = 0; x < 0x40; x++)	if (ptrn[y][x] == 2)	ptrn[y][x] = 0;
}

void smooth(unsigned char ptrn[0x40][0x40])
{
	int x = 1, y = 1;
	unsigned char m = ptrn[y][x], u = ptrn[y - 1][x], d = ptrn[y + 1][x], l = ptrn[y][x - 1], r = ptrn[y][x + 1],
		dr = ptrn[y + 1][x + 1], ur = ptrn[y - 1][x + 1], dl = ptrn[y + 1][x - 1], ul = ptrn[y - 1][x - 1];	//Structures(kouzoutai) are likely to be used.

	for (y = 1; y < 0x40 - 0x1; y++)	for (x = 1; x < 0x40 - 0x1; x++)
	{
		if ((m == 1) && ((u == 1) && (d == 1) && (l == 1) && (r == 1)))
		{
			if ((dr == 1) && (ur == 0) && (dl == 1) && (ul == 0))	u = 0;
			else if ((dr == 0) && (ur == 1) && (dl == 0) && (ul == 1))	d = 0;
			else if ((dr == 1) && (ur == 1) && (dl == 0) && (ul == 0))	l = 0;
			else if ((dr == 0) && (ur == 0) && (dl == 1) && (ul == 1))	r = 0;
		}
		if ((m == 1) && ((dr == 1) && (ur == 1) && (dl == 1) && (ul == 1)))
		{
			if ((u == 0) && (d == 1) && (l == 1) && (r == 1))	dr = 1;
			else if ((u == 1) && (d == 0) && (l == 1) && (r == 1))	ur = 1;
			else if ((u == 1) && (d == 1) && (l == 0) && (r == 1))	dl = 1;
			else if ((u == 1) && (d == 1) && (l == 1) && (r == 0))	ul = 1;
		}
	}
}

void normalize(unsigned char ptrn[0x40][0x40])	//dota oane es(left to right)
{
	int x0 = 0x40, y0 = 0x40, x1 = 0x0, y1 = 0x0, w, h;
	double dw = 0x40, dh = 0x40;
	char ptrn_temp[0x40][0x40];

	for (size_t r = 0; r < 0x40; r++)	for (size_t c = 0; c < 0x40; c++)
	{
		if (ptrn[r][c] == 1)
		{
			x0 = (x0 < c) ? x0 : c;
			y0 = (y0 < c) ? y0 : r;
			x1 = (x1 > c) ? x1 : c;
			y1 = (y1 > c) ? y1 : r;
		}
	}
	x1 += 1;
	y1 += 1;
	w = x1 - x0;
	h = y1 - y0;

	for (size_t r = 0; r < 0x40; r++)	for (size_t c = 0; c < 0x40; c++)
	{
		ptrn_temp[r][c] = ptrn[(int)(r * (h / dh) + y0 + 0.5)][(int)(c * (w / dw) + x0 + 0.5)];
	}

	for (size_t r = 0; r < 0x40; r++)	for (size_t c = 0; c < 0x40; c++)	ptrn[r][c] = ptrn_temp[r][c];
}

void label(unsigned char ptrn[0x40][0x40])
{
	int lblnum = 2;

	for (size_t c = 0; c < 0x40; c++)	for (size_t r = 0; r < 0x40; r++)	if (ptrn[c][r] == 1)
	{
		labeling(ptrn, r, c, lblnum);
		lblnum++;
	}
}

int labeling(unsigned char ptrn[0x40][0x40], int r, int c, int cursor)
{
	static int cnt;
	cnt++;
	ptrn[c][r] = cursor;

	if ((r == 64) || (c == 64) || (r == -1) || (c == -1))	return cursor;

	if (ptrn[c][r + 1] == 1)	labeling(ptrn, r + 1, c, cursor);
	if (ptrn[c + 1][r] == 1)	labeling(ptrn, r, c + 1, cursor);
	if (ptrn[c][r - 1] == 1)	labeling(ptrn, r - 1, c, cursor);
	if (ptrn[c - 1][r] == 1)	labeling(ptrn, r, c - 1, cursor);

	if (ptrn[c + 1][r + 1] == 1)	labeling(ptrn, r + 1, c + 1, cursor);
	if (ptrn[c + 1][r - 1] == 1)	labeling(ptrn, r + 1, c + 1, cursor);
	if (ptrn[c - 1][r + 1] == 1)	labeling(ptrn, r + 1, c - 1, cursor);
	if (ptrn[c - 1][r - 1] == 1)	labeling(ptrn, r - 1, c - 1, cursor);

	return cursor;
}

void noise(unsigned char ptrn[0x40][0x40], int size)
{
	int lbl = 0, num[0x80] = {};

	for (size_t c = 0; c < 0x40; c++)	for (size_t r = 0; r < 0x40; r++)
	{
		lbl = (lbl > ptrn[c][r]) ? lbl : ptrn[c][r];
		num[ptrn[c][r]]++;
	}

	for (size_t c = 0; c < 0x40; c++)	for (size_t r = 0; r < 0x40; r++)
	{
		if (num[ptrn[c][r]] >= size)	ptrn[c][r] = ptrn[c][r];
		else	ptrn[c][r] = 0;
	}
}

void thinning(unsigned char ptrn[0x40][0x40])
{
	//int x = 1, y = 1;
	//unsigned char m = ptrn[y][x], u = ptrn[y - 1][x], d = ptrn[y + 1][x], l = ptrn[y][x - 1], r = ptrn[y][x + 1],
	//	dr = ptrn[y + 1][x + 1], ur = ptrn[y - 1][x + 1], dl = ptrn[y + 1][x - 1], ul = ptrn[y - 1][x - 1];	//Structures(kouzoutai) are likely to be used.

	//for (y = 1; y < 0x40 - 0x1; y++)	for (x = 1; x < 0x40 - 0x1; x++)
	//{
	//	if ((m == 1) && ((u == 1) && (d == 1) && (l == 1) && (r == 1)))
	//	{
	//		if ((dr == 1) && (ur == 0) && (dl == 1) && (ul == 0))	u = 0;
	//		else if ((dr == 0) && (ur == 1) && (dl == 0) && (ul == 1))	d = 0;
	//		else if ((dr == 1) && (ur == 1) && (dl == 0) && (ul == 0))	l = 0;
	//		else if ((dr == 0) && (ur == 0) && (dl == 1) && (ul == 1))	r = 0;
	//	}
	//	if ((m == 1) && ((dr == 1) && (ur == 1) && (dl == 1) && (ul == 1)))
	//	{
	//		if ((u == 0) && (d == 1) && (l == 1) && (r == 1))	dr = 1;
	//		else if ((u == 1) && (d == 0) && (l == 1) && (r == 1))	ur = 1;
	//		else if ((u == 1) && (d == 1) && (l == 0) && (r == 1))	dl = 1;
	//		else if ((u == 1) && (d == 1) && (l == 1) && (r == 0))	ul = 1;
	//	}
	//}

	//confer https://pokosho.com/t/image/

	unsigned int ia[9], ic[9], i, ix, iy, m, ir, iv, iw;
	unsigned char ptrn_temp[0x40][0x40];

	for (iy = 0; iy < 0x40; iy++)	for (ix = 0; ix < 0x40; ix++)	ptrn_temp[iy][ix] = ptrn[iy][ix];
	m = 100; ir = 1;
	while (ir != 0)
	{
		ir = 0;
		for (iy = 1; iy < (0x40 - 1); iy++)	for (ix = 1; ix < (0x40 - 1); ix++)
		{
			if (ptrn_temp[iy][ix] != 0xFF)	continue;
			ia[0] = ptrn_temp[iy][ix + 1];
			ia[1] = ptrn_temp[iy - 1][ix + 1];
			ia[2] = ptrn_temp[iy - 1][ix];
			ia[3] = ptrn_temp[iy - 1][ix - 1];
			ia[4] = ptrn_temp[iy][ix - 1];
			ia[5] = ptrn_temp[iy + 1][ix - 1];
			ia[6] = ptrn_temp[iy + 1][ix];
			ia[7] = ptrn_temp[iy + 1][ix + 1];
			for (i = 0; i < 8; i++)
			{
				if (ia[i] == m)
				{
					ia[i] = 0xFF;
					ic[i] = 0;
				}
				else
				{
					if (ia[i] < 0xFF)	ia[i] = 0;
					ic[i] = ia[i];
				}
			}
			ia[8] = ia[0];
			ic[8] = ic[0];
			if ((ia[0] + ia[2] + ia[4] + ia[6]) == (0xFF * 4))	continue;
			for (i = 0, iv = 0, iw = 0; i < 8; i++)
			{
				if (ia[i] == 0xFF)	iv++;
				if (ic[i] == 0xFF)	iw++;
			}
			if (iv <= 1)	continue;
			if (iw == 0)	continue;
			if (cconc(ia) != 1)	continue;
			if (ptrn_temp[iy - 1][ix] == m)
			{
				ia[2] = 0;
				if (cconc(ia) != 1)	continue;
				ia[2] = 0xFF;
			}
			if (ptrn_temp[iy][ix - 1] == m) {
				ia[4] = 0;
				if (cconc(ia) != 1) continue;
				ia[4] = 0xFF;
			}
			ptrn_temp[iy][ix] = m; ir++;
		}
		m++;
	}
	for (iy = 0; iy < 0x40; iy++)
		for (ix = 0; ix < 0x40; ix++)
			if (ptrn_temp[iy][ix] < 0xFF) ptrn_temp[iy][ix] = 0;
}

int	cconc(unsigned int inb[9])
{
	int i, icn;
	icn = 0;

	for (i = 0; i < 8; i += 2)	if (inb[i] == 0)	if (inb[i + 1] == 0xFF || inb[i + 2] == 0xFF)	icn++;

	return icn;
}

void correction(unsigned char ptrn[0x40][0x40])
{
}
