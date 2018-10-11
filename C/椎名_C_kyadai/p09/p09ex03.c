#include <stdio.h>


void right(char *d, char *s, int n);

int main(int argc, char*argv[])
{
	char str1[] = "exercises";
	char str2[32] = "abcdefghijklmn";
	char str3[32] = "abcdefghijklmn";
	char str4[] = "Tokyo";
	char str5[32] = "abcdefghijklmn";
	char str6[32] = "abcdefghijklmn";

	right(str2, str1, 5);
	puts(str2);
	right(str3, str1, 10);
	puts(str3);
	right(str5, str4, 3);
	printf("--%s--\n", str5);
	right(str6, str4, 10);
	printf("--%s--\n", str6);

	return 0;
}

void right(char *d, char *s, int n)
{
	int cnt = 0;
	char *scnt;

	scnt = s;

	while (*scnt++) cnt++;

	//for (size_t i = 0; i<cnt; i++) d++;
	for (size_t i = 0; i < (cnt - 1); i++) s++;
	if (n > cnt)
	{
		n = cnt;
	}
	for (size_t i = 0; i < n; i++)
	{
		*d = *s;
		d++;
		s--;
	}

	*d = '\0';

	return;
}
