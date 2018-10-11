#include "Params.h"

/*--- amplify --- �摜�̖��邳�����{���� --------------------------------------
	image_in:	���͉摜�z��
	image_out:	�o�͉摜�z��
	n:			�{��
-----------------------------------------------------------------------------*/
void amplify(unsigned char image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE], float n)
{
	int i, j, nf;

	for (i = 0; i < Y_SIZE; i++){
    	for (j = 0; j < X_SIZE; j++){
			nf = (int)(image_in[i][j] * n);
			if (nf > 255) nf = 255;
			image_out[i][j] = (unsigned char)nf;
		}
	}
}
