#include "Params.h"

/*---- colorbar --- カラーバーを作る ------------------------------------------
	image_r:	出力画像配列　Ｒ
	image_g:	出力画像配列　Ｇ
	image_b:	出力画像配列　Ｂ
	level:		濃度値
-----------------------------------------------------------------------------*/
void colorbar(unsigned char image_r[Y_SIZE][X_SIZE], 
	unsigned char image_g[Y_SIZE][X_SIZE], 
	unsigned char image_b[Y_SIZE][X_SIZE], int level)
{
	int     i, j, width;

	width = X_SIZE / 8;
	for (i = 0; i < Y_SIZE; i++){
		for (j = 0; j < X_SIZE; j++){
			if (((j >= 0) && (j < 2*width)) ||  /* Ｒプレーン */
					((j >= 4*width) && (j < 6*width)))
				image_r[i][j] = level;
			else image_r[i][j] = 0;
			if ((j >= 0) && (j < 4*width ))     /* Ｇプレーン */
				image_g[i][j] = level;
			else image_g[i][j] = 0;
			if (((j >= 0) && (j < width )) ||   /* Ｂプレーン */
					((j >= 2*width) && (j < 3*width)) ||
					((j >= 4*width) && (j < 5*width)) ||
					((j >= 6*width) && (j < 7*width)))
				image_b[i][j] = level;
			else image_b[i][j] = 0;
		}
	}
}
