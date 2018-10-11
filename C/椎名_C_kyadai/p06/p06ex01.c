// test.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


int myrand(void);
int delay2(int var);


int main()
{
	int i;
	int x, y;
	for (i = 0; i<100000; i++)
	{
		x = myrand();
		y = delay2(x);
		if (i<10 || 99990<i)	printf("%8d x=%6d y=%6d\n", i, x, y);
	}

	return 0;
}


int myrand(void)
{
	static unsigned int rnd = 12345;

	rnd = 18397 * rnd + 35977;
	rnd %= 32768;

	return (int)rnd;
}

int delay2(int var)
{
	static int prev0 = 0;
	static int prev1 = 0;
	static int prev2 = 0;

	prev2 = prev1;
	prev1 = prev0;
	prev0 = var;

	return prev1;
}
