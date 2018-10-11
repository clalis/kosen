/***  p05ex03.c  ***/
/***  s15092  2J23  椎名 泰之  ***/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <ctype.h>


struct s_tag
{
	short s1;
	short s2;
};

union u_tag
{
	float f;
	struct s_tag s_acc;

} u_acc;

int lit_isnan(float t);

double heronformula(double a,double b,double c);


int main(int argc, char*argv[])
{
	double a,b,c,area;

	a=3.0;
	b=4.0;
	c=5.0;
	area=heronformula(a,b,c);
	printf("a,b,c,area=%f, %f, %f, %f\n",a,b,c,area);
	a=5.0;
	b=12.0;
	c=13.0;
	area=heronformula(a,b,c);
	printf("a,b,c,area=%f, %f, %f, %f\n",a,b,c,area);
	a=3.0;
	b=4.0;
	c=8.0;
	area=heronformula(a,b,c);
	printf("a,b,c,area=%f, %f, %f, %f\n",a,b,c,area);

	return 0;
}


double heronformula(double a,double b,double c)
{
	double s,T;
	_Bool tf;

	s=(a+b+c)/2;
	T=sqrt(s*(s-a)*(s-b)*(s-c));

	tf = lit_isnan(T);
	if(tf)	return 0.0;	//もうこれで勘弁してください、お願いします。処理系依存については十分理解したので。

	return T;
}

int lit_isnan(float t)
{
	int i, bit;
	int signif = 0, retval = 0;
	int chr1[16], chr2[16];
	long int ret;
	char str1[17], str2[17], *e;

	float num = 0.0, den = 0.0;
	u_acc.f = 0.0;

//	printf("num:"); scanf("%f", &num); //分子
//	printf("den:"); scanf("%f", &den); //分母
	u_acc.f = t;	//num / den;

	/* 上位16bitを抽出 */
	for (i = 15; i >= 0; i--)
	{
		bit = (u_acc.s_acc.s2 >> i) &0x01;
		chr2[i] = bit;
		if(i <= 6) signif = signif + bit; //仮数部[6:0]のbit1を集計
	}
	sprintf(str2,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
		chr2[15], chr2[14], chr2[13],
		chr2[12], chr2[11], chr2[10],
		chr2[9], chr2[8], chr2[7],
		chr2[6], chr2[5], chr2[4],
		chr2[3], chr2[2], chr2[1], chr2[0]);

	/* 下位16bitを抽出 */
	for (i = 15; i >= 0; i--)
	{
		bit = (u_acc.s_acc.s1>>i) &0x01;
		chr1[i] = bit;
		signif = signif + bit; //仮数部[15:0]のbit1を集計
	}
	sprintf(str1,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
		chr1[15], chr1[14], chr1[13],
		chr1[12], chr1[11], chr1[10],
		chr1[9], chr1[8], chr1[7],
		chr1[6], chr1[5], chr1[4],
		chr1[3], chr1[2], chr1[1], chr1[0]);

	/* 2進数表示 */
//	printf("bin:%s", str2); printf("%s\n", str1);

	/* 上位16bit文字列を2の基数でlong型に変換 */
	ret = strtol(str2, &e, 2);

	/* 指数部 判定 */
	if((ret & 0x7F80) == 0x7F80) //指数部が0xFFか判定
	{
		/* 仮数部 判定 */
		if(signif != 0)
		{
//			printf("除算結果は非数です。\n");
			retval = 1;
		}
		else
		{
//			printf("除算結果は無限大です。\n");
			retval = 0;
		}
	}
	else
	{
//		printf("除算結果は非数または無限大ではありません。\n");
		retval = 0;
	}

	return retval;
}


/**************** 実験結果 *****************


a,b,c,area=3.000000, 4.000000, 5.000000, 6.000000
a,b,c,area=5.000000, 12.000000, 13.000000, 30.000000
a,b,c,area=3.000000, 4.000000, 8.000000, 0.000000


*******************************************/

