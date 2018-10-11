#include <stdio.h>	/* dev-c++�R���p�C���ł́C���L��"<"��">"��"stdio.h"�Ƃ̊ԂɃX�y�[�X����������*/
#include <stdlib.h>	/*�R���p�C�����ɕs����������邱�Ƃ������̂ŁC�X�y�[�X�͓����Ȃ��悤�� */
#include <string.h>

#define BF 1
#define KMP 1
#define BM 1
#define TAR 0
#define PYOKO 1
#define ABC 1
#define TEXT_LENGTH 0x40
#define PATN_LENGTH 0x7a
#define MAX(a, b) ((a) > (b) ? (a) : (b))



void init_next(char pattern[]);									/* ���炵�\���쐬���� */
void init_skip(unsigned char pattern[]);						/* BM�@�p�̂��炵�\���쐬���� */
int brute_force_search(char text[], char pattern[]);			/* ������text���當����pattern����������(�͂܂����@) */
int kmp_search(char text[], char pattern[]);					/* ������text���當����pattern����������(KMP�@) */
int bm_search(unsigned char text[], unsigned char pattern[]);	/* ������text���當����pattern����������(BM�@) */


int next[PATN_LENGTH];
int skip[PATN_LENGTH];

int main(int argc, char *argv[], char *envp[])
{
	char text_tar[TEXT_LENGTH + 1];
	char pattern_tar[PATN_LENGTH + 1];
	char text_pyoko[TEXT_LENGTH + 1];
	char pattern_pyoko[PATN_LENGTH + 1];
	unsigned char text_abc[TEXT_LENGTH + 1];
	unsigned char pattern_abc[PATN_LENGTH + 1];

	int position;

	strcpy(text_tar, "xxxtartartayx");
	strcpy(pattern_tar, "tartay");
	strcpy(text_pyoko, "pyokopyokomipyokopyokomepyokopyokopyokopyokomupyokopyoko");
	strcpy(pattern_pyoko, "pyokopyokomu");
	strcpy((char *)text_abc, "aabbabcabc");
	strcpy((char *)pattern_abc, "abcab");

#if TAR
#if BF
	printf("--- B F ---\n");
	printf("%s\n", text_tar);
	position = brute_force_search(text_tar, pattern_tar);
	printf("position=%d\n\n", position);
#endif

#if KMP
	printf("--- KMP ---\n");
	init_next(pattern_tar);
	printf("%s\n", text_tar);
	position = kmp_search(text_tar, pattern_tar);
	printf("position=%d\n\n", position);
#endif

#if BM
	printf("--- B M ---\n");
	init_skip((unsigned char *)pattern_tar);
	printf("%s\n", text_tar);
	position = bm_search((unsigned char *)text_tar, (unsigned char *)pattern_tar);
	printf("position=%d\n\n", position);
#endif
#endif

#if PYOKO
#if BF
	printf("--- B F ---\n");
	printf("%s\n", text_pyoko);
	position = brute_force_search(text_pyoko, pattern_pyoko);
	printf("position=%d\n\n", position);
#endif

#if KMP
	printf("--- KMP ---\n");
	init_next(pattern_pyoko);
	printf("%s\n", text_pyoko);
	position = kmp_search(text_pyoko, pattern_pyoko);
	printf("position=%d\n\n", position);
#endif

#if BM
	printf("--- B M ---\n");
	init_skip((unsigned char *)pattern_pyoko);
	printf("%s\n", text_pyoko);
	position = bm_search((unsigned char *)text_pyoko, (unsigned char *)pattern_pyoko);
	printf("position=%d\n\n", position);
#endif
#endif

#if ABC
#if BF
	printf("--- B F ---\n");
	printf("%s\n", text_abc);
	position = brute_force_search((char *)text_abc, (char *)pattern_abc);
	printf("position=%d\n\n", position);
#endif

#if KMP
	printf("--- KMP ---\n");
	init_next((char *)pattern_abc);
	printf("%s\n", text_abc);
	position = kmp_search((char *)text_abc, (char *)pattern_abc);
	printf("position=%d\n\n", position);
#endif

#if BM
	printf("--- B M ---\n");
	init_skip(pattern_abc);
	printf("%s\n", text_abc);
	position = bm_search(text_abc, pattern_abc);
	printf("position=%d\n\n", position);
#endif
#endif

	return 0;
}

