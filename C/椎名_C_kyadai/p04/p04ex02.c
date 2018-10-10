/*p04ex02.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	unsigned int sum, mon, day, numberofdays [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char buff [256];
	sum = mon = day = 0;

	fgets (buff, 16, stdin);
	sscanf (buff, "%d %d", &mon, &day);

	if (mon != 1)
	{
		for (size_t i = 0; i < mon - 1; i++)
		{
			sum += numberofdays[i];
		}
	}
	sum += day;

	printf ("%d\n", sum);

RETURN:
	return 0;
}

//////////////////////

//////////////////////
