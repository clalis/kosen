/*p03ex05.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int num,sum = 0,ave,cnt = 0;
	char buff[256];

	while(1)
	{
		num = 0;
		fgets(buff, 255, stdin);
		sscanf(buff, "%d", &num);

		if(num >= 0)
		{
			sum += num;
			cnt++;
		}
		else if(cnt == 0 && num < 0)
		{
			printf("no data.\n");
			goto RETURN;
		}
		else break;
	}

	printf("sum:%d\n", sum);
	printf("ave:%f\n", (double)sum / (double)cnt);

RETURN:
	return 0;
}
//////////////////////

//////////////////////
