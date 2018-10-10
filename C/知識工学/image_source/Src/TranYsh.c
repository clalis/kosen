#include "Params.h"

/*--- tran_ysh --- �P�x,�ʓx,�F����ς��� -------------------------------------
	in_y:		���̓f�[�^�z��@  �x
	in_sat:		���̓f�[�^�z��@�r�`�s
	in_hue:		���̓f�[�^�z��@�g�t�d
	out_y:		�o�̓f�[�^�z��@  �x
	out_sat:	�o�̓f�[�^�z��@�r�`�s
	out_hue:	�o�̓f�[�^�z��@�g�t�d
	ym:			�P�x�̏搔
	sm:			�ʓx�̏搔
	hd:			�F���̑���
-----------------------------------------------------------------------------*/
void tran_ysh(int in_y[Y_SIZE][X_SIZE], int in_sat[Y_SIZE][X_SIZE], 
	int in_hue[Y_SIZE][X_SIZE], int out_y[Y_SIZE][X_SIZE], 
	int out_sat[Y_SIZE][X_SIZE], int out_hue[Y_SIZE][X_SIZE], 
	float ym, float sm, float hd)
{
	int i, j;

	for (i = 0; i < Y_SIZE; i++){
		for (j = 0; j < X_SIZE; j++){
			out_y[i][j]   = (int)(in_y[i][j] * ym);
			out_sat[i][j] = (int)(in_sat[i][j] * sm);
			out_hue[i][j] = (int)(in_hue[i][j] + hd);
			if(out_hue[i][j]>360) out_hue[i][j] = out_hue[i][j] - 360;
			if(out_hue[i][j]<  0) out_hue[i][j] = out_hue[i][j] + 360;
		}
	}
}
