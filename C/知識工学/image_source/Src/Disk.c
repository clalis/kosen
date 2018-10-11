#include	<stdio.h>
#include	"Params.h"

/*--- image_read --- �f�B�X�N����摜��ǂݍ��� -------------------------------
	image:		�摜�z��
	filename:	�t�@�C����
-----------------------------------------------------------------------------*/
int image_read(unsigned char image[Y_SIZE][X_SIZE], char *filename)
{
	FILE 	*fp;

	fp = fopen(filename, "rb");
	if (fp == NULL) return -1;
	else {
		fread(image, (size_t)X_SIZE, (size_t)Y_SIZE, fp);
		fclose(fp);
		return 0;
	}
}

/*--- image_write --- �f�B�X�N�ɉ摜�������o�� --------------------------------
	image:		�摜�z��
	filename:	�t�@�C����
-----------------------------------------------------------------------------*/
int image_write(unsigned char image[Y_SIZE][X_SIZE], char *filename)
{
	FILE	*fp;

	fp = fopen(filename, "wb");
	if (fp == NULL) return -1;
	else {
		fwrite(image, (size_t)X_SIZE, (size_t)Y_SIZE, fp);
		fclose(fp);
		return 0;
	}
}

/*--- image_read_color --- �f�B�X�N����J���[�摜��ǂݍ��� -------------------
	image:		�J���[�摜�z��
	filename:	�t�@�C����
-----------------------------------------------------------------------------*/
int image_read_color(unsigned char image[3][Y_SIZE][X_SIZE], char *filename)
{
	FILE	*fp;
	int		i;

	fp = fopen(filename, "rb");
	if (fp == NULL) return -1;
	else {
		for (i = 0; i < 3; i++)
			fread(&image[i][0][0], (size_t)X_SIZE, (size_t)Y_SIZE, fp);
		fclose(fp);
		return 0;
	}
}

/*--- image_write_color --- �f�B�X�N�ɃJ���[�摜�������o�� --------------------
	image:		�J���[�摜�z��
	filename:	�t�@�C����
-----------------------------------------------------------------------------*/
int image_write_color(unsigned char image[3][Y_SIZE][X_SIZE], char *filename)
{
	FILE	*fp;
	int		i;

	fp = fopen(filename, "wb");
	if (fp == NULL) return -1;
	else {
		for (i = 0; i < 3; i++)
			fwrite(&image[i][0][0], (size_t)X_SIZE, (size_t)Y_SIZE, fp);
		fclose(fp);
		return 0;
	}
}
