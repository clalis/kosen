#include "Params.h"

/*---- colorbar --- �J���[�o�[����� ------------------------------------------
	image_r:	�o�͉摜�z��@�q
	image_g:	�o�͉摜�z��@�f
	image_b:	�o�͉摜�z��@�a
	level:		�Z�x�l
-----------------------------------------------------------------------------*/
void colorbar(unsigned char image_r[Y_SIZE][X_SIZE], 
	unsigned char image_g[Y_SIZE][X_SIZE], 
	unsigned char image_b[Y_SIZE][X_SIZE], int level)
{
	int     i, j, width;

	width = X_SIZE / 8;
	for (i = 0; i < Y_SIZE; i++){
		for (j = 0; j < X_SIZE; j++){
			if (((j >= 0) && (j < 2*width)) ||  /* �q�v���[�� */
					((j >= 4*width) && (j < 6*width)))
				image_r[i][j] = level;
			else image_r[i][j] = 0;
			if ((j >= 0) && (j < 4*width ))     /* �f�v���[�� */
				image_g[i][j] = level;
			else image_g[i][j] = 0;
			if (((j >= 0) && (j < width )) ||   /* �a�v���[�� */
					((j >= 2*width) && (j < 3*width)) ||
					((j >= 4*width) && (j < 5*width)) ||
					((j >= 6*width) && (j < 7*width)))
				image_b[i][j] = level;
			else image_b[i][j] = 0;
		}
	}
}
