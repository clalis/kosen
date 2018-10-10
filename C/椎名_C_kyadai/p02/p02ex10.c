/*p02ex10.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int n, x, y;

	printf("n=");
	scanf("%d", &n);

	for (size_t y = 1; y < (n + 1) / 2; y++)
	{
		for (x = 0; x < (n + 1) / 2 - y; x++) printf("-");
		for (x = 0; x < 2 * y - 1; x++) printf("*");
		for (x = 0; x < (n + 1) / 2 - y; x++) printf("-");

		printf ("\n");
	}

	for (size_t y = (n + 1) / 2; y <= n; y++)
	{
		for (x = 0; x < y - (n + 1) / 2; x++) printf("-");
		for (x = 0; x < n - (y - (n + 1) / 2) * 2; x++) printf("*");
		for (x = 0; x < y - (n + 1) / 2; x++) printf("-");

		printf ("\n");
	}

	return 0;
}
