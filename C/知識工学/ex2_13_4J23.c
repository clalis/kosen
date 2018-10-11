// 4J23	椎名 泰之	Sample:SHRT_MAX(32767)
// 
// 根魚:大きな値を設定することによって、値が安定することが観測された。
// そのため、値をINT_MAXに設定したが、処理が重くなってしまったためちょうどマクロ設定のあるSHRT_MAXを用いた。
// 実際に、小数点第3位まで+-1程度、凡そ安定させることに成功した。
// 
// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL
#define UPPER_MASK 0x80000000UL
#define LOWER_MASK 0x7fffffffUL


static unsigned long mt[N];
static int mti = N + 1;

void init_genrand(unsigned long s);
void init_by_array(unsigned long init_key[], int key_length);
unsigned long genrand_int32(void);
long genrand_int31(void);
double genrand_real1(void);
double genrand_real2(void);
double genrand_real3(void);
double genrand_res53(void);


int main(int argc, char const *argv[])
{
	double gate;
	int a, b, c, d;
	int ans1 = 0, ans2 = 0, ans3 = 0;
	int count1 = 0, count2 = 0, count3 = 0, loop = 0;

	init_genrand((unsigned)time(NULL));

	while ((count1 < SHRT_MAX) || (count2 < SHRT_MAX) || (count3 < SHRT_MAX))
	{
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		loop++;
		gate = 0.2;
		a = genrand_real2() < gate ? 0 : 1;
		gate = 0.85;
		b = genrand_real2() < gate ? 0 : 1;
		if (a)	gate = b ? 0.95 : 0.30;
		else	gate = b ? 0.75 : 0.10;
		c = genrand_real2() < gate ? 0 : 1;
		gate = c ? 0.80 : 0.95;
		d = genrand_real2() < gate ? 0 : 1;
		if (b)
		{
			count1++;
			if (d)	ans1++;
		}
		if (!a && d)
		{
			count2++;
			if (!c)	ans2++;
		}
		if (a)
		{
			count3++;
			if (!d)	ans3++;
		}
	}
	printf("(1) :%8d /%8d =%10f\n", ans1, count1, (double)ans1 / count1);
	printf("(2) :%8d /%8d =%10f\n", ans2, count2, (double)ans2 / count2);
	printf("(3) :%8d /%8d =%10f\n", ans3, count3, (double)ans3 / count3);

	system("pause");

	return 0;
}

void init_genrand(unsigned long s)
{
	mt[0] = s & 0xffffffffUL;
	for (mti = 1; mti < N; mti++)
	{
		mt[mti] = (1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + mti);

		mt[mti] &= 0xffffffffUL;
	}
}

void init_by_array(unsigned long init_key[], int key_length)
{
	int i, j, k;
	init_genrand(19650218UL);
	i = 1;
	j = 0;
	k = (N > key_length ? N : key_length);
	for (; k; k--)
	{
		mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >> 30)) * 1664525UL)) + init_key[j] + j;
		mt[i] &= 0xffffffffUL;
		i++;
		j++;
		if (i >= N)
		{
			mt[0] = mt[N - 1];
			i = 1;
		}
		if (j >= key_length)	j = 0;
	}
	for (k = N - 1; k; k--)
	{
		mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >> 30)) * 1566083941UL)) - i;
		mt[i] &= 0xffffffffUL;
		i++;
		if (i >= N)
		{
			mt[0] = mt[N - 1];
			i = 1;
		}
	}

	mt[0] = 0x80000000UL;
}

unsigned long genrand_int32(void)
{
	unsigned long y;
	static unsigned long mag01[2] = { 0x0UL, MATRIX_A };

	if (mti >= N)
	{
		int kk;

		if (mti == N + 1)	init_genrand(5489UL);

		for (kk = 0; kk < N - M; kk++)
		{
			y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
			mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1UL];
		}
		for (; kk < N - 1; kk++)
		{
			y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
			mt[kk] = mt[kk + (M - N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
		}
		y = (mt[N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
		mt[N - 1] = mt[M - 1] ^ (y >> 1) ^ mag01[y & 0x1UL];

		mti = 0;
	}

	y = mt[mti++];

	y ^= (y >> 11);
	y ^= (y << 7) & 0x9d2c5680UL;
	y ^= (y << 15) & 0xefc60000UL;
	y ^= (y >> 18);

	return y;
}

long genrand_int31(void)
{
	return (long)(genrand_int32() >> 1);
}

double genrand_real1(void)
{
	return genrand_int32() * (1.0 / 4294967295.0);
}

double genrand_real2(void)
{
	return genrand_int32() * (1.0 / 4294967296.0);
}

double genrand_real3(void)
{
	return (((double)genrand_int32()) + 0.5) * (1.0 / 4294967296.0);
}

double genrand_res53(void)
{
	unsigned long a = genrand_int32() >> 5, b = genrand_int32() >> 6;
	return (a * 67108864.0 + b) * (1.0 / 9007199254740992.0);
}
