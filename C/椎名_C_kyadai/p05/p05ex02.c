/*p05ex02.c*/

#include <stdio.h>

double average4(double x1,double x2,double x3,double x4)
{
	double sum,ave;
	sum=0;
	ave=0;

	sum+=x1;
	sum+=x2;
	sum+=x3;
	sum+=x4;

	ave=sum/4;

	return ave;
}

int main(int argc, char*argv[])
{
	double ans;
	ans=average4(10.0, 20.0, 30.0, 40.0);

	printf("%f\n",ans);

	return 0;
}

//////////////////////

//////////////////////

