#include "stdafx.h"

int countHit(char s1[], char s2[]);

int main()
{
	char s0[]="1234", char s1[]="9837", s2[]="9817", s3[]="1837", s4[]="1834", s5[]="1234";
	int i,count;
	count=countHit(s0,s1);
	printf ("%s %s => %d\n",s0,s1,count);
	count=countHit(s0,s2);
	printf ("%s %s => %d\n",s0,s2,count);
	count=countHit(s0,s3);
	printf ("%s %s => %d\n",s0,s3,count);
	count=countHit(s0,s4);
	printf ("%s %s => %d\n",s0,s4,count);
	count=countHit(s0,s5);
	printf ("%s %s => %d\n",s0,s5,count);
	
	return 0;
}

int countHit(char s1[], char s2[])
{
	short chk, i;
	chk = 0;

	for (i = 0; i < 4; i++)
	{
		if (s1[i] == s2[i]) chk++;
	}

	return chk;
}
