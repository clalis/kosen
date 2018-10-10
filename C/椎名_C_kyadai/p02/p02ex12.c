/*p02ex12.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int x, y;

	printf("    ");

	for (size_t x = 1; x <= 12; x++)
	{
		printf ("%4d", x);
	}

	printf ("\n");

	for (size_t y = 1; y <= 12; y++)
	{
		printf ("%4d", y);
		
		for (size_t x = 1; x <= 12; x++)
		{
			printf ("%4d", x * y);
		}

		printf ("\n");
	}

	return 0;
}
