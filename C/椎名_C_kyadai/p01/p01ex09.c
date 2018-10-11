/*p01ex09.c*/

#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>

int main(void)
{
	long double x=M_PI;
	double r=0;

	printf("r=");

	scanf("%lf",&r);

	printf("ëÃêœ:%fï\ñ êœ:%f",4*M_PI*(double)pow(r,3)/3,4*M_PI*(double)pow(r,2));

	return 0;
}
//////////////////////

//////////////////////
