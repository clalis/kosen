/***  p07ex07.c  ***/
/***  s15092  2J23  ’Å–¼ ‘×”V  ***/

#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE *fp;
	double ddata[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
	double gdata[10];

	printf("original data\n");
	for (size_t i = 0; i < 10; i++) printf("(%02d)  %6.1f\n",i,ddata[i]);

	if ((fp = fopen("test.bin", "wb")) == NULL)
	{
		printf("Error has occured.\n");
		exit(EXIT_FAILURE);
	}

	fwrite(ddata, sizeof(double), sizeof(ddata) / sizeof(double), fp);

	fclose(fp);

	if ((fp = fopen("test.bin", "rb")) == NULL)
	{
		printf("Error has occured.\n");
		exit(EXIT_FAILURE);
	}

	fread(gdata, sizeof(double), sizeof(gdata) / sizeof(double), fp);

	fclose(fp);

	printf("obtained data\n");
	for (size_t i = 0; i < 10; i++) printf("[%02d] %6.1f\n",i,gdata[i]);


	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************


original data
(00)     1.0
(01)     2.0
(02)     3.0
(03)     4.0
(04)     5.0
(05)     6.0
(06)     7.0
(07)     8.0
(08)     9.0
(09)    10.0
obtained data
[00]    1.0
[01]    2.0
[02]    3.0
[03]    4.0
[04]    5.0
[05]    6.0
[06]    7.0
[07]    8.0
[08]    9.0
[09]   10.0


*******************************************/
