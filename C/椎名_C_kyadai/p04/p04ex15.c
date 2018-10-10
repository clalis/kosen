/*p04ex15.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	unsigned long int i, num[50];

	for (i = 0; i < 50; i++)
		num[i] = pow((double)i, 2);
	for (i = 1; i < 50; i += 2)
	{
		printf("%5d\n", num[i]);
	}

RETURN:
	return 0;
}

//////////////////////

//////////////////////
