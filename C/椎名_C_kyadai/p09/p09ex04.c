

void mid(char *d, char *s, int m, int n);

int main(int argc, char*argv[])
{
	char str1[] = "exercises";
	char str2[32] = "abcdefghijklmn";
	char str3[32] = "abcdefghijklmn";
	char str4[32] = "abcdefghijklmn";
	char str5[] = "Tokyo";
	char str6[32] = "abcdefghijklmn";
	char str7[32] = "abcdefghijklmn";

	puts(str1);
	mid(str2, str1, 2, 5);
	puts(str2);
	mid(str3, str1, 2, 10);
	puts(str3);
	mid(str4, str1, 12, 3);
	puts(str4);
	printf("%d\n", str4[0]);
	mid(str6, str5, 2, 1);
	printf("--%s--\n", str6);    /*実行結果は --o-- が表示されるはず*/
	mid(str7, str5, 2, 10);
	printf("--%s--\n", str7);    /*実行結果は --okyo-- が表示されるはず*/

	return 0;
}

void mid(char *d, char *s, int m, int n)
{
	int cnt = 0;
	char *scnt;

	scnt = s;

	while (*scnt++) cnt++;

	//for (size_t i = 0; i<cnt; i++) d++;
	for (size_t i = 0; i < (m-1); i++) s++;
	if (n > cnt)
	{
		n = cnt;
	}
	if (m >= cnt)
	{
		*d = '\0';
		return;
	}
	for (size_t i = 0; i < n; i++)
	{
		*d = *s;
		d++;
		s++;
	}

	*d = '\0';

	return;
}
