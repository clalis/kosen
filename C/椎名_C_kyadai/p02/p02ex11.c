/*p02ex11.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int x, y;

	printf("   ");

	for (size_t x = 1; x <= 9; x++)
	{
		printf ("%3d", x);
	}

	printf ("\n");

	for (size_t y = 1; y <= 9; y++)
	{
		printf ("%3d", y);
		
		for (size_t x = 1; x <= 9; x++)
		{
			printf ("%3d", x * y);
		}

		printf ("\n");
	}

	return 0;
}
