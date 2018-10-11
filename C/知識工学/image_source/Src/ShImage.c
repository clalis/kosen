#include <math.h>
#include "Params.h"

/*--- sat_image --- �ʓx�f�[�^��Z�W�摜������ --------------------------------
	sat:		�ʓx�̃f�[�^�z��
	image_out:	�o�͉摜�z��
-----------------------------------------------------------------------------*/
int sat_image(int sat[Y_SIZE][X_SIZE], unsigned char image_out[Y_SIZE][X_SIZE])
{
	int i, j;
	int min, max;
	int isat;

	min = 255;
	max = 0;
	for (i = 0; i < Y_SIZE; i++){
		for (j = 0; j < X_SIZE; j++ ){
			if (sat[i][j] > max) max = sat[i][j];
			if (sat[i][j] < min) min = sat[i][j];
		}
	}
	if (min == max) return -1;
	for (i = 0; i < Y_SIZE; i++){
		for (j = 0; j < X_SIZE; j++ ){
			isat = 255 * (sat[i][j] - min) / (max - min);
			image_out[i][j] = (unsigned char)(isat);
		}
	}
	return 0;
}

/*--- hue_image --- �F���f�[�^���摜������ ------------------------------------
	sat:		�ʓx�̃f�[�^�z��
	hue:		�F���̃f�[�^�z��
	stdhue:		��ƂȂ�F���l
	image_out:	�o�͉摜�z��
-----------------------------------------------------------------------------*/
void hue_image(int sat[Y_SIZE][X_SIZE], int hue[Y_SIZE][X_SIZE], 
	float stdhue, unsigned char image_out[Y_SIZE][X_SIZE])
{
	int		i, j;
	int		ihue;
	float	delt;

	for (i = 0; i < Y_SIZE; i++){
		for (j = 0; j < X_SIZE; j++){
			if (sat[i][j] > 0){
				delt = (float)(fabs((double)hue[i][j] - (double)stdhue));
				if (delt > 180.0) delt = (float)360.0 - delt;
				ihue = (int)(255.0 - delt * 255.0 / 180.0);
				image_out[i][j] = (unsigned char)ihue;
			}
			else image_out[i][j]=0;
		}
	}
}
