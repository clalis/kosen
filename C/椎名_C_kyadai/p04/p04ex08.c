/*p04ex08.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	char buff[256], str1[256] = { 0 }, str2[256] = { 0 };

	fgets(buff, 128, stdin);
	sscanf(buff, "%s%s", str1, str2);

	if (str1[0] == str2[0])
		printf("equal\n");
	else
		printf("not equal\n");

RETURN:
	return 0;
}

//////////////////////

//////////////////////
