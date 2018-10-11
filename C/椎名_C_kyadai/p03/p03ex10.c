/*p03ex10.c*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	double b, c, d, ans[2] = { 0 };
	char buff[256];

	fgets(buff, 255, stdin);
	sscanf(buff, "%lf %lf", &b, &c);

	d = pow(b, 2) - 4 * c;

	if (d == 0)
	{
		ans[0] = -b / 2;
		printf("“ñd‰ğ:%lf\n", ans[0]);
	}
	else if (d > 0)
	{
		ans[0] = (-b + sqrt(d)) / 2;
		ans[1] = (-b - sqrt(d)) / 2;
		printf("À”‰ğ:%lf,%lf\n", ans[0], ans[1]);
	}
	else
	{
		ans[0] = -b / 2;
		ans[1] = sqrt(abs(d)) / 2;
		printf("•¡‘f”‰ğ:%lf}%lfi\n", ans[0], ans[1]);
	}

RETURN:
	return 0;
}
//////////////////////

//////////////////////
