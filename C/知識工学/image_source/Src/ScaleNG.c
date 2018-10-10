#include        "Params.h"

/*--- scale_ng --- 拡大縮小（このやり方は，間違っている）----------------------
	image_in:	入力画像配列
	image_out:	出力画像配列
	zx:			拡大率（横）
	zy:			拡大率（縦）
-----------------------------------------------------------------------------*/
void scale_ng(unsigned char image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE], float zx, float zy)
{
	int	i, j, m, n;
	int	xs = X_SIZE/2;
	int	ys = Y_SIZE/2;

	for (i = -ys; i < ys; i++) {
		for (j = -xs; j < xs; j++) {
			m = (int)(zy * i);
			n = (int)(zx * j);
			if ( (m >= -ys) && (m < ys) && (n >= -xs) && (n < xs) )
				image_out[m+ys][n+xs] = image_in[i+ys][j+xs];
		}
	}
}
