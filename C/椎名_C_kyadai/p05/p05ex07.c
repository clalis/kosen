#include <stdio.h>
#include <string.h>

void right(char d[],char s[],int n);

int main(int argc, char*argv[])
{
	char str1[]="exercises";
	char str2[32]="abcdefghijklmn";
	char str3[32]="abcdefghijklmn";
	char str4[]="Tokyo";
	char str5[32]="abcdefghijklmn";
	char str6[32]="abcdefghijklmn";

	right(str2,str1,5);
	puts(str2);					/*実行結果は cises が表示されるはず*/
	right(str3,str1,10);
	puts(str3);					/*実行結果は exercises が表示されるはず*/
	right(str5,str4,3);
	printf("--%s--\n",str5);	/*実行結果は --kyo-- が表示されるはず*/
	right(str6,str4,10);
	printf("--%s--\n",str6);	/*実行結果は --Tokyo-- が表示されるはず*/

	return 0;
}

void right(char d[],char s[],int n)
{
	int i=0,j=0;

	while(s[i]!='\0')
	{
		i++;
	}

	i=i-n;

	if(i<0)
	{
		i=0;
	}
	for(j=0;j<n;j++)
	{
		d[j]=s[i];
		i++;
	}

	d[j]='\0';
}

