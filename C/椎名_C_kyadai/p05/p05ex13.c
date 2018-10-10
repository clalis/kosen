#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <tchar.h>

int checkString(char s[]);
void generateNumber(char theNumber[]);


int main()
{
	char aNumber[10]="abcdefg"; /*ŒŸØ‚Ì‚½‚ß‚ÉˆÓ–¡‚Ì‚È‚¢•¶š—ñ‚ğ‰Šú’l‚Æ‚·‚é*/
	int count;
	srand((unsigned) time(NULL));/*—”—ñ¶¬‚Ì‰Šú‰»*/

	for (count=0; count<10; count++)
	{
		generateNumber(aNumber);
		puts(aNumber);
	}
	return 0;

}

int checkString(char s[])
{
	int ans, i, j;
	ans = 0;
	i = 0;

	while (s[i] != '\0') i++;

	if (i != 4) ans = 1;
	for (i = 0; i < 4; i++)
	{
		if (s[i] < '0' || '9' < s[i]) ans = 1;
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 1 + i; j < 4; j++)
		{
			if (s[i] == s[j]) ans = 1;
		}
	}

	return ans;
}

void generateNumber(char theNumber[])
{
	int chk, n, i;

	do
	{
		for (i = 0; i < 4; i++)
		{
			n = rand() % 10;
			theNumber[i] = n + '0';
		}

		theNumber[i] = '\0';
		chk = checkString(theNumber);

	} while (chk == 1);

	return;
}
