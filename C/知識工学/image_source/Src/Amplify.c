#include "Params.h"

/*--- amplify --- ‰æ‘œ‚Ì–¾‚é‚³‚ğ‚”{‚·‚é --------------------------------------
	image_in:	“ü—Í‰æ‘œ”z—ñ
	image_out:	o—Í‰æ‘œ”z—ñ
	n:			”{—¦
-----------------------------------------------------------------------------*/
void amplify(unsigned char image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE], float n)
{
	int i, j, nf;

	for (i = 0; i < Y_SIZE; i++){
    	for (j = 0; j < X_SIZE; j++){
			nf = (int)(image_in[i][j] * n);
			if (nf > 255) nf = 255;
			image_out[i][j] = (unsigned char)nf;
		}
	}
}
