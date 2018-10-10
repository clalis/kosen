// test.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


int myrand(void);
int delay2(int var);


int main()
{
	int i;
	int x, y;

	for(i = 0;i < 25;i++)
	{
		x = myrand();
		y = delay20(x);
		printf("%8d x=%6d y=%6d\n",i,x,y);
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

int delay20(int var)
{
	static int buff[32]={0};
	static int put=21;
	static int get=0;

	buff[put]=var;
	put++;
	if (put==22)	put=0;
	get++;
	if (get==22)	get=0;

	return buff[get];
}
