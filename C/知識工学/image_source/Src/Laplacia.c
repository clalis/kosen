#include <math.h>
#include "Params.h"

/*--- laplacian --- ２次微分による輪郭抽出 ------------------------------------
	image_in:	入力画像配列
	image_out:	出力画像配列
	amp:		出力画像の利得
-----------------------------------------------------------------------------*/
void laplacian(unsigned char image_in[Y_SIZE][X_SIZE], 
		unsigned char image_out[Y_SIZE][X_SIZE], float amp)
{
	static int c[9] = {-1, -1, -1	/* オペレータの係数(laplacian) */
					   -1,  8, -1	/* 他のオペレータ使用時は      */
					   -1, -1, -1};	/* 書き換えて下さい            */
	int	d[9];
	int	i, j, dat;
	float	z, zz;

	for (i = 1; i < Y_SIZE-1; i++) {
		for (j = 1; j < X_SIZE-1; j++) {
			d[0] = image_in[i-1][j-1];
			d[1] = image_in[i-1][j];
			d[2] = image_in[i-1][j+1];
			d[3] = image_in[i][j-1];
			d[4] = image_in[i][j];
			d[5] = image_in[i][j+1];
			d[6] = image_in[i+1][j-1];
			d[7] = image_in[i+1][j];
			d[8] = image_in[i+1][j+1];
			z =  (float)(c[0]*d[0] + c[1]*d[1] + c[2]*d[2]
					   + c[3]*d[3] + c[4]*d[4] + c[5]*d[5]
					   + c[6]*d[6] + c[7]*d[7] + c[8]*d[8]);
			zz = amp*z;
			dat = (int)(zz);
			if (dat <   0) dat = -dat;
			if (dat > 255) dat =  255;
			image_out[i][j] = (char)dat;
		}
	}
}
