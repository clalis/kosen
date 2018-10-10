
typedef struct fraction_type
{
	int numerator;
	int denominator;
} fraction_t;

void printcheckfraction(fraction_t a, char ope, fraction_t b, fraction_t c);
void checkfraction(fraction_t a, fraction_t b);
fraction_t reduceFraction(fraction_t fraction);
fraction_t addFraction(fraction_t a, fraction_t b);
fraction_t subtractFraction(fraction_t a, fraction_t b);
fraction_t multiplyFraction(fraction_t a, fraction_t b);
fraction_t divideFraction(fraction_t a, fraction_t b);


int main()
{
	fraction_t a = { 1,6 };
	fraction_t b = { 1,3 };
	fraction_t am = { -1,6 };
	fraction_t bm = { -1,3 };
	fraction_t c = { 3,4 };
	fraction_t d = { 16,3 };
	fraction_t cm = { -3,4 };
	fraction_t dm = { -16,3 };

	checkfraction(a, b);
	checkfraction(a, bm);
	checkfraction(am, b);
	checkfraction(am, bm);
	checkfraction(c, d);
	checkfraction(c, dm);
	checkfraction(cm, d);
	checkfraction(cm, dm);

	return 0;
}

void printcheckfraction(fraction_t a, char ope, fraction_t b, fraction_t c)
{
	printf("(%d/%d) %c (%d/%d) = (%d/%d)\n",
		a.numerator, a.denominator, ope,
		b.numerator, b.denominator,
		c.numerator, c.denominator
		);

}

void checkfraction(fraction_t a, fraction_t b)
{
	fraction_t c;
	c = addFraction(a, b);
	printcheckfraction(a, '+', b, c);
	c = subtractFraction(a, b);
	printcheckfraction(a, '-', b, c);
	c = subtractFraction(b, a);
	printcheckfraction(b, '-', a, c);

	c = multiplyFraction(a, b);
	printcheckfraction(a, '*', b, c);
	c = divideFraction(a, b);
	printcheckfraction(a, '/', b, c);
	c = divideFraction(b, a);
	printcheckfraction(b, '/', a, c);
	printf("\n");

}

fraction_t reduceFraction(fraction_t fraction)
{
	int x = fraction.numerator;
	int y = fraction.denominator;
	int r;

	if (x < 0)
	{
		x *= -1;
	}
	if (y < 0)
	{
		y *= -1;
	}

	r = x%y;

	while (r != 0)
	{
		x = y; y = r;
		r = x%y;
	}

	fraction.numerator /= y;
	fraction.denominator /= y;

	return fraction;
}

fraction_t addFraction(fraction_t a, fraction_t b)
{
	fraction_t ans;
	fraction_t surefrc;

	surefrc.numerator = (((a.numerator)*(b.denominator)) + ((b.numerator)*(a.denominator)));
	surefrc.denominator = ((a.denominator)*(b.denominator));

	ans = reduceFraction(surefrc);

	return ans;
}

fraction_t subtractFraction(fraction_t a, fraction_t b)
{
	fraction_t ans;
	fraction_t surefrc;

	surefrc.numerator = (((a.numerator)*(b.denominator)) - ((b.numerator)*(a.denominator)));
	surefrc.denominator = ((a.denominator)*(b.denominator));

	ans = reduceFraction(surefrc);

	return ans;
}

fraction_t multiplyFraction(fraction_t a, fraction_t b)
{
	fraction_t ans;
	fraction_t surefrc;

	surefrc.numerator = ((a.numerator)*(b.numerator));
	surefrc.denominator = ((a.denominator)*(b.denominator));

	ans = reduceFraction(surefrc);

	return ans;
}

fraction_t divideFraction(fraction_t a, fraction_t b)
{
	fraction_t ans;
	fraction_t surefrc;

	surefrc.numerator = ((a.numerator)*(b.denominator));
	surefrc.denominator = ((a.denominator)*(b.numerator));

	ans = reduceFraction(surefrc);

	if (b.numerator == 0)
	{
		ans.numerator = 10000000;
		ans.denominator = 1;
	}

	return ans;
}
