#include "Params.h"

/*--- rgb_to_yc --- Ｒ,Ｇ,Ｂから輝度,色差信号に変換する -----------------------
	image_r:	入力画像配列    Ｒ
	image_g:	入力画像配列    Ｇ
	image_b:	入力画像配列    Ｂ
	y:			出力データ配列　Ｙ
	c1:			出力データ配列Ｒ－Ｙ
	c2:			出力データ配列Ｂ－Ｙ
-----------------------------------------------------------------------------*/
void rgb_to_yc(unsigned char image_r[Y_SIZE][X_SIZE], 
	unsigned char image_g[Y_SIZE][X_SIZE], 
	unsigned char image_b[Y_SIZE][X_SIZE], 
	int y[Y_SIZE][X_SIZE], int c1[Y_SIZE][X_SIZE], int c2[Y_SIZE][X_SIZE])
{
	int		i, j;
	float	fr, fg, fb;

	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			fr = (float)image_r[i][j];
			fg = (float)image_g[i][j];
			fb = (float)image_b[i][j];
			y[i][j] = (int)(0.3 * fr + 0.59 * fg + 0.11 * fb);
			c1[i][j] = (int)(0.7 * fr - 0.59 * fg - 0.11 * fb);
			c2[i][j] = (int)(-0.3 * fr - 0.59 * fg + 0.89 * fb);
		}  
	}
}

/*--- yc_to_rgb --- 輝度,色差信号からＲ,Ｇ,Ｂ信号に変換する -------------------
	y:			入力データ配列　Ｙ
	c1:			入力データ配列Ｒ－Ｙ
	c2:			入力データ配列Ｂ－Ｙ
	image_r:	出力画像配列    Ｒ
	image_g:	出力画像配列    Ｇ
	image_b:	出力画像配列    Ｂ
------------------------------------------------------------------------------*/
void yc_to_rgb(int y[Y_SIZE][X_SIZE],
	int c1[Y_SIZE][X_SIZE],
	int c2[Y_SIZE][X_SIZE],
	unsigned char image_r[Y_SIZE][X_SIZE],
	unsigned char image_g[Y_SIZE][X_SIZE],
	unsigned char image_b[Y_SIZE][X_SIZE])
{
	int	i, j;
	int	ir, ig, ib;

	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			ir = y[i][j] + c1[i][j];
			if (ir > 255) ir = 255;
			if (ir < 0) ir = 0;
			ig = (int)(y[i][j] - 0.3 / 0.59 *
				c1[i][j] - 0.11 / 0.59 * c2[i][j]);
			if (ig > 255) ig = 255;
			if (ig < 0) ig = 0;
			ib = y[i][j] + c2[i][j];
			if (ib > 255) ib = 255;
			if (ib < 0) ib = 0;
			image_r[i][j] = (unsigned char)ir;
			image_g[i][j] = (unsigned char)ig;
			image_b[i][j] = (unsigned char)ib;
		}
	}
}
