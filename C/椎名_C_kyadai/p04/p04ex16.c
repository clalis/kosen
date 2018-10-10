/*p04ex16.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int i, num[20] = { 0 };

	for (i = pow((double)2, 2); i < 20; i += 2)
		num[i] = 1;

	for (i = 0; i < 20; i++)
		printf("%d", num[i]);
	printf("\n");

RETURN:
	return 0;
}

//////////////////////

//////////////////////
