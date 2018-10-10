#include	"Params.h"

/*--- shift --- �ʒu�̈ړ��i���`��Ԗ@�j---------------------------------------
	image_in:	���͉摜�z��
	image_out:	�o�͉摜�z��
	px:			�ړ��ʁi���j
	py:			�ړ��ʁi�c�j
-----------------------------------------------------------------------------*/
void shift(unsigned char image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE], float px, float py)
{
	int	i, j, m, n;
	float	x, y, p, q;
	int	xs = X_SIZE/2;
	int	ys = Y_SIZE/2;
	int	d;

	for (i = -ys; i < ys; i++) {
		for (j = -xs; j < xs; j++) {
			y = i - py;
			x = j - px;
			if (y > 0) m = (int)y;
			else m = (int)(y-1);
			if (x > 0) n = (int)x;
			else n = (int)(x-1);
			q = y - m;
			p = x - n;
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
