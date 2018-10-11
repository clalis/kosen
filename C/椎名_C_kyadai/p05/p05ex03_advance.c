/***  p05ex03.c  ***/
/***  s15092  2J23  �Ŗ� �הV  ***/

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
	if(tf)	return 0.0;	//��������Ŋ��ق��Ă��������A���肢���܂��B�����n�ˑ��ɂ��Ă͏\�����������̂ŁB

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

//	printf("num:"); scanf("%f", &num); //���q
//	printf("den:"); scanf("%f", &den); //����
	u_acc.f = t;	//num / den;

	/* ���16bit�𒊏o */
	for (i = 15; i >= 0; i--)
	{
		bit = (u_acc.s_acc.s2 >> i) &0x01;
		chr2[i] = bit;
		if(i <= 6) signif = signif + bit; //������[6:0]��bit1���W�v
	}
	sprintf(str2,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
		chr2[15], chr2[14], chr2[13],
		chr2[12], chr2[11], chr2[10],
		chr2[9], chr2[8], chr2[7],
		chr2[6], chr2[5], chr2[4],
		chr2[3], chr2[2], chr2[1], chr2[0]);

	/* ����16bit�𒊏o */
	for (i = 15; i >= 0; i--)
	{
		bit = (u_acc.s_acc.s1>>i) &0x01;
		chr1[i] = bit;
		signif = signif + bit; //������[15:0]��bit1���W�v
	}
	sprintf(str1,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
		chr1[15], chr1[14], chr1[13],
		chr1[12], chr1[11], chr1[10],
		chr1[9], chr1[8], chr1[7],
		chr1[6], chr1[5], chr1[4],
		chr1[3], chr1[2], chr1[1], chr1[0]);

	/* 2�i���\�� */
//	printf("bin:%s", str2); printf("%s\n", str1);

	/* ���16bit�������2�̊��long�^�ɕϊ� */
	ret = strtol(str2, &e, 2);

	/* �w���� ���� */
	if((ret & 0x7F80) == 0x7F80) //�w������0xFF������
	{
		/* ������ ���� */
		if(signif != 0)
		{
//			printf("���Z���ʂ͔񐔂ł��B\n");
			retval = 1;
		}
		else
		{
//			printf("���Z���ʂ͖�����ł��B\n");
			retval = 0;
		}
	}
	else
	{
//		printf("���Z���ʂ͔񐔂܂��͖�����ł͂���܂���B\n");
		retval = 0;
	}

	return retval;
}


/**************** �������� *****************


a,b,c,area=3.000000, 4.000000, 5.000000, 6.000000
a,b,c,area=5.000000, 12.000000, 13.000000, 30.000000
a,b,c,area=3.000000, 4.000000, 8.000000, 0.000000


*******************************************/

