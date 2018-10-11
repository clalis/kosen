/*p04ex09.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int i;
	char buff[256], str1[256] = { 0 }, str2[256] = { 0 };

	fgets(buff, 128, stdin);
	sscanf(buff, "%s%s", str1, str2);

	for (i = 0; i < 3; i++)
	{
		if (str1[i] != str2[i])
			break;
	}
	if (i == 3)
		printf("equal\n");
	else
		printf("not equal\n");

RETURN:
	return 0;
}

//////////////////////

//////////////////////
