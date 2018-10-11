
typedef struct point_type
{
	int x;
	int y;
} point_t;

point_t rotatePoint(point_t point, double theta);

int main()
{
	point_t pnt;
	pnt.x = 100;
	pnt.y = 100;

	printf("(%d, %d)\n", rotatePoint(pnt, M_PI / 4));

	printf("(%d, %d)\n", rotatePoint(pnt, M_PI / 4 * -1));

	return 0;
}

point_t rotatePoint(point_t point, double theta)
{
	point_t surepnt;
	surepnt.x = 0;
	surepnt.y = 0;

	surepnt.x = ((point.x)*(cos(theta))) - ((point.y)*(sin(theta)));
	surepnt.y = ((point.x)*(sin(theta))) + ((point.y)*(cos(theta)));

	return surepnt;
}
