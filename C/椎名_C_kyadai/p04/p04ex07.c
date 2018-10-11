/*p04ex07.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int cnt = 0, i = 0;
	char str[256];

	fgets (str, 32, stdin);

	do
	{
		if (str[i] == 'e')
		{
			cnt++;
		}
		i++;
	} while (str[i]);

	printf ("%d\n", cnt);

RETURN:
	return 0;
}

//////////////////////

//////////////////////
