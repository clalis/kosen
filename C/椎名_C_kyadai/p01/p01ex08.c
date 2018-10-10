/*p01ex08.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	double upper,lower,height;

	printf("è„íÍ â∫íÍ çÇÇ≥Çì¸óÕ(cm)--> ");

	scanf("%lf%lf%lf",&upper,&lower,&height);

	printf("ñ êœ=%.3f\n",(upper+lower)*height/2);

	return 0;
}
//////////////////////
//2.5 3.2 4.5 12.825//
//					//
//3.4 2.4 6.5 18.850//
//					//
//2.8 3.7 6.2 20.150//
//					//
//3.5 1.2 3.5 8.225	//
//////////////////////
