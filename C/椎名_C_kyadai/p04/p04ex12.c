/*p04ex12.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	while (true)
	{
		char buff[256], num[64];

		fgets(buff, 32, stdin);
		sscanf(buff, "%s", num);

		else if ((num[0] == 0x7a) && (num[1] == 0x7a) && (num[2] == 0x7a) && (num[3] == 0x7a))
			goto RETURN;
		if (num[2] == 0x30 && num[3] == 0x30)
			printf("N/A\n");
		else if ((num[2] != 0) || (num[3] != 0))
			printf("N/A\n");
		else if ((num[0] == 0x32) && (num[1] == 0x4a) && ((num[2] <= 0x30) || (num[2] <= 0x34)) && ((num[3] <= 0x30) || (num[3] <= 0x39)))
			printf("correct!\n");
		else
			printf("N/A\n");
	}

RETURN:
	return 0;
}

//////////////////////

//////////////////////
