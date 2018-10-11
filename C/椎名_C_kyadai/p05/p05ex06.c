#include <stdio.h>
#include <string.h>

void left(char d[],char s[],int n)
{
	memset(d,'\0',32);
	for(size_t i=0;i<n;i++)
	{
		d[i]='\0';
		if(s[i]!='\0')d[i]=s[i];
		if(s[i]=='\0')	break;
	}
}

int main(int argc, char*argv[])
{
	char str1[]="exercises";
	char str2[32]="abcdefghijklmn";
	char str3[32]="abcdefghijklmn";

	left(str2,str1,5);
	puts(str2);		/*実行結果は exerc が表示されるはず*/
	left(str3,str1,10);
	puts(str3);		/*実行結果は exercises が表示されるはず*/

	return 0;
}

