#include "Params.h"

int	cconc(int inb[9] );

/*--- thinning --- ２値画像を細線化する ---------------------------------------
	image_in:	入力画像配列
	image_out:	出力画像配列
-----------------------------------------------------------------------------*/
void thinning(unsigned char	image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE])
{
	int	ia[9], ic[9], i, ix, iy, m, ir, iv, iw;

	for (iy = 0; iy < Y_SIZE; iy++)
		for (ix = 0; ix < X_SIZE; ix++)
			image_out[iy][ix] = image_in[iy][ix];
	m = 100; ir = 1 ;
	while (ir != 0) {
		ir = 0;
		for (iy = 1; iy < Y_SIZE-1; iy++)
			for (ix = 1; ix < X_SIZE-1; ix++) {
				if (image_out[iy][ix] != HIGH) continue;
				ia[0] = image_out[iy  ][ix+1];
	  			ia[1] = image_out[iy-1][ix+1];
				ia[2] = image_out[iy-1][ix  ];
			  	ia[3] = image_out[iy-1][ix-1];
			  	ia[4] = image_out[iy  ][ix-1];
			  	ia[5] = image_out[iy+1][ix-1];
			  	ia[6] = image_out[iy+1][ix  ];
			  	ia[7] = image_out[iy+1][ix+1];
				for (i = 0; i < 8; i++) {
					if (ia[i] == m) {
						ia[i] = HIGH; ic[i] = 0;
					}
					else {
						if (ia[i] < HIGH) ia[i] = 0;
						ic[i] = ia[i];
					}
				}
				ia[8] = ia[0]; ic[8] = ic[0];
				if (ia[0]+ia[2]+ia[4]+ia[6] == HIGH*4) continue;
				for (i = 0, iv = 0, iw = 0; i < 8; i++) {
					if (ia[i] == HIGH) iv++;
					if (ic[i] == HIGH) iw++;
				}
				if (iv <= 1) continue;
				if (iw == 0) continue;
				if (cconc(ia) != 1) continue;
              	if (image_out[iy-1][ix] == m) {
					ia[2] = 0;
					if (cconc(ia) != 1) continue;
					ia[2] = HIGH;
				}
				if (image_out[iy][ix-1] == m) {
					ia[4] = 0;
					if (cconc(ia) != 1) continue;
					ia[4] = HIGH;
				}
				image_out[iy][ix] = m; ir++;
			}
		m++;
	}
	for (iy = 0; iy < Y_SIZE; iy++)
		for (ix = 0; ix < X_SIZE; ix++)
			if (image_out[iy][ix] < HIGH) image_out[iy][ix] = 0;
}

/*--- cconc --- 連結性（連結数）を調べる --------------------------------------
	inb:	入力画素
-----------------------------------------------------------------------------*/
int	cconc(int inb[9])
{          
	int	i, icn;
	icn = 0;

	for (i = 0; i < 8; i += 2)
		if (inb[i] == 0)
		if (inb[i+1] == HIGH || inb[i+2] == HIGH)
		icn++;
		return icn;
}
