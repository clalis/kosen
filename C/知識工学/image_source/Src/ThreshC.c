#include  "Params.h"

/*--- thresh_color --- R,G,B’l‚É‚æ‚éè‡’lˆ— ----------------------------------
	image_in_r:		“ü—Í‚q‰æ‘œ
	image_in_g:		“ü—Í‚f‰æ‘œ
	image_in_b:		“ü—Í‚a‰æ‘œ
	image_out_r:	o—Í‚q‰æ‘œ
	image_out_g:	o—Í‚f‰æ‘œ
	image_out_b:	o—Í‚a‰æ‘œ
	thdrl, thdrm:	‚q‚Ìè‡’l (min,max)
	thdgl, thdgm:	‚f‚Ìè‡’l (min,max)
	thdbl, thdbm:	‚a‚Ìè‡’l (min,max)
-----------------------------------------------------------------------------*/
void thresh_color(unsigned char image_in_r[Y_SIZE][X_SIZE], 
	unsigned char image_in_g[Y_SIZE][X_SIZE], 
	unsigned char image_in_b[Y_SIZE][X_SIZE],
	unsigned char image_out_r[Y_SIZE][X_SIZE], 
	unsigned char image_out_g[Y_SIZE][X_SIZE], 
	unsigned char image_out_b[Y_SIZE][X_SIZE],
	int thdrl, int thdrm, int thdgl, int thdgm, int thdbl, int thdbm)
{
	int   i, j;

	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			image_out_r[i][j] = image_in_r[i][j];
			image_out_g[i][j] = image_in_g[i][j];
			image_out_b[i][j] = image_in_b[i][j];
		}
	}
	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			if (image_out_r[i][j] < thdrl)
				image_out_r[i][j] = image_out_g[i][j] = image_out_b[i][j] = 0;
			if (image_out_r[i][j] > thdrm)
				image_out_r[i][j] = image_out_g[i][j] = image_out_b[i][j] = 0;
			if (image_out_g[i][j] < thdgl)
				image_out_r[i][j] = image_out_g[i][j] = image_out_b[i][j] = 0;
			if (image_out_g[i][j] > thdgm)
				image_out_r[i][j] = image_out_g[i][j] = image_out_b[i][j] = 0;
			if (image_out_b[i][j] < thdbl)
				image_out_r[i][j] = image_out_g[i][j] = image_out_b[i][j] = 0;
			if (image_out_b[i][j] > thdbm)
				image_out_r[i][j] = image_out_g[i][j] = image_out_b[i][j] = 0;
		}
	}
}
