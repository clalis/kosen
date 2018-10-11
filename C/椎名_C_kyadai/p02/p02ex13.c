/*p02ex13.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int x, cnt, sum = 0;
	char buff [10];

	for (size_t cnt = 1, x = 0; cnt <= 10; cnt++)
	{
		printf ("x%d=", cnt);
		fgets (buff, 10, stdin);
		sscanf (buff, "%d", &x);
		
		sum = sum + x;
	}

	printf ("SUM=%d\n",sum);


	return 0;
}


//55,155

