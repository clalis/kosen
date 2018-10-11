#include <math.h>
#include "Params.h"

/*--- laplacian --- �Q�������ɂ��֊s���o ------------------------------------
	image_in:	���͉摜�z��
	image_out:	�o�͉摜�z��
	amp:		�o�͉摜�̗���
-----------------------------------------------------------------------------*/
void laplacian(unsigned char image_in[Y_SIZE][X_SIZE], 
		unsigned char image_out[Y_SIZE][X_SIZE], float amp)
{
	static int c[9] = {-1, -1, -1	/* �I�y���[�^�̌W��(laplacian) */
					   -1,  8, -1	/* ���̃I�y���[�^�g�p����      */
					   -1, -1, -1};	/* ���������ĉ�����            */
	int	d[9];
	int	i, j, dat;
	float	z, zz;

	for (i = 1; i < Y_SIZE-1; i++) {
		for (j = 1; j < X_SIZE-1; j++) {
			d[0] = image_in[i-1][j-1];
			d[1] = image_in[i-1][j];
			d[2] = image_in[i-1][j+1];
			d[3] = image_in[i][j-1];
			d[4] = image_in[i][j];
			d[5] = image_in[i][j+1];
			d[6] = image_in[i+1][j-1];
			d[7] = image_in[i+1][j];
			d[8] = image_in[i+1][j+1];
			z =  (float)(c[0]*d[0] + c[1]*d[1] + c[2]*d[2]
					   + c[3]*d[3] + c[4]*d[4] + c[5]*d[5]
					   + c[6]*d[6] + c[7]*d[7] + c[8]*d[8]);
			zz = amp*z;
			dat = (int)(zz);
			if (dat <   0) dat = -dat;
			if (dat > 255) dat =  255;
			image_out[i][j] = (char)dat;
		}
	}
}
