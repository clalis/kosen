#include <stdio.h>

int mystrlen(char *str)
{
	int n = 0;

    while (*str++) n++;
    return (n);
}

int main(int argc, char*argv[])
{
	char  str1[]="exercises";
    char  str2[]="pointer programing";
    int cnt1,cnt2;
    
    cnt1=mystrlen(str1);
    cnt2=mystrlen(str2);
    
    printf("%s %d\n",str1,cnt1);
    printf("%s %d\n",str2,cnt2);

	return 0;
}

