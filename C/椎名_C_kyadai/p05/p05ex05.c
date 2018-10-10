#include <stdio.h>

void reverse(int array[], int size)
{

	int sub[256];

	for(size_t i=0;i<size;i++)
	{
		sub[size-i-1]=array[i];
	}
	for(size_t i=0;i<size;i++)
	{
		array[i]=sub[i];
	}
}


int main(int argc, char*argv[])
{
	int i;
	int array[] = {100,2,3,11,12,13,21,22,23,100};

	reverse(array,10);
	for(i=0;i<10;++i) printf("%d ",array[i]);
	printf("\n");
	reverse(array,4);
	for(i=0;i<4;++i) printf("%d ",array[i]);
	printf("\n");

	return 0;
}

