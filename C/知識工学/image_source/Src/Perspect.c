#include	<math.h>
#include	"Params.h"

void param_pers(float k[9], float a, float b, float x0, 
	float y0, float z0, float z, float x, float y, float t, float s);
void matrix(double l[4][4], double m[4][4], double n[4][4]);

/*--- perspect --- 透視変換（線形補間法）--------------------------------------
	image_in:	入力画像配列
	image_out:	出力画像配列
	ax:			拡大率（横）
	ay:			拡大率（縦）
	px:			移動量（ｘ）
	py:			移動量（ｙ）
	pz:			移動量（ｚ）
	rz:			回転角（ｚ度）
	rx:			回転角（ｘ度）
	ry:			回転角（ｙ度）
	v:			視点の位置（ｚ）
	s:			スクリーンの位置（ｚ）
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

	param_pers(k,ax,ay,px,py,pz,rz,rx,ry,v,s); /* 変換パラメータ決定 */
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

/*--- param_pers --- 透視変換のパラメータ計算 ---------------------------------
	k:		変換パラメータ
	a:		拡大率（ｘ方向）
	b:		拡大率（ｙ方向）
	x0:		移動量（ｘ方向）
	y0:		移動量（ｙ方向）
	z0:		移動量（ｚ方向）
	z:		回転角（ｚ方向，度）
	x:		回転角（ｘ方向，度）
	y:		回転角（ｙ方向，度）
	t:		視点の位置（ｚ方向）
	s:		スクリーンの位置（ｚ方向）
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
	matrix(l,m,n);	/* 正規化マトリックス × 拡大縮小マトリックス */
	l[0][0]= 1;       l[0][1]= 0;       l[0][2]= 0;        l[0][3]= 0;
	l[1][0]= 0;       l[1][1]= 1;       l[1][2]= 0;        l[1][3]= 0;
	l[2][0]= 0;       l[2][1]= 0;       l[2][2]= 1;        l[2][3]= 0;
	l[3][0]= x0;      l[3][1]= y0;      l[3][2]= z0;       l[3][3]= 1;
	matrix(n,l,m);	/* × 移動マトリックス */
	n[0][0]=  cos(w); n[0][1]= sin(w);  n[0][2]= 0;        n[0][3]= 0;
	n[1][0]= -sin(w); n[1][1]= cos(w);  n[1][2]= 0;        n[1][3]= 0;
	n[2][0]= 0;       n[2][1]= 0;       n[2][2]= 1;        n[2][3]= 0;
	n[3][0]= 0;       n[3][1]= 0;       n[3][2]= 0;        n[3][3]= 1;
	matrix(m,n,l);	/* × ｚ軸の回転マトリックス */
	m[0][0]= 1;       m[0][1]= 0;       m[0][2]= 0;       m[0][3]= 0;
	m[1][0]= 0;       m[1][1]= cos(u);  m[1][2]= sin(u);  m[1][3]= 0;
	m[2][0]= 0;       m[2][1]= -sin(u); m[2][2]= cos(u);  m[2][3]= 0;
	m[3][0]= 0;       m[3][1]= 0;       m[3][2]= 0;       m[3][3]= 1;
	matrix(l,m,n);	/* × ｘ軸の回転マトリックス */
	l[0][0]= cos(v);  l[0][1]= 0;       l[0][2]= sin(v);  l[0][3]= 0;
	l[1][0]= 0;       l[1][1]= 1;       l[1][2]= 0;       l[1][3]= 0;
	l[2][0]= -sin(v); l[2][1]= 0;       l[2][2]= cos(v);  l[2][3]= 0;
	l[3][0]= 0;       l[3][1]= 0;       l[3][2]= 0;       l[3][3]= 1;
	matrix(n,l,m);	/* × ｙ軸の回転マトリックス */
	n[0][0]= 1;       n[0][1]= 0;       n[0][2]= 0;       n[0][3]= 0;
	n[1][0]= 0;       n[1][1]= 1;       n[1][2]= 0;       n[1][3]= 0;
	n[2][0]= 0;       n[2][1]= 0;       n[2][2]= -1;      n[2][3]= 0;
	n[3][0]= 0;       n[3][1]= 0;       n[3][2]= t;       n[3][3]= 1;
	matrix(m,n,l);	/* × 視点座標変換マトリックス */
	m[0][0]= 1;       m[0][1]= 0;       m[0][2]= 0;       m[0][3]= 0;
	m[1][0]= 0;       m[1][1]= 1;       m[1][2]= 0;       m[1][3]= 0;
	m[2][0]= 0;       m[2][1]= 0;       m[2][2]= 1/s;     m[2][3]= 1/s;
	m[3][0]= 0;       m[3][1]= 0;       m[3][2]= -1;      m[3][3]= 0;
	matrix(l,m,n);	/* × 透視変換マトリックス */
	l[0][0]= xs;      l[0][1]= 0;       l[0][2]= 0;       l[0][3]= 0;
	l[1][0]= 0;       l[1][1]= -xs;     l[1][2]= 0;       l[1][3]= 0;
	l[2][0]= 0;       l[2][1]= 0;       l[2][2]= 1;       l[2][3]= 0;
	l[3][0]= 0;       l[3][1]= 0;       l[3][2]= 0;       l[3][3]= 1;
	matrix(n,l,m);	/* × 正規化逆マトリックス */
	k1=(float)(m[0][3]);	k2=(float)(m[1][3]);	k3=(float)(m[3][3]);
	k4=(float)(m[0][0]);	k5=(float)(m[1][0]);	k6=(float)(m[3][0]);
	k7=(float)(m[0][1]);	k8=(float)(m[1][1]);	k9=(float)(m[3][1]);
	k[0]=k7*k2-k8*k1; k[1]=k5*k1-k4*k2; k[2]=k4*k8-k7*k5;
	k[3]=k8*k3-k9*k2; k[6]=k9*k1-k7*k3; k[4]=k6*k2-k5*k3;
	k[7]=k4*k3-k6*k1; k[5]=k5*k9-k8*k6; k[8]=k7*k6-k4*k9;
}

/*--- matrix --- マトリックス計算 ---------------------------------------------
	l:	入力マトリックス１
	m:	入力マトリックス２
	n:	出力マトリックス
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
