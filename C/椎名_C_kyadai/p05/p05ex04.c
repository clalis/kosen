/***   p05ex04.c          ***/
/***   s15092 2J23 �Ŗ� �הV      ***/

// test.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <tchar.h>


double average(int array[], int size);

int main()
{
	int data1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int data2[] = { 4,5,0,2,3,7 };
	double ave;

	ave = average(data1, 10);
	printf("%5.1f\n", ave);
	ave = average(data2, 6);
	printf("%5.1f\n", ave);

	return 0;
}

double average(int array[], int size)
{
	double sum, ave;

	sum = 0;
	ave = 0;

	for (size_t i = 0; i < size; i++)
	{
		sum += array[i];
	}
	ave = sum / size;

	return ave;
}

/*** ���s���� ***

  5.5
  3.5


****************/
