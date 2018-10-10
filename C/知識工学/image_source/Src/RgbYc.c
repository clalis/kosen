#include "Params.h"

/*--- rgb_to_yc --- �q,�f,�a����P�x,�F���M���ɕϊ����� -----------------------
	image_r:	���͉摜�z��    �q
	image_g:	���͉摜�z��    �f
	image_b:	���͉摜�z��    �a
	y:			�o�̓f�[�^�z��@�x
	c1:			�o�̓f�[�^�z��q�|�x
	c2:			�o�̓f�[�^�z��a�|�x
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

/*--- yc_to_rgb --- �P�x,�F���M������q,�f,�a�M���ɕϊ����� -------------------
	y:			���̓f�[�^�z��@�x
	c1:			���̓f�[�^�z��q�|�x
	c2:			���̓f�[�^�z��a�|�x
	image_r:	�o�͉摜�z��    �q
	image_g:	�o�͉摜�z��    �f
	image_b:	�o�͉摜�z��    �a
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
