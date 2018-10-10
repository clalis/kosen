#include <stdio.h>	/* dev-c++コンパイラでは，上記の"<"や">"と"stdio.h"との間にスペースを入れると*/
#include <stdlib.h>	/*コンパイル時に不具合が発生することがあるので，スペースは入れないように */

#define LINEAR	0	/* 1:線形探索，0:二分探索 */
#define NORMAL	1	/* 1:通常版，  0:番兵版   */
#define LOOP	0	/* 1:ループ版，0:再帰版   */

#define N 30000		/* 探索するレコード数 (注意：この値"だけ"を変えても、実際の検索レコード数は増えない） */


void quick(int data[], int left, int right);				/* クイックソート */
int int_sort(const void* a ,const void* b);					/* クイックソート用比較関数 */
int l_search(int data[], int target);						/* 線形探索 */
int b_search(int data[], int low, int high, int target);	/* 二分探索 */

int main(void)	/* メイン */
{
	int a[N], i, target, work[N], index;

	for (i = 0; i < N; i++)	work[i] = rand() % N;

#if LINEAR

#else
	quick(work,0,N-1);
#endif

	for(target = N/2-500; target < N/2+500; target++)	// 検索レコード数を変えるには、この辺りを修正する
	{
#if LINEAR
		index = l_search(work,target);

#else
		index = b_search(work,0,N-1,target);
#endif

		printf("TARGET=%d: ", target);
		if (index != -1)	printf("○\n");
		else				printf("×\n");
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

#if NORMAL	/* 通常版 */
	for (i = 0; i < N; i++)	if (target == data[i])	return i;
	return -1;

#else		/* 番兵版 */
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
