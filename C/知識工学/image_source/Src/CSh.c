#include <math.h>
#include "Params.h"

#define	PI			3.141592
#define	THRESHOLD	0.0			/* 彩度の有無を判断する閾値		*/
#define	NONE		0.0			/* 彩度がない場合に代入する値	*/

/*---- c_to_sh --- 色差信号から彩度,色相を計算する ----------------------------
	c1:		入力データ配列Ｒ－Ｙ
	c2:		入力データ配列Ｂ－Ｙ
	sat:	彩度のデータ配列
	hue:	色相のデータ配列
-----------------------------------------------------------------------------*/
void c_to_sh(int c1[Y_SIZE][X_SIZE], int c2[Y_SIZE][X_SIZE], 
	int sat[Y_SIZE][X_SIZE], int hue[Y_SIZE][X_SIZE])
{
	int		i, j;
	float	fhue, length;

	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			length =(float)c1[i][j] * (float)c1[i][j]
					+(float)c2[i][j] * (float)c2[i][j];
			sat[i][j] = (int)(sqrt((double)length));

			if ((sat[i][j]) > THRESHOLD){
				fhue = (float)(atan2((double)c1[i][j], (double)c2[i][j]) *
						180.0 / PI);
				if (fhue < 0 ) fhue = fhue + (float)360.0;
				hue[i][j] = (int)fhue;
				}
			else hue[i][j] = (int)NONE; /* 彩度が閾値以下の時 */
		}
	}
}

/*--- sh_to_c --- 彩度,色相から色差信号を計算する -----------------------------
	c1:		入力データ配列Ｒ－Ｙ
	c2:		入力データ配列Ｂ－Ｙ
	sat:	彩度のデータ配列
	hue:	色相のデータ配列
-----------------------------------------------------------------------------*/
void sh_to_c(int sat[Y_SIZE][X_SIZE], int hue[Y_SIZE][X_SIZE], 
	int c1[Y_SIZE][X_SIZE], int c2[Y_SIZE][X_SIZE])
{
	int		i, j;
	float	rad;

	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			rad = (float)(PI * hue[i][j] / 180.0);
			c1[i][j] = (int)(sat[i][j] * sin((double)rad));
			c2[i][j] = (int)(sat[i][j] * cos((double)rad));
		}
	}
}