int brute_force_search(char text[], char pattern[])
{
	int i = 0;	/* ���ڂ��Ă����e�L�X�g�̈ʒu */
	int j = 0;	/* ���ڂ��Ă����p�^�[���̈ʒu */
	int text_len, patn_len, flag, in;
	flag = 1;

	text_len = strlen(text);	/* �e�L�X�g�̒������Z�b�g */
	patn_len = strlen(pattern);	/* �p�^�[���̒������Z�b�g */

	while ((i < text_len) && (j < patn_len))
	{
		if (flag)	for (in = 0; in < i; in++)	putchar(' ');
		putchar(pattern[j]);
		if (text[i] == pattern[j])
		{
			i++;
			j++;
			flag = 0;
		}
		else
		{
			i += 1 - j;
			j = 0;
			printf("\t\t...failed.\n");
			flag = 1;
		}
	}

	if (j == patn_len)
	{
		printf("\tsucceeded.\n");
		return i - j;
	}
	else	return -1;
}

void init_next(char pattern[])
{
	int i, k, m;

	for (i = 0; i < strlen(pattern); i++)
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
		printf("next[%2d] = %2d\n", i, next[i]);
	}
}

int kmp_search(char text[], char pattern[])
{
	int i = 0; /* ���ڂ��Ă����e�L�X�g�̈ʒu */
	int j = 0; /* ���ڂ��Ă����p�^�[���̈ʒu */
	int text_len, patn_len, flag, in;
	flag = 1;

	text_len = strlen(text);    /* �e�L�X�g�̒������Z�b�g */
	patn_len = strlen(pattern); /* �p�^�[���̒������Z�b�g */

	while ((i < text_len) && (j < patn_len))
	{
		if (flag)	for (in = 0; in < i; in++)	putchar(' ');
		putchar(pattern[j]);
		if (text[i] == pattern[j])
		{
			i++;
			j++;
			flag = 0;
		}
		else
		{
			j -= next[j];
			if (j < 0)
			{
				i++;
				j++;
			}
			printf("\t\t...failed.\n");
			flag = 1;
		}
	}

	if (j == patn_len)
	{
		printf("\t...succeeded.\n");
		return i - j;
	}
	else	return -1;
}

void init_skip(unsigned char pattern[])
{
	int i;

	for (i = 0; i < PATN_LENGTH; i++)	skip[i] = strlen((char *)pattern);
	for (i = 0; i < strlen((char *)pattern); i++)	skip[pattern[i]] = strlen((char *)pattern) - i - 1;
	for (i = 0; i < strlen((char *)pattern); i++)	printf("%c : skip[%3d] = %d\n", pattern[i], pattern[i], skip[pattern[i]]);
}

int bm_search(unsigned char text[], unsigned char pattern[])
{
	int i;	/* ���ڂ��Ă����e�L�X�g�̈ʒu */
	int j;	/* ���ڂ��Ă����p�^�[���̈ʒu */
	int text_len, patn_len, flag, in;
	flag = 1;

	text_len = strlen((char *)text);    /* �e�L�X�g�̒������Z�b�g */
	patn_len = strlen((char *)pattern); /* �p�^�[���̒������Z�b�g */

	i = patn_len - 1;	/* i�Ƀe�L�X�g�̍ŏ��̒��ڈʒu���Z�b�g */

	while (i < text_len)
	{
		j = patn_len - 1;	/* j�Ƀp�^�[���̍ŏ��̒��ڈʒu���Z�b�g */

		for (in = 0; in < i; in++)	putchar('>');

		while (text[i] == pattern[j])	/* �e�L�X�g�ƃp�^�[�����P�������r */
		{
			if (j == 0)	/* ���ׂĂ̕��������v������ */
			{
				printf("%c\t...succeeded.\n", pattern[j]);	/* �p�^�[�������������ʒu���Ԃ� */
				return i;
			}

			printf("%c\n", pattern[j]);

			i--;	/* �e�L�X�g�̈ʒu���P�����߂� */
			j--;	/* �p�^�[���̈ʒu���P�����߂� */

			for (in = 0; in < i; in++)	putchar(' ');
		}

		i += MAX(patn_len - j, skip[text[i]]);	/* �e�L�X�g�̒��ړ_(i)���C�s���v�ɂȂ��������ɉ��������ʂ������炷 */
		printf("%c\t\t...failed.\n", pattern[j]);
	}

	return -1;
}
