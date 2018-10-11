#include <stdio.h>
#include <math.h>


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int *num;
	int n;
	char buff[256];

	fgets(buff, 12, stdin);
	sscanf(buff, "%d", &n);

	*num = (char *)malloc(n*sizeof(n));
	if (num == NULL)
	{
		printf("ƒƒ‚ƒŠ‚ªŠm•Û‚Å‚«‚Ü‚¹‚ñ\n");
		exit(EXIT_FAILURE);
	}
	memset(num, '\0', n * sizeof(n));

	int j, cnt = 0;
	for (size_t i = 0; i < *num; i++)
		num[i] = 1;
	num[0] = num[1] = 0;

	for (size_t i = 2; i <= 32; i++)
	{
		if (num[i] == 1)
		{
			for (j = i * 2; j < *num; j += i)
			{
				num[j] = 0;
			}
		}
	}

	for (size_t i = 0; i < *num; i++)
		if (num[i] == 1)
		{
			printf("%4d", i);
			cnt++;
			if (cnt % 10 == 0)
			{
				printf("\n");
			}
		}
	if (cnt % 10 != 0)
		printf("\n");
	printf("%d primenumbers are found.\n", cnt);

	free(num);

RETURN:
	return 0;
}
