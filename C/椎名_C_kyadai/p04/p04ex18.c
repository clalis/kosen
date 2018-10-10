/*p04ex18.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int j, cnt = 0, num[1001];
	for (size_t i = 0; i < 1001; i++)
		num[i] = 1;
	num[0] = num[1] = 0;

	for (size_t i = 2; i <= 32; i++)
	{
		if (num[i] == 1)
		{
			for (j = i * 2; j < 1001; j += i)
			{
				num[j] = 0;
			}
		}
	}

	for (size_t i = 0; i < 1001; i++)
		if (num[i] == 1)
		{
			printf("%4d", i);
			cnt++;
			if (cnt % 10 == 0)
			{
				printf("\n");
			}
		}
	if (cnt % 10 != 0)
		printf("\n");
	printf("%d prime numbers are found.\n", cnt);

RETURN:
	return 0;
}

//////////////////////

//////////////////////
