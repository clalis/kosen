/*p02ex16.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int x = 0, cnt = 0, sum = 0, temp;
	char buff [256];

	do
	{
		printf("key in an integer : ");
		fgets(buff, 255, stdin);
		sscanf(buff, "%d", &x);

		cnt = 0;
		temp = x;

		while (x > 0)
		{
			x = x / 10;
			cnt++;
		}

		printf ("%d : %d (digits)\n", temp, cnt);
	}
	while (x >= 0);


	return 0;
}

