#include <math.h>
#include "Params.h"

/*--- gradient --- �P�������ɂ��֊s���o -------------------------------------
	image_in:	���͉摜�z��
	image_out:	�o�͉摜�z��
	amp:		�o�͉摜�̗���
-----------------------------------------------------------------------------*/
void gradient(unsigned char image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE], float amp)
{
	static int cx[9] = { 0, 0, 0,	/* �I�y���[�^�̌W����(Roberts) */
						 0, 1, 0,	/* ���̃I�y���[�^�̎���        */
						 0, 0,-1};	/* ���������ĉ�����            */
	static int cy[9] = { 0, 0, 0,	/* �I�y���[�^�̌W����(Roberts) */
						 0, 0, 1,	/* ���̃I�y���[�^�̎���        */
						 0,-1, 0};	/* ���������ĉ�����            */
	int		d[9];
	int		i, j, dat;
	float	xx, yy, zz;

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
		    xx = (float)(cx[0]*d[0] + cx[1]*d[1] + cx[2]*d[2]
					   + cx[3]*d[3] + cx[4]*d[4] + cx[5]*d[5]
					   + cx[6]*d[6] + cx[7]*d[7] + cx[8]*d[8]);
			yy = (float)(cy[0]*d[0] + cy[1]*d[1] + cy[2]*d[2]
					   + cy[3]*d[3] + cy[4]*d[4] + cy[5]*d[5]
					   + cy[6]*d[6] + cy[7]*d[7] + cy[8]*d[8]);
			zz = (float)(amp*sqrt(xx*xx+yy*yy));
			dat = (int)zz;
			if(dat > 255) dat = 255;
			image_out[i][j] = (char)dat;
		}
	}
}
