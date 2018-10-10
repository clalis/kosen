#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>


unsigned long long int fib(unsigned long long int n);
unsigned long long int fact(unsigned long long int n);
unsigned long long int sum(unsigned long long int n);
unsigned long long int d2b(unsigned long long int n);

int main()
{
	unsigned long long int n;
	char buff[256];

	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%I64d", &n);

	//plz choose func
	putchar('\n');

	system("pause");

	return 0;
}

unsigned long long int fib(unsigned long long int n)
{
	if (n < 3)	return 1;
	return fib(n - 2) + fib(n - 1);
}

unsigned long long int fact(unsigned long long int n)
{
	if (n > 0)	return n * fact(n - 1);
	else	return 1;
}

unsigned long long int sum(unsigned long long int n)
{
	if (n == 1) return 1;
	return n + sum(n - 1);
}

unsigned long long int d2b(unsigned long long int n)
{
	if (n < 1)	return 0;

	d2b(n / 2);

	printf("%I64d", n % 2);
	/*for (size_t i = 0x8000; i; i /= 1)
	{
		if (n & i) putchar('1');
		else putchar('0');
	}*/
}
