#include   "Params.h"

/*--- synth --- �N���}�L�[�ɂ���ʍ��� --------------------------------------
	image_in1_r:		���͑O�i�q�摜
	image_in1_g:		���͑O�i�f�摜
	image_in1_b:		���͑O�i�a�摜
	image_in2_r:		���͔w�i�q�摜
	image_in2_g:		���͔w�i�f�摜
	image_in2_b:		���͔w�i�a�摜
	image_out_r:		�o�͍����q�摜
	image_out_g:		�o�͍����f�摜
	image_out_b:		�o�͍����a�摜
	image_key:			�����p�L�[�摜
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
