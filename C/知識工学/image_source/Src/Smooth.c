#include	"Params.h"

/*--- smooth --- �ړ����ϖ@�ɂ��m�C�Y���� -----------------------------------
	image_in:	���͉摜�z��
	image_out:	�o�͉摜�z��
-----------------------------------------------------------------------------*/
void smooth(unsigned char image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE])
{
	int             i, j, buf;
                    
   	for (i = 1; i < Y_SIZE-1; i++) {
		for (j = 1; j < X_SIZE-1; j++) {
			buf = (int)image_in[i-1][j-1]
				+ (int)image_in[i-1][j]
				+ (int)image_in[i-1][j+1]
				+ (int)image_in[i][j-1]
				+ (int)image_in[i][j]
				+ (int)image_in[i][j+1]
				+ (int)image_in[i+1][j-1]
				+ (int)image_in[i+1][j]
				+ (int)image_in[i+1][j+1];
			image_out[i][j] = buf / 9;
		}
	}
}
