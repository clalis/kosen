/*p04ex03.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int i, j, n, tmp, myarray[100] =
	{
		467, 41, 334, 500, 169, 724, 478, 358, 962, 464,
		705, 145, 281, 827, 961, 491, 995, 942, 827, 436,
		391, 604, 902, 153, 292, 382, 421, 716, 718, 895,
		447, 726, 771, 538, 869, 912, 667, 299, 35, 894,
		703, 811, 322, 333, 673, 664, 141, 711, 253, 868,
		547, 644, 662, 757, 37, 859, 723, 741, 529, 778,
		316, 35, 190, 842, 288, 106, 40, 942, 264, 648,
		446, 805, 890, 729, 370, 350, 6, 101, 393, 548,
		629, 623, 84, 954, 756, 840, 966, 376, 931, 308,
		944, 439, 626, 323, 537, 538, 118, 82, 929, 541
	};
	n = sizeof(myarray) / sizeof(int);

	printf("before\n");

	for (i = 0; i < n; i++)
	{
		if (((i + 1) % 10 != 0) || (i == 0))
		{
			printf("%3d ", myarray[i]);
		}
		else
		{
			printf("%3d\n", myarray[i]);
		}
	}

	printf("\nafter\n");

	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (myarray[j - 1] > myarray[j])
			{
				tmp = myarray[j];
				myarray[j] = myarray[j - 1];
				myarray[j - 1] = tmp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (((i + 1) % 10 != 0) || (i == 0))
		{
			printf("%3d ", myarray[i]);
		}
		else
		{
			printf("%3d\n", myarray[i]);
		}
	}
	putchar('\n');

RETURN:
	return 0;
}


//////////////////////

//////////////////////
