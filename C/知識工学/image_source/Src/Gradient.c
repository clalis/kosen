#include <math.h>
#include "Params.h"

/*--- gradient --- １次微分による輪郭抽出 -------------------------------------
	image_in:	入力画像配列
	image_out:	出力画像配列
	amp:		出力画像の利得
-----------------------------------------------------------------------------*/
void gradient(unsigned char image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE], float amp)
{
	static int cx[9] = { 0, 0, 0,	/* オペレータの係数ｘ(Roberts) */
						 0, 1, 0,	/* 他のオペレータの時は        */
						 0, 0,-1};	/* 書き換えて下さい            */
	static int cy[9] = { 0, 0, 0,	/* オペレータの係数ｙ(Roberts) */
						 0, 0, 1,	/* 他のオペレータの時は        */
						 0,-1, 0};	/* 書き換えて下さい            */
	int		d[9];
	int		i, j, dat;
	float	xx, yy, zz;

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
		    xx = (float)(cx[0]*d[0] + cx[1]*d[1] + cx[2]*d[2]
					   + cx[3]*d[3] + cx[4]*d[4] + cx[5]*d[5]
					   + cx[6]*d[6] + cx[7]*d[7] + cx[8]*d[8]);
			yy = (float)(cy[0]*d[0] + cy[1]*d[1] + cy[2]*d[2]
					   + cy[3]*d[3] + cy[4]*d[4] + cy[5]*d[5]
					   + cy[6]*d[6] + cy[7]*d[7] + cy[8]*d[8]);
			zz = (float)(amp*sqrt(xx*xx+yy*yy));
			dat = (int)zz;
			if(dat > 255) dat = 255;
			image_out[i][j] = (char)dat;
		}
	}
}
