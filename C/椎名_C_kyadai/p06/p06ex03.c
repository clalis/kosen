// test.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


double movingAverage(int var);


int main()
{
	int x;
	double y;

	for(x = 0;x < 10;x++)
	{
		y = movingAverage(x);
		printf("x=%6d y=%10.2f\n",x,y);
	}

	return 0;
}


double movingAverage(int var)
{
	double ave = 0;
	static double prev0 = 0;
	static double prev1 = 0;
	static double prev2 = 0;
	static double prev3 = 0;

	prev3 = prev2;
	prev2 = prev1;
	prev1 = prev0;
	prev0 = var;
	
	ave = (prev0 + prev1 + prev2 + prev3) / 4;

	return ave;
}
