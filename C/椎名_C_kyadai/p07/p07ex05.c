/***  p07ex05.c  ***/
/***  s15092  2J23  í≈ñº ë◊îV  ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define B 256


int main()
{
	FILE *fpi, *fpo;
	int cnt = 0, stat = 1;	//stat = 0:imgnary prog, 1:not word, other:now in progress
	char buff[B], str, laststr = 0;

	fgets(buff, B, stdin);
	sscanf(buff, "%s", &buff);


	if (((fpi = fopen((char*)buff, "r")) == NULL) || ((fpo = fopen("output.txt", "w")) == NULL))
	{
		printf("Error has occured.\n");
		exit(EXIT_FAILURE);
	}

	while ((str = fgetc(fpi)) != EOF)
	{
		if (stat == 2)
		{
			if (isalnum(str) || (str == '_'))	fprintf(fpo, "%c", str);
			else
			{
				stat = 1;
				cnt++;
				if (cnt % 8 == 0)	fprintf(fpo, "\n");
				else	fprintf(fpo, " ");
			}
		}
		else if (stat == 0)
		{
			if (isalnum(str) || (str == '_'))	{}
			else	stat = 1;
		}
		else
		{
			if (isalpha(str))
			{
				if (isdigit(laststr))	stat = 0;
				else
				{
					stat = 2;
					fprintf(fpo, "%c", str);
				}
			}
		}

		laststr = str;
	}

	fclose(fpi);
	fclose(fpo);


	return 0;
}


/**************** é¿çsåãâ  *****************


wer qwe123 wer456 sw_qwe q12_12 A123B123 wsed_123 


*******************************************/
