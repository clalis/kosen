#include	<math.h>
#include	"Params.h"

#define PI	3.141592

/*--- affine --- �g��k��,��],�ړ��i���`��Ԗ@�j------------------------------
	image_in:	���͉摜�z��
	image_out:	�o�͉摜�z��
	deg:		��]�p�i�x�j
	zx:			�g�嗦�i���j
	zy:			�g�嗦�i�c�j
	px:			�ړ��ʁi���j
	py:			�ړ��ʁi�c�j
-----------------------------------------------------------------------------*/
void affine(unsigned char image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE], 
	float deg, float zx, float zy, float px, float py)
{
	int	i, j, m, n;
	float	x, y, u, v, p, q;
	double	r;
	float	c, s;
	int	xs = X_SIZE/2;
	int	ys = Y_SIZE/2;
	int	d;

	r = deg*PI/180.0;
	c = (float)cos(r);
	s = (float)sin(r);
	for (i = -ys; i < ys; i++) {
		for (j = -xs; j < xs; j++) {
			v = i - py;
			u = j - px;
			y = (u*s + v*c) / zy;
			x = (u*c - v*s) / zx;
			if (y > 0) m = (int)y;
			else m = (int)(y-1);
			if (x > 0) n = (int)x;
			else n = (int)(x-1);
			q = y - m;
			p = x - n;
			if ( (m >= -ys) && (m < ys) && (n >= -xs) && (n < xs) )
				d = (int)((1.0-q)*((1.0-p)*image_in[m  +ys][n  +xs]
				                       + p*image_in[m  +ys][n+1+xs])
				              + q*((1.0-p)*image_in[m+1+ys][n  +xs]
				                       + p*image_in[m+1+ys][n+1+xs]));
			else
				d = 0;
			if (d <   0) d =   0;
			if (d > 255) d = 255;
			image_out[i+ys][j+xs] = d;
		}
	}
}
