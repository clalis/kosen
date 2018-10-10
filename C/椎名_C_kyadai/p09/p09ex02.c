#include <stdio.h>

void left(char *d,char *s,int n)
{
	for(size_t i=0;i<n;i++)
	{
		*d=*s;
		d++;
		s++;
	}

	return;
}

int main(int argc, char*argv[])
{
	char str1[]="exercises";
    char str2[32]="abcdefghijklmn";
    char str3[32]="abcdefghijklmn";
    
    left(str2,str1,5);
    puts(str2);
    left(str3,str1,10);
    puts(str3);

	return 0;
}
