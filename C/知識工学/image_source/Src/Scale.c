#include	"Params.h"

/*--- scale --- 拡大縮小（線形補間法）-----------------------------------------
	image_in:	入力画像配列
	image_out:	出力画像配列
	zx:			拡大率（横）
	zy:			拡大率（縦）
-----------------------------------------------------------------------------*/
void scale(unsigned char image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE], float zx, float zy)
{
	int	i, j, m, n;
	float	x, y, p, q;
	int	xs = X_SIZE/2;
	int	ys = Y_SIZE/2;
	int 	d;

	for (i = -ys; i< ys; i++) {
		for (j = -xs; j< xs; j++) {
			y = i/zy;
			x = j/zx;
			if (y > 0) m = (int)y;
			else m = (int)(y-1);
			if (x > 0) n = (int)x;
			else n = (int)(x-1);
			q = y - m;
			p = x - n;
			if (q == 1) {q = 0; m = m + 1;}
			if (p == 1) {p = 0; n = n + 1;}
			if ( (m >= -ys) && (m < ys) && (n >= -xs) && (n < xs) )
				d = (int)((1.0-q)*((1.0-p)*image_in[m  +ys][n  +xs]
				                       + p*image_in[m  +ys][n+1+xs])
				              + q*((1.0-p)*image_in[m+1+ys][n  +xs]
				                       + p*image_in[m+1+ys][n+1+xs]));
			else
				d = 0;
			if (d <   0) d =   0;
			if (d > 255) d = 255;
			image_out[i+ys][j+xs] = d;
		}
	}
}
