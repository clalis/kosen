#include "stdafx.h"

int countBlow(char s1[], char s2[]);

int main()
{
	int i, count;
	char s0[] = "1234", char s1[] = "9387", s2[] = "9807", s3[] = "0391", s4[] = "4213", s5[] = "4312";

	count = countBlow(s0, s1);
	printf("%s %s => %d\n", s0, s1, count);
	count = countBlow(s0, s2);
	printf("%s %s => %d\n", s0, s2, count);
	count = countBlow(s0, s3);
	printf("%s %s => %d\n", s0, s3, count);
	count = countBlow(s0, s4);
	printf("%s %s => %d\n", s0, s4, count);
	count = countBlow(s0, s5);
	printf("%s %s => %d\n", s0, s5, count);

	return 0;
}

int countBlow(char s1[], char s2[])
{
	int fair, i, j;
	fair = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (i != j && s1[i] == s2[j]) fair++;
		}
	}
	return fair;

	return 0;
}
