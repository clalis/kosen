#include "stdafx.h"


int checkString(char s[]);

int main()
{
	int chk;
	char s1[] = "1234";
	char s2[] = "123";
	char s3[] = "12345";
	char s4[] = "A123";
	char s5[] = "123#";
	char s6[] = "1231";

	chk = checkString(s1);
	printf("%5s => %d\n", s1, chk);
	chk = checkString(s2);
	printf("%5s => %d\n", s2, chk);
	chk = checkString(s3);
	printf("%5s => %d\n", s3, chk);
	chk = checkString(s4);
	printf("%5s => %d\n", s4, chk);
	chk = checkString(s5);
	printf("%5s => %d\n", s5, chk);
	chk = checkString(s6);
	printf("%5s => %d\n", s6, chk);

	return 0;
}

int checkString(char s[])
{
	int chk, i, j;
	chk = 0;
	i = 0;

	while (s[i] != '\0') i++;

	if (i != 4) chk = 1;
	for (i = 0; i < 4; i++)
	{
		if (s[i] < '0' || '9' < s[i]) chk = 1;
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 1 + i; j < 4; j++)
		{
			if (s[i] == s[j]) chk = 1;
		}
	}

	return chk;
}
