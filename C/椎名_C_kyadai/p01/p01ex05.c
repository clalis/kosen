/*p01ex05.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	double temp;
    double velo;
    
	printf("What's the air temperature?\n");
	printf("temp=");
	
	scanf("%lf",&temp);
	velo=331.5+0.6*temp;
	
	printf("temperature=%10.1f\n",temp);
	printf("velocity   =%10.1f\n",velo);

	return 0;
}
//////////
//15.0	//
// 340.5//
//		//
//20.0	//
// 343.5//
//		//
//25.0	//
// 346.5//
//		//
//30.0	//
// 349.5//
//////////
