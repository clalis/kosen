/*p02ex17.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int x, y, tmp, a = 0;
	char buff [256];

	printf ("x,y=");
	fgets (buff, 32, stdin);
	sscanf (buff, "%d %d", &x, &y);

	if(x < y)
	{
		tmp = x;
		x = y;
		y = tmp;
	}

	while ((a = x % y) != 0)
	{
		x = y;
		y = a;
	}

	printf ("%d\n",y);

	return 0;
}
