#include "stdafx.h"


void reverseString(char s[]);

int main()
{
	char str[30] = "exercises";
	char str2[30] = "java";

	printf("++--%s--++\n", str);
	reverseString(str);
	printf("++--%s--++\n", str);
	printf("++--%s--++\n", str2);
	reverseString(str2);
	printf("++--%s--++\n", str2);

	return 0;
}

void reverseString(char s[])
{
	char tmp = '\0';
	char *f = s;
	char *l = s;

	if (*f == '\0')	return;

	while (*(l + 1) != '\0')	l++;

	while (f < l)
	{
		tmp = *f;
		*f = *l;
		*l = tmp;

		f++;
		l--;
	}

	return;
}

