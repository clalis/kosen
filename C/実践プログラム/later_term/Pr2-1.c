#include <stdio.h>	/* dev-c++�R���p�C���ł́C��L��"<"��">"��"stdio.h"�Ƃ̊ԂɃX�y�[�X�������*/
#include <stdlib.h>	/*�R���p�C�����ɕs����������邱�Ƃ�����̂ŁC�X�y�[�X�͓���Ȃ��悤�� */

#define BF 1
#define KMP 1
#define TAR 1
#define PYOKO 1
#define TEXT_LENGTH 64
#define PATN_LENGTH 16


void init_next(char pattern[]);							/* ���炵�\���쐬���� */
int brute_force_search(char text[], char pattern[]);	/* ������text���當����pattern����������(�͂܂����@) */
int kmp_search(char text[], char pattern[]);			/* ������text���當����pattern����������(KMP�@) */
int next[PATN_LENGTH];

int main(int argc, char *argv[], char *envp[])
{
	char text_tar[TEXT_LENGTH+1];
	char pattern_tar[PATN_LENGTH+1];
	char text_pyoko[TEXT_LENGTH+1];
	char pattern_pyoko[PATN_LENGTH+1];
	int position;

	strcpy(text_tar,"xxxtartartayx");
	strcpy(pattern_tar,"tartay");
	strcpy(text_pyoko,"pyokopyokomipyokopyokomepyokopyokopyokopyokomupyokopyoko");
	strcpy(pattern_pyoko,"pyokopyokomu");

#if TAR
	#if BF
		printf("--- B F ---\n");
		printf("%s\n",text_tar);
		position = brute_force_search(text_tar, pattern_tar);
		printf("position=%d\n",position);
	#endif

	#if KMP
		printf("--- KMP ---\n");
		init_next(pattern);
		printf("%s\n",text_tar);
		position = kmp_search(text_tar, pattern_tar);
		printf("position=%d\n",position);
	#endif
#endif

#if PYOKO
	#if BF
		printf("--- B F ---\n");
		printf("%s\n",text_pyoko);
		position = brute_force_search(text_pyoko, pattern_pyoko);
		printf("position=%d\n",position);
	#endif

	#if KMP
		printf("--- KMP ---\n");
		init_next(pattern);
		printf("%s\n",text_pyoko);
		position = kmp_search(text_pyoko, pattern_pyoko);
		printf("position=%d\n",position);
	#endif
#endif

	return 0;
}

int brute_force_search(char text[], char pattern[])
{
	int i = 0;	/* ���ڂ��Ă���e�L�X�g�̈ʒu */
	int j = 0;	/* ���ڂ��Ă���p�^�[���̈ʒu */
	int text_len, patn_len;

	text_len = strlen(text);	/* �e�L�X�g�̒������Z�b�g */
	patn_len = strlen(pattern);	/* �p�^�[���̒������Z�b�g */

	while ((i < text_len) && (j < patn_len))
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			i += 1 - j;
			j = 0;
		}
	}

	if (j == patn_len)	return i - j;
	else	return -1;
}

void init_next(char pattern[])
{
	int i, k, m;

	for (i = 0; i < patn_len; i++)
	{
		if (i < 1)	next[i] = 1;
		else
		{
			for (k = 1; k < i; k++)
			{
			    for (m = k; (m < i) && (pattern[m] == pattern[m - k]); m++);
			    if (m == i)	break;
			}
			next[i] = k;
		}
	}
}

int kmp_search(char text[], char pattern[])
{
	int i = 0; /* ���ڂ��Ă���e�L�X�g�̈ʒu */
	int j = 0; /* ���ڂ��Ă���p�^�[���̈ʒu */
	int text_len, patn_len;

	text_len = strlen(text);    /* �e�L�X�g�̒������Z�b�g */
	patn_len = strlen(pattern); /* �p�^�[���̒������Z�b�g */

	while ((i < text_len) && (j < patn_len))
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			j -= next[j];
			if (j < 0)
			{
				i++;
				j++;
			}
		}
	}

	if (j == patn_len)	return i - j;
	else	return -1;
}
