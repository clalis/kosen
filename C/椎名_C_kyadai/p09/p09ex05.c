

#include <stdio.h>
#include <stdlib.h>

void reverseString(char *s);

int main(int argc, char*argv[])
{
	char  str1[] = "exercises";
	char  str2[] = "pointer programing";
	puts(str1);
	reverseString(str1);
	puts(str1);
	puts(str2);
	reverseString(str2);
	puts(str2);

	return 0;
}

void reverseString(char *s)
{
	int cnt = 0;
	char sd[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz", *d, *scnt;

	d = sd;
	/*d = (char *)malloc(256);
	if (d == NULL)
	{
		printf("ƒƒ‚ƒŠ‚ªŠm•Û‚Å‚«‚Ü‚¹‚ñ\n");
		exit(EXIT_FAILURE);
	}
	memset(d, '\0', 256);*/

	scnt = s;

	while (*scnt++) cnt++;

	//for (size_t i = 0; i<cnt; i++) d++;
	for (size_t i = 0; i < cnt; i++) s++;

	for (size_t i = 0; i <= cnt; i++)
	{
		*d = *s;
		d++;
		s--;
	}

	*d = '\0';
	for (size_t i = 0; i < cnt; i++)
		d--;
	s = d;

	puts(s);

	//free(d);

	return;
}
