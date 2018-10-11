/*p04ex13.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int i = 0, cnta = 0, cnte = 0, cnti = 0, cnto = 0, cntu = 0;
	char buff[1024], str[1024];

	fgets(buff, 512, stdin);
	sscanf(buff, "%s", str);

	do
	{
		if ((str[i] == 'A') || (str[i] == 'a'))
		{
			cnta++;
		}
		if ((str[i] == 'E') || (str[i] == 'e'))
		{
			cnte++;
		}
		if ((str[i] == 'I') || (str[i] == 'i'))
		{
			cnti++;
		}
		if ((str[i] == 'O') || (str[i] == 'o'))
		{
			cnto++;
		}
		if ((str[i] == 'U') || (str[i] == 'u'))
		{
			cntu++;
		}
		i++;
	} while (str[i]);

	printf("a=%d\ne=%d\ni=%d\no=%d\nu=%d\n", cnta, cnte, cnti, cnto, cntu);

RETURN:
	return 0;
}

//////////////////////

//////////////////////
