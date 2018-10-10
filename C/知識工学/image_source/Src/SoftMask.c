#include  "Params.h"

/*--- soft_mask --- 合成用キー（ソフトキー）の生成 ----------------------------
	image_in_r:		入力Ｒ画像
	image_in_g:		入力Ｇ画像
	image_in_b:		入力Ｂ画像
	image_key:		合成用キー画像
	thdh, thdl:		閾値 (max,min) 
-----------------------------------------------------------------------------*/
void soft_mask(unsigned char image_in_r[Y_SIZE][X_SIZE], 
	unsigned char image_in_g[Y_SIZE][X_SIZE], 
	unsigned char image_in_b[Y_SIZE][X_SIZE],
	unsigned char image_key[Y_SIZE][X_SIZE], int thdh, int thdl)
{
	int 	i, j, d;
	int 	kk;

	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
        	d = ((int)image_in_r[i][j] + (int)image_in_g[i][j]) / 2
               - (int)image_in_b[i][j];
            kk = ((long)(d - thdl) * 255 / (thdh - thdl));
            if (kk > 255)		image_key[i][j] = 255;
            else if (kk < 0) 	image_key[i][j] = 0;
			else				image_key[i][j] = kk;
		}
	}
}
