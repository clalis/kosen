/***  p10ex01.c  ***/
/***  s15092  2J23  í≈ñº ë◊îV  ***/

#include <stdint.h>
#include <stdio.h>


int factorial(int n)
{
	if(n > 0)	return n * factorial(n - 1);
	else return 1;
}

int main()
{
	int i;
	int fact;

	for (i = 1; i <= 12; i++)
	{
		fact = factorial(i);
		printf("factorial(%2d)=%d\n", i, fact);
	}
}

/*uint64_t fact(uint64_t n);

int main()
{
	uint64_t num;
	char buff[1048576];

	fgets(buff, 1048576, stdin);
	sscanf(buff, "%lld", &num);

	printf("%lld! = %I64d\n", num, fact(num));

	return 0;
}

uint64_t fact(uint64_t n)
{
	if(n > 0)	return n * fact(n - 1);
	else return 1;
}

http://www.c-lang.org/detail/stdint_h.html
http://www.geocities.jp/woodwood77777/c_64bit.htm
*/


/**************** é¿çsåãâ  *****************


factorial( 1)=1
factorial( 2)=2
factorial( 3)=6
factorial( 4)=24
factorial( 5)=120
factorial( 6)=720
factorial( 7)=5040
factorial( 8)=40320
factorial( 9)=362880
factorial(10)=3628800
factorial(11)=39916800
factorial(12)=479001600


*******************************************/
