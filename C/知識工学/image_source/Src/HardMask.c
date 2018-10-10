#include  "Params.h"

/*--- hard_mask --- 合成キー（ハードキー）の生成 ------------------------------
	image_in_r:	入力Ｒ画像
	image_in_g:	入力Ｇ画像
	image_in_b:	入力Ｒ画像
	image_key:	入力Ｂ画像
	thresh:		閾値
-----------------------------------------------------------------------------*/
void hard_mask(unsigned char image_in_r[Y_SIZE][X_SIZE], 
	unsigned char image_in_g[Y_SIZE][X_SIZE], 
	unsigned char image_in_b[Y_SIZE][X_SIZE], 
	unsigned char image_key[Y_SIZE][X_SIZE], int thresh)
{
	int   i, j, d;
	
	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			d = ((int)image_in_r[i][j] + (int)image_in_g[i][j]) / 2
				- (int)image_in_b[i][j];
			if (d >= thresh) image_key[i][j] = 255;
			else             image_key[i][j] = 0;
		}
	}
}
