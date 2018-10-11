/***  p07ex03.c  ***/
/***  s15092  2J23  í≈ñº ë◊îV  ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
	FILE *fp;
	int len = 0, row = 0;
	char temp[256] = {0}, buff[256];
	char *tp = temp, *buff1, *filename;

	fgets(buff, 32, stdin);
	sscanf(buff, "%s", &buff);

	filename = (char*)buff;

	if ((fp = fopen(buff, "r")) == NULL)
	{
		printf("Error has occured.\n");
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	while ((*tp = fgetc(fp)) != EOF)	if (*tp == '\n')row++;
	fseek(fp, 0, SEEK_SET);

	printf("len = %d\n", len - row);

	tp = (char *)calloc(strlen(temp), sizeof(char));
	if (tp == NULL)
	{
		printf("Error has occured.\n");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; (*tp = fgetc(fp)) != EOF; i++)	temp[i] = *tp;

	//buff1 = strrchr(temp, (int)'\n');//\n detector
	//printf("%c\n", *buff1);
	if (temp[strlen(temp) - 1] != '\n')	row++;

	printf("row = %d\n", row);

	free(tp);
	fclose(fp);


	return 0;
}


/**************** é¿çsåãâ  *****************


p07ex03A.txt
len = 155
row = 5

p07ex03B.txt
len = 154
row = 5


*******************************************/
