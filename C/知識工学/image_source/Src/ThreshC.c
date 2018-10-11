#include  "Params.h"

/*--- thresh_color --- R,G,B�l�ɂ��臒l���� ----------------------------------
	image_in_r:		���͂q�摜
	image_in_g:		���͂f�摜
	image_in_b:		���͂a�摜
	image_out_r:	�o�͂q�摜
	image_out_g:	�o�͂f�摜
	image_out_b:	�o�͂a�摜
	thdrl, thdrm:	�q��臒l (min,max)
	thdgl, thdgm:	�f��臒l (min,max)
	thdbl, thdbm:	�a��臒l (min,max)
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
