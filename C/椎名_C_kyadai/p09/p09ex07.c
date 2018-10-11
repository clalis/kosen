#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>


typedef struct hmstime_type
{
	int hour;/*ŽžŠÔ‚ð•\‚·*/
	int min; /*•ª‚ð•\‚·*/
	int sec; /*•b‚ð•\‚·*/
} hmstime_t;

hmstime_t addTime(hmstime_t *t1, hmstime_t *t2);

int main(int argc, char*argv[])
{
	hmstime_t t1 = { 2,46,27 };
	hmstime_t t2 = { 1,34,34 };
	hmstime_t t3;
	hmstime_t t4 = { 2,46,27 };
	hmstime_t t5 = { 1,13,34 };
	hmstime_t t6;

	t3 = addTime(&t1, &t2);
	t6 = addTime(&t4, &t5);

	printf("%2d:%2d:%2d\n", t3.hour, t3.min, t3.sec);
	printf("%2d:%2d:%2d\n", t6.hour, t6.min, t6.sec);

	return 0;
}

hmstime_t addTime(hmstime_t * t1, hmstime_t * t2)
{
	hmstime_t ta;

	ta.sec = (t1->sec) + (t2->sec);
	ta.min = (t1->min) + (t2->min);
	ta.hour = (t1->hour) + (t2->hour);

	if (ta.sec >= 60) ta.min++; ta.sec -= 60;
	if (ta.min >= 60) ta.hour++; ta.min -= 60;

	return ta;
}
