#include <stdio.h>	/* dev-c++�R���p�C���ł́C��L��"<"��">"��"stdio.h"�Ƃ̊ԂɃX�y�[�X�������*/
#include <stdlib.h>	/*�R���p�C�����ɕs����������邱�Ƃ�����̂ŁC�X�y�[�X�͓���Ȃ��悤�� */

#define LINEAR	0	/* 1:���`�T���C0:�񕪒T�� */
#define NORMAL	1	/* 1:�ʏ�ŁC  0:�ԕ���   */
#define LOOP	0	/* 1:���[�v�ŁC0:�ċA��   */

#define N 30000		/* �T�����郌�R�[�h�� (���ӁF���̒l"����"��ς��Ă��A���ۂ̌������R�[�h���͑����Ȃ��j */


void quick(int data[], int left, int right);				/* �N�C�b�N�\�[�g */
int int_sort(const void* a ,const void* b);					/* �N�C�b�N�\�[�g�p��r�֐� */
int l_search(int data[], int target);						/* ���`�T�� */
int b_search(int data[], int low, int high, int target);	/* �񕪒T�� */

int main(void)	/* ���C�� */
{
	int a[N], i, target, work[N], index;

	for (i = 0; i < N; i++)	work[i] = rand() % N;

#if LINEAR

#else
	quick(work,0,N-1);
#endif

	for(target = N/2-500; target < N/2+500; target++)	// �������R�[�h����ς���ɂ́A���̕ӂ���C������
	{
#if LINEAR
		index = l_search(work,target);

#else
		index = b_search(work,0,N-1,target);
#endif

		printf("TARGET=%d: ", target);
		if (index != -1)	printf("��\n");
		else				printf("�~\n");
	}

	return 0;
}

void quick(int data[], int left, int right)
{
	qsort((void *)data, N, sizeof(data[0]), int_sort);
}

int int_sort(const void* a ,const void* b)
{
	if (*(int *)a < *(int *)b)			return -1;
	else	if (*(int *)a == *(int *)b)	return 0;
	return 1;
}

int l_search(int data[], int target)
{
	int i, count = 0;

#if NORMAL	/* �ʏ�� */
	for (i = 0; i < N; i++)	if (target == data[i])	return i;
	return -1;

#else		/* �ԕ��� */
	data[N] = target;

	while (data[i] != target)	i++;
	if (i == N)	return -1;
	return i;
#endif
}

int b_search(int data[], int low, int high, int target)
{
	int mid;

#if LOOP
	while (low < high)
	{
		mid = (low + high) / 2;
		if (data[mid] == target)	return mid;
		else if (target < data[mid])	high = mid - 1;
		else	low = mid + 1;
	}
	return -1;

#else
	if (high < low)	return -1;
	else
	{
		int mid = low + (high - low) / 2;

		if (data[mid] > target)	return b_search(data, low, mid - 1, target);
		else if (data[mid] < target)	return b_search(data, mid + 1, high, target);
		else	return mid;
	}
#endif
}
