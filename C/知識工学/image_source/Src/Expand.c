#include "Params.h"

/*--- expand --- �Z�x���O����Q�T�T�͈̔͂ɕϊ����� ---------------------------
	image_in:	���͉摜�z��
	image_out:	�o�͉摜�z��
	fmax:		���͉摜�̔Z�x�̍ő�l
	fmin:		���͉摜�̔Z�x�̍ŏ��l
-----------------------------------------------------------------------------*/
void expand(unsigned char image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE], int fmax, int fmin)
{
	int i, j;
	float d;

	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			d = (float)255 / (float)(fmax - fmin) 
				* ((int)image_in[i][j] - fmin);
			if (d > 255) image_out[i][j] = 255;
			else if (d < 0) image_out[i][j] = 0;
			else            image_out[i][j] = (unsigned char)d;
		}
	}
}
