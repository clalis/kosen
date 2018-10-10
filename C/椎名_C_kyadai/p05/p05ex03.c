/*p05ex03.c*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

double heronformula(double a,double b,double c)
{
	double s,T;

	s=(a+b+c)/2;

	T=sqrt(s*(s-a)*(s-b)*(s-c));

	return T;
}

int main(int argc, char*argv[])
{
	double a,b,c,area;
	a=3.0;
	b=4.0;
	c=5.0;
	area=heronformula(a,b,c);
	printf("a,b,c,area=%f, %f, %f, %f\n",a,b,c,area);
	a=5.0;
	b=12.0;
	c=13.0;
	area=heronformula(a,b,c);
	printf("a,b,c,area=%f, %f, %f, %f\n",a,b,c,area);
	a=3.0;
	b=4.0;
	c=8.0;
	area=heronformula(a,b,c);
	printf("a,b,c,area=%f, %f, %f, %f\n",a,b,c,area);

	return 0;
}

//////////////////////

//////////////////////

