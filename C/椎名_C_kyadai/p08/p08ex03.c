/***  p08ex03.c  ***/
/***  s15092  2J23  ’Å–¼ ‘×”V  ***/

#include <stdio.h>


typedef struct data_type
{
	char lets[16];
	char letl[16];
	int num;
}data_t;

data_t Data[] =
{
	{ "a","A",21 },
	{ "b","B",20 },
	{ "c","C",19 },
	{ "d","D",18 },
	{ "e","H",17 },
	{ "f","G",16 },
	{ "g","F",15 },
	{ "h","E",14 },
	{ "i","I",13 },
	{ "j","J",12 },
	{ "k","K",11 },
	{ "l","L",10 },
	{ "m","P",9 },
	{ "n","O",8 },
	{ "o","N",7 },
	{ "p","M",6 },
	{ "q","Q",5 },
	{ "r","R",4 },
	{ "s","S",3 },
	{ "t","T",2 },
	{ "u","U",1 }
};

void sortDataInNum(data_t data[], int number)
{
	int i, j;
	data_t tmp;
	for (i = 0; i < number - 1; i++)
	{
		for (j = i + 1; j < number; j++)
		{
			if (data[i].num > data[j].num)
			{
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
		}
	}
}

void sortDataInLetL(data_t data[], int number)
{
	int i, j;
	data_t tmp;
	for (i = 0; i < number - 1; i++)
	{
		for (j = i + 1; j < number; j++)
		{
			if (0 < strcmp(data[i].letl, data[j].letl))
			{
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
		}
	}
}

void printData(data_t data[], int number)
{
	int i;

	for (i = 0; i < number; i++)
	{
		printf("%s\t%s\t%2d\n",
			data[i].lets,
			data[i].letl,
			data[i].num);
	}
}

int main()
{
	int numberOfData = sizeof(Data) / sizeof(data_t);

	printf("** Original data **\n");
	printData(Data, numberOfData);

	sortDataInNum(Data, numberOfData);
	printf("** Number order **\n");
	printData(Data, numberOfData);

	sortDataInLetL(Data, numberOfData);
	printf("** Small Letter order **\n");
	printData(Data, numberOfData);

	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************


** Original data **
a       A       21
b       B       20
c       C       19
d       D       18
e       H       17
f       G       16
g       F       15
h       E       14
i       I       13
j       J       12
k       K       11
l       L       10
m       P        9
n       O        8
o       N        7
p       M        6
q       Q        5
r       R        4
s       S        3
t       T        2
u       U        1
** Number order **
u       U        1
t       T        2
s       S        3
r       R        4
q       Q        5
p       M        6
o       N        7
n       O        8
m       P        9
l       L       10
k       K       11
j       J       12
i       I       13
h       E       14
g       F       15
f       G       16
e       H       17
d       D       18
c       C       19
b       B       20
a       A       21
** Small Letter order **
a       A       21
b       B       20
c       C       19
d       D       18
h       E       14
g       F       15
f       G       16
e       H       17
i       I       13
j       J       12
k       K       11
l       L       10
p       M        6
o       N        7
n       O        8
m       P        9
q       Q        5
r       R        4
s       S        3
t       T        2
u       U        1


*******************************************/
