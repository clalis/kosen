#include        "Params.h"

/*--- scale_ng --- �g��k���i���̂����́C�Ԉ���Ă���j----------------------
	image_in:	���͉摜�z��
	image_out:	�o�͉摜�z��
	zx:			�g�嗦�i���j
	zy:			�g�嗦�i�c�j
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
