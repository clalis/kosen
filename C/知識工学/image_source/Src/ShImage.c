#include <math.h>
#include "Params.h"

/*--- sat_image --- 彩度データを濃淡画像化する --------------------------------
	sat:		彩度のデータ配列
	image_out:	出力画像配列
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

/*--- hue_image --- 色相データを画像化する ------------------------------------
	sat:		彩度のデータ配列
	hue:		色相のデータ配列
	stdhue:		基準となる色相値
	image_out:	出力画像配列
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
