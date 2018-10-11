/***  p07ex04.c  ***/
/***  s15092  2J23  ’Å–¼ ‘×”V  ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define B 256


void revStr(char *in, char *out);
void reverseString(char string[]);

int main()
{
	FILE *fpi, *fpo;
	char buff[B], in[B], out[B];

//	fstr = (char *)calloc(B, sizeof(char));
//	if (fstr == NULL)
//	{
//		printf("Error has occured.\n");
//		exit(EXIT_FAILURE);
//	}

	fgets(buff, B, stdin);
	sscanf(buff, "%s", &buff);

	if (((fpi = fopen((char*)buff, "r+")) == NULL) || ((fpo = fopen("output.txt", "w+")) == NULL))
	{
		printf("Error has occured.\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(in, B, fpi) != NULL)
	{
		in[strlen(in) - 1] = '\0';
		revStr(in, out);
		fprintf(fpo, "%s\n", out);
	}

	fclose(fpi);
	fclose(fpo);
//	free(fstr);

	reverseString(buff);


	return 0;
}


void revStr(char *in, char *out)
{
	volatile register unsigned long long int i;
	for (i = 0; i < strlen(in); i++)	out[i] = in[strlen(in) - i - 1];

	out[i] = '\0';
}

void reverseString(char string[])
{
	char tmp = '\0';
	char *f = string;
	char *l = string;

	if (*f == '\0')	return;

	while (*(l + 1) != '\0')	l++;

	while (f < l)
	{
		tmp = *f;
		*f = *l;
		*l = tmp;

		f++;
		l--;
	}

	return;
}


/**************** ŽÀsŒ‹‰Ê *****************


>h.oidts< edulcni#

)(niam tni
{
;)"n\?uoy era woH .olleH"(ftnirp    
;)"n\?uoY dnA .sknaht ,eniF"(ftnirp    
;)"n\.os oS"(ftnirp    
;0 nruter    
}


*******************************************/
