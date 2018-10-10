#include  "Params.h"

/*--- hard_mask --- �����L�[�i�n�[�h�L�[�j�̐��� ------------------------------
	image_in_r:	���͂q�摜
	image_in_g:	���͂f�摜
	image_in_b:	���͂q�摜
	image_key:	���͂a�摜
	thresh:		臒l
-----------------------------------------------------------------------------*/
void hard_mask(unsigned char image_in_r[Y_SIZE][X_SIZE], 
	unsigned char image_in_g[Y_SIZE][X_SIZE], 
	unsigned char image_in_b[Y_SIZE][X_SIZE], 
	unsigned char image_key[Y_SIZE][X_SIZE], int thresh)
{
	int   i, j, d;
	
	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			d = ((int)image_in_r[i][j] + (int)image_in_g[i][j]) / 2
				- (int)image_in_b[i][j];
			if (d >= thresh) image_key[i][j] = 255;
			else             image_key[i][j] = 0;
		}
	}
}
