/*p04ex14.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int day[32];
	char buff[256], week[7][20] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };


	fgets(buff, 16, stdin);
	sscanf(buff, "%d", day);

	day[0] -= 1;
	day[0] %= 7;
	printf("%s\n", &week[(int)day + 1]);

RETURN:
	return 0;
}

//////////////////////

//////////////////////
