#include	"Params.h"

/*--- scale_near --- �g��k���i�ŋߖT�@�j--------------------------------------
	image_in:	���͉摜�z��
	image_out:	�o�͉摜�z��
	zx:			�g�嗦�i���j
	zy:			�g�嗦�i�c�j
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
