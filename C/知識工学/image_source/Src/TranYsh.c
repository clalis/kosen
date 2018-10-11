#include "Params.h"

/*--- tran_ysh --- 輝度,彩度,色相を変える -------------------------------------
	in_y:		入力データ配列　  Ｙ
	in_sat:		入力データ配列　ＳＡＴ
	in_hue:		入力データ配列　ＨＵＥ
	out_y:		出力データ配列　  Ｙ
	out_sat:	出力データ配列　ＳＡＴ
	out_hue:	出力データ配列　ＨＵＥ
	ym:			輝度の乗数
	sm:			彩度の乗数
	hd:			色相の増分
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
