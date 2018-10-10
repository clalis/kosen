/*p02ex15.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int x = 0, cnt = 0, sum = 0;
	char buff [255];

	while (x >= 0)
	{
		x = 0;

		printf ("x%d=", cnt);
		fgets (buff, 255, stdin);
		sscanf (buff, "%d", &x);

		if (x >= 0)
		{
			sum = sum + x;
			cnt++;
		}
	}

	printf ("SUM=%d\nAVE=%.1lf\n", sum, (double) sum / (double) cnt);


	return 0;
}


//55,5.5
//15,3

