#define BUF_SIZE 0x20
#include <stdio.h>


int checksp(int c);
void compress(char *s);

int main(void)
{
	char s[] = "     Nice to \n meet \t you    ,  Jack !\n     I'm      Mike \n\t\t .    ";

	printf("Before\t=\t\"%s\"\n", s);
	compress(s);

	printf("After\t=\t\"%s\"\n", s);

	return 0;
}

int checksp(int c)
{
	return ((c == '\t') || (c == '\n') || (c == ' ')) ? 1 : 0;
}

void compress(char *s)
{
	char *p;
	p = s;

	while (checksp(*s))	s++;	/* 行頭の空白を消去 */

	/* 新しい文字列を作成していく */
	while (*s)	/* while文内の条件を記入せよ（必ずしもwhile文で実装しなくても良い）*/
	{
		if ((checksp(*s) == 1) && (checksp(*(s + 1)) == 1))	s++;
		else if ((checksp(*s) == 1) && (checksp(*(s + 1)) == 0))
		{
			if ((*(s + 1) != ',') && (*(s + 1) != '.'))
			{
				*p = ' ';
				p++;
			}
			s++;
		}
		else
		{
			*p = *s;
			p++;
			s++;
		}
	}

	s = p;
	if (checksp(*(--s)) == 1)	*s = '\0';
	*p = '\0';
}
