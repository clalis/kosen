/*p02ex14.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int x, cnt, sum = 0;
	char buff [10];

	for (size_t cnt = 1, x = 0; cnt <= 10; cnt++)
	{
		printf ("x%d=", cnt);
		fgets (buff, 10, stdin);
		sscanf (buff, "%d", &x);
		
		sum = sum + x;
	}

	printf ("SUM=%d\nAVE=%.1lf\n", sum, (double) sum / 10);	//C99‚È‚ç%lf‚Å‚à‚¨‚‹


	return 0;
}


//55,5.5
//155,15.5

