#include	<math.h>
#include	"Params.h"

void param_pers(float k[9], float a, float b, float x0, 
	float y0, float z0, float z, float x, float y, float t, float s);
void matrix(double l[4][4], double m[4][4], double n[4][4]);

/*--- perspect --- �����ϊ��i���`��Ԗ@�j--------------------------------------
	image_in:	���͉摜�z��
	image_out:	�o�͉摜�z��
	ax:			�g�嗦�i���j
	ay:			�g�嗦�i�c�j
	px:			�ړ��ʁi���j
	py:			�ړ��ʁi���j
	pz:			�ړ��ʁi���j
	rz:			��]�p�i���x�j
	rx:			��]�p�i���x�j
	ry:			��]�p�i���x�j
	v:			���_�̈ʒu�i���j
	s:			�X�N���[���̈ʒu�i���j
-----------------------------------------------------------------------------*/
void perspect(unsigned char image_in[Y_SIZE][X_SIZE], 
	unsigned char image_out[Y_SIZE][X_SIZE], float ax, float ay, 
	float px, float py, float pz, float rz, 
	float rx, float ry, float v, float s)
{
	int	i, j, m, n;
	float	x, y, w, p, q;
	float	k[9];
	int	xs = X_SIZE/2;
	int	ys = Y_SIZE/2;
	int     d;

	param_pers(k,ax,ay,px,py,pz,rz,rx,ry,v,s); /* �ϊ��p�����[�^���� */
	for (i = -ys; i < ys; i++) {
		for (j = -xs; j < xs; j++) {
			w = k[0]*j + k[1]*i + k[2];
			x = k[3]*j + k[4]*i + k[5];
			y = k[6]*j + k[7]*i + k[8];
			x = x/w;
			y = y/w;
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

/*--- param_pers --- �����ϊ��̃p�����[�^�v�Z ---------------------------------
	k:		�ϊ��p�����[�^
	a:		�g�嗦�i�������j
	b:		�g�嗦�i�������j
	x0:		�ړ��ʁi�������j
	y0:		�ړ��ʁi�������j
	z0:		�ړ��ʁi�������j
	z:		��]�p�i�������C�x�j
	x:		��]�p�i�������C�x�j
	y:		��]�p�i�������C�x�j
	t:		���_�̈ʒu�i�������j
	s:		�X�N���[���̈ʒu�i�������j
-----------------------------------------------------------------------------*/
void param_pers(float k[9], float a, float b, float x0, 
	float y0, float z0, float z, float x, float y, float t, float s)
{
	double	l[4][4],m[4][4],n[4][4];
	float	k1,k2,k3,k4,k5,k6,k7,k8,k9;
	double	u,v,w;
	int	xs = X_SIZE/2;
	//int	ys = Y_SIZE/2;	//unused?

	u=x*3.141592/180.0;	v=y*3.141592/180.0;	w=z*3.141592/180.0;
	l[0][0]= 1.0/xs;  l[0][1]= 0;       l[0][2]= 0;        l[0][3]= 0;
	l[1][0]= 0;       l[1][1]= -1.0/xs; l[1][2]= 0;        l[1][3]= 0;
	l[2][0]= 0;       l[2][1]= 0;       l[2][2]= 1;        l[2][3]= 0;
	l[3][0]= 0;       l[3][1]= 0;       l[3][2]= 0;        l[3][3]= 1;
	m[0][0]= a;       m[0][1]= 0;       m[0][2]= 0;        m[0][3]= 0;
	m[1][0]= 0;       m[1][1]= b;       m[1][2]= 0;        m[1][3]= 0;
	m[2][0]= 0;       m[2][1]= 0;       m[2][2]= 1;        m[2][3]= 0;
	m[3][0]= 0;       m[3][1]= 0;       m[3][2]= 0;        m[3][3]= 1;
	matrix(l,m,n);	/* ���K���}�g���b�N�X �~ �g��k���}�g���b�N�X */
	l[0][0]= 1;       l[0][1]= 0;       l[0][2]= 0;        l[0][3]= 0;
	l[1][0]= 0;       l[1][1]= 1;       l[1][2]= 0;        l[1][3]= 0;
	l[2][0]= 0;       l[2][1]= 0;       l[2][2]= 1;        l[2][3]= 0;
	l[3][0]= x0;      l[3][1]= y0;      l[3][2]= z0;       l[3][3]= 1;
	matrix(n,l,m);	/* �~ �ړ��}�g���b�N�X */
	n[0][0]=  cos(w); n[0][1]= sin(w);  n[0][2]= 0;        n[0][3]= 0;
	n[1][0]= -sin(w); n[1][1]= cos(w);  n[1][2]= 0;        n[1][3]= 0;
	n[2][0]= 0;       n[2][1]= 0;       n[2][2]= 1;        n[2][3]= 0;
	n[3][0]= 0;       n[3][1]= 0;       n[3][2]= 0;        n[3][3]= 1;
	matrix(m,n,l);	/* �~ �����̉�]�}�g���b�N�X */
	m[0][0]= 1;       m[0][1]= 0;       m[0][2]= 0;       m[0][3]= 0;
	m[1][0]= 0;       m[1][1]= cos(u);  m[1][2]= sin(u);  m[1][3]= 0;
	m[2][0]= 0;       m[2][1]= -sin(u); m[2][2]= cos(u);  m[2][3]= 0;
	m[3][0]= 0;       m[3][1]= 0;       m[3][2]= 0;       m[3][3]= 1;
	matrix(l,m,n);	/* �~ �����̉�]�}�g���b�N�X */
	l[0][0]= cos(v);  l[0][1]= 0;       l[0][2]= sin(v);  l[0][3]= 0;
	l[1][0]= 0;       l[1][1]= 1;       l[1][2]= 0;       l[1][3]= 0;
	l[2][0]= -sin(v); l[2][1]= 0;       l[2][2]= cos(v);  l[2][3]= 0;
	l[3][0]= 0;       l[3][1]= 0;       l[3][2]= 0;       l[3][3]= 1;
	matrix(n,l,m);	/* �~ �����̉�]�}�g���b�N�X */
	n[0][0]= 1;       n[0][1]= 0;       n[0][2]= 0;       n[0][3]= 0;
	n[1][0]= 0;       n[1][1]= 1;       n[1][2]= 0;       n[1][3]= 0;
	n[2][0]= 0;       n[2][1]= 0;       n[2][2]= -1;      n[2][3]= 0;
	n[3][0]= 0;       n[3][1]= 0;       n[3][2]= t;       n[3][3]= 1;
	matrix(m,n,l);	/* �~ ���_���W�ϊ��}�g���b�N�X */
	m[0][0]= 1;       m[0][1]= 0;       m[0][2]= 0;       m[0][3]= 0;
	m[1][0]= 0;       m[1][1]= 1;       m[1][2]= 0;       m[1][3]= 0;
	m[2][0]= 0;       m[2][1]= 0;       m[2][2]= 1/s;     m[2][3]= 1/s;
	m[3][0]= 0;       m[3][1]= 0;       m[3][2]= -1;      m[3][3]= 0;
	matrix(l,m,n);	/* �~ �����ϊ��}�g���b�N�X */
	l[0][0]= xs;      l[0][1]= 0;       l[0][2]= 0;       l[0][3]= 0;
	l[1][0]= 0;       l[1][1]= -xs;     l[1][2]= 0;       l[1][3]= 0;
	l[2][0]= 0;       l[2][1]= 0;       l[2][2]= 1;       l[2][3]= 0;
	l[3][0]= 0;       l[3][1]= 0;       l[3][2]= 0;       l[3][3]= 1;
	matrix(n,l,m);	/* �~ ���K���t�}�g���b�N�X */
	k1=(float)(m[0][3]);	k2=(float)(m[1][3]);	k3=(float)(m[3][3]);
	k4=(float)(m[0][0]);	k5=(float)(m[1][0]);	k6=(float)(m[3][0]);
	k7=(float)(m[0][1]);	k8=(float)(m[1][1]);	k9=(float)(m[3][1]);
	k[0]=k7*k2-k8*k1; k[1]=k5*k1-k4*k2; k[2]=k4*k8-k7*k5;
	k[3]=k8*k3-k9*k2; k[6]=k9*k1-k7*k3; k[4]=k6*k2-k5*k3;
	k[7]=k4*k3-k6*k1; k[5]=k5*k9-k8*k6; k[8]=k7*k6-k4*k9;
}

/*--- matrix --- �}�g���b�N�X�v�Z ---------------------------------------------
	l:	���̓}�g���b�N�X�P
	m:	���̓}�g���b�N�X�Q
	n:	�o�̓}�g���b�N�X
-----------------------------------------------------------------------------*/
void matrix(double l[4][4], double m[4][4], double n[4][4])
{
	int		i, j, k;
	double	p;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			p = 0;
			for (k = 0; k < 4; k++) p = p + l[i][k]*m[k][j];
			n[i][j] = p;
		}
	}
}
