#include <math.h>
#include "Params.h"

#define	PI			3.141592
#define	THRESHOLD	0.0			/* �ʓx�̗L���𔻒f����臒l		*/
#define	NONE		0.0			/* �ʓx���Ȃ��ꍇ�ɑ������l	*/

/*---- c_to_sh --- �F���M������ʓx,�F�����v�Z���� ----------------------------
	c1:		���̓f�[�^�z��q�|�x
	c2:		���̓f�[�^�z��a�|�x
	sat:	�ʓx�̃f�[�^�z��
	hue:	�F���̃f�[�^�z��
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
			else hue[i][j] = (int)NONE; /* �ʓx��臒l�ȉ��̎� */
		}
	}
}

/*--- sh_to_c --- �ʓx,�F������F���M�����v�Z���� -----------------------------
	c1:		���̓f�[�^�z��q�|�x
	c2:		���̓f�[�^�z��a�|�x
	sat:	�ʓx�̃f�[�^�z��
	hue:	�F���̃f�[�^�z��
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
