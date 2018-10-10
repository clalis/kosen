#include <stdio.h>
#include <string.h>

void mid(char d[],char s[],int m,int n);

int main(int argc, char*argv[])
{
	char str1[]="exercises";
	char str2[32]="abcdefghijklmn";
	char str3[32]="abcdefghijklmn";
	char str4[32]="abcdefghijklmn";
	char str5[]="Tokyo";
	char str6[32]="abcdefghijklmn";
	char str7[32]="abcdefghijklmn";

	puts(str1);
	mid(str2,str1,2,5);
	puts(str2);
	mid(str3,str1,2,10);
	puts(str3);
	mid(str4,str1,12,3);
	puts(str4);
	printf("%d\n",str4[0]);
	mid(str6,str5,2,1);
	printf("--%s--\n",str6);
	mid(str7,str5,2,10);
	printf("--%s--\n",str7);

	return 0;
}

void mid(char d[],char s[],int m,int n)
{
	int i=0,j=0,k=0;

	i=m-1;
	while(s[k]!='\0')	k++;
	if(k<i)	n=0;

	for(j=0;j<n;j++)
	{
		d[j]=s[i];
		i++;
	}

	d[j]='\0';
}

