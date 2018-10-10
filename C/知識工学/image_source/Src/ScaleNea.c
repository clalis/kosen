#include	"Params.h"

/*--- scale_near --- 拡大縮小（最近傍法）--------------------------------------
	image_in:	入力画像配列
	image_out:	出力画像配列
	zx:			拡大率（横）
	zy:			拡大率（縦）
-----------------------------------------------------------------------------*/
void scale_near(unsigned char image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE], float zx, float zy)
{
	int	i, j, m, n;
	int	xs = X_SIZE/2;
	int	ys = Y_SIZE/2;

	for (i = -ys; i < ys; i++) {
		for (j = -xs;j < xs; j++) {
			if (i > 0) m = (int)(i/zy + 0.5);
			else m = (int)(i/zy - 0.5);
			if (j > 0) n = (int)(j/zx + 0.5);
			else n = (int)(j/zx - 0.5);
			if ( (m >= -ys) && (m < ys) && (n >= -xs) && (n < xs) )
				image_out[i+ys][j+xs] = image_in[m+ys][n+xs];
			else
				image_out[i+ys][j+xs] = 0;
		}
	}
}
