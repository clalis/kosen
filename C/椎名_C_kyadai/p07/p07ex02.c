/***  p07ex02.c  ***/
/***  s15092  2J23  椎名 泰之  ***/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	FILE *fp;
	int i = 0, num, pts[128][8] = { 0 }, sum[64], cepcnt;
	double ave[4];

	if ((fp = fopen("marks.txt", "r")) == NULL)
	{
		printf("Error has occured.\n");
		exit(EXIT_FAILURE);
	}

	while (fscanf(fp, "%d, %d, %d, %d", &pts[i][0], &pts[i][1], &pts[i][2], &pts[i][3]) == 4)	i++;

	fclose(fp);

	num = i;

	if ((fp = fopen("marks1.txt", "w")) == NULL)
	{
		printf("Error has occured.\n");
		exit(EXIT_FAILURE);
	}

	fprintf(fp, "学生番号\t国語\t数学\t理科\t英語\t合計\n");

	for (i = 0; i < num; i++)
	{
		pts[i][4] = 0;
		for (cepcnt = 0; cepcnt <= 3; cepcnt++)	pts[i][4] += pts[i][cepcnt];
	}
	for (i = 0; i < 5; i++)
	{
		sum[i] = 0;
		for (cepcnt = 0; cepcnt < num; cepcnt++)	sum[i] += pts[cepcnt][i];
		ave[i] = (double)sum[i] / (double)num;
	}

	for (i = 0; i < num; i++)	fprintf(fp, "\t%2d\t\t%4d\t%4d\t%4d\t%4d\t%4d\n", i, pts[i][3], pts[i][1], pts[i][2], pts[i][0], pts[i][4]);
	fprintf(fp, "平均\t\t%4.1f\t%4.1f\t%4.1f\t%4.1f\t%4.1f", ave[3], ave[1], ave[2], ave[0], ave[4]);

	fclose(fp);

	return 0;
}


/**************** 実行結果 *****************


学生番号	国語	数学	理科	英語	合計
	 0		  66	  59	  56	  70	 251
	 1		 100	 100	 100	 100	 400
	 2		  94	  90	  96	  68	 348
	 3		  75	  92	  85	  79	 331
	 4		  50	  66	  72	  64	 252
	 5		 100	 100	 100	 100	 400
	 6		  97	  92	  86	  81	 356
	 7		  79	  88	  88	  95	 350
	 8		  74	  74	  75	  78	 301
	 9		  75	  80	  92	  75	 322
	10		  63	  76	  77	  87	 303
	11		 100	  90	  99	  90	 379
	12		  75	  68	  67	  68	 278
	13		  71	  66	  69	  66	 272
	14		  80	  69	  73	  71	 293
	15		  97	  81	  98	  98	 374
	16		 100	 100	 100	 100	 400
	17		  92	 100	  94	  91	 377
	18		  68	  87	  73	  89	 317
	19		  94	 100	 100	  89	 383
	20		  25	  27	  26	  21	  99
	21		 100	 100	 100	 100	 400
	22		  31	  53	  32	  36	 152
	23		  85	  74	  72	  97	 328
	24		  79	  85	  81	  86	 331
	25		  72	  71	  63	  75	 281
	26		  84	  94	  87	  88	 353
	27		  60	  68	  72	  62	 262
	28		  70	  68	  62	  62	 262
	29		  70	  88	  86	  92	 336
	30		  64	  64	  69	  57	 254
	31		  73	  77	  51	  55	 256
	32		  71	  74	  80	  58	 283
	33		 100	  91	  79	  97	 367
	34		  69	  58	  72	  69	 268
	35		  19	  54	  35	  38	 146
	36		  37	  23	  34	  31	 125
	37		  63	  85	  71	  94	 313
	38		  73	  90	  71	  64	 298
	39		  48	  51	  50	  55	 204
	40		 100	 100	 100	  97	 397
	41		  85	  83	 100	  87	 355
平均		74.5	77.5	76.0	75.7	303.7


*******************************************/
//http://www.nurs.or.jp/~sug/soft/tora/tora10.htm
