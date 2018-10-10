#include   "Params.h"

/*--- synth --- ƒNƒƒ}ƒL[‚É‚æ‚é‰æ–Ê‡¬ --------------------------------------
	image_in1_r:		“ü—Í‘OŒi‚q‰æ‘œ
	image_in1_g:		“ü—Í‘OŒi‚f‰æ‘œ
	image_in1_b:		“ü—Í‘OŒi‚a‰æ‘œ
	image_in2_r:		“ü—Í”wŒi‚q‰æ‘œ
	image_in2_g:		“ü—Í”wŒi‚f‰æ‘œ
	image_in2_b:		“ü—Í”wŒi‚a‰æ‘œ
	image_out_r:		o—Í‡¬‚q‰æ‘œ
	image_out_g:		o—Í‡¬‚f‰æ‘œ
	image_out_b:		o—Í‡¬‚a‰æ‘œ
	image_key:			‡¬—pƒL[‰æ‘œ
-----------------------------------------------------------------------------*/
void synth(unsigned char image_in1_r[Y_SIZE][X_SIZE], 
	unsigned char image_in1_g[Y_SIZE][X_SIZE],
	unsigned char image_in1_b[Y_SIZE][X_SIZE],
	unsigned char image_in2_r[Y_SIZE][X_SIZE],
	unsigned char image_in2_g[Y_SIZE][X_SIZE],
	unsigned char image_in2_b[Y_SIZE][X_SIZE],
	unsigned char image_out_r[Y_SIZE][X_SIZE],
	unsigned char image_out_g[Y_SIZE][X_SIZE],
	unsigned char image_out_b[Y_SIZE][X_SIZE],
	unsigned char image_key[Y_SIZE][X_SIZE])
{
	int   i, j;
	int   rr1, gg1, bb1;
	int   rr2, gg2, bb2;
	long  kk;

	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			rr1 = (int)image_in1_r[i][j];
			gg1 = (int)image_in1_g[i][j];
			bb1 = (int)image_in1_b[i][j];
			rr2 = (int)image_in2_r[i][j];
			gg2 = (int)image_in2_g[i][j];
			bb2 = (int)image_in2_b[i][j];
			kk = (long)image_key[i][j];
			image_out_r[i][j] = (unsigned char)((rr1*kk+rr2*(255-kk))/255);
			image_out_g[i][j] = (unsigned char)((gg1*kk+gg2*(255-kk))/255);
			image_out_b[i][j] = (unsigned char)((bb1*kk+bb2*(255-kk))/255);
		}
	}
}
