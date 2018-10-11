#include "Params.h"

/*--- histsmooth --- �q�X�g�O�����𕽊������� ---------------------------------
	hist_in:	�q�X�g�O���� �������O
	hist_out:	�q�X�g�O���� ��������
-----------------------------------------------------------------------------*/
void histsmooth(long hist_in[256], long hist_out[256])
{
	int  m, n, i;
	long sum;

	for (n = 0; n < 256; n++) {
		sum = 0;
		for (m = -2; m <= 2; m++) {
			i = n + m;
			if (i <   0) i =   0;
			if (i > 255) i = 255;
			sum = sum + hist_in[i];
		}
		hist_out[n] = (long)((float)sum / 5.0 + 0.5);
	}
}
