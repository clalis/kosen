#include	<stdio.h>
#include	"Params.h"

/*--- image_read --- ディスクから画像を読み込む -------------------------------
	image:		画像配列
	filename:	ファイル名
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

/*--- image_write --- ディスクに画像を書き出す --------------------------------
	image:		画像配列
	filename:	ファイル名
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

/*--- image_read_color --- ディスクからカラー画像を読み込む -------------------
	image:		カラー画像配列
	filename:	ファイル名
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

/*--- image_write_color --- ディスクにカラー画像を書き出す --------------------
	image:		カラー画像配列
	filename:	ファイル名
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
