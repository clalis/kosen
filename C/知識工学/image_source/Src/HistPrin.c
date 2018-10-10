#include <stdio.h>
#include "Params.h"

/*--- histprint --- ヒストグラムを数字とグラフで印字する ----------------------
	hist:	ヒストグラム
	buf:	メッセージ用バッファ
-----------------------------------------------------------------------------*/
void histprint(long hist[256], char *buf)
{
	int		i, j, k;
	float	p, q, max;
	int		posi, m;

	posi = 0;
	p = X_SIZE*Y_SIZE;
	max = 0;
	for (i = 0; i < 256; i++) if (hist[i] > max) max = (float)hist[i];
	for (i = 0; i < 256; i++) {
		q = (float)((float)hist[i]/p*100.0);
		m = sprintf(&buf[posi], "%3d:%5.1f%%|",i,q);
		posi += m;
		k = (int)((float)hist[i]/max*60.0);
		for (j = 0; j < k; j++) {
			m = sprintf(&buf[posi], "*");
			posi += m;
		}
		m = sprintf(&buf[posi], "\n");
		posi += m;
	}
}

