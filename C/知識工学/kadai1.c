// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


int main()
{
	FILE *fp;
	unsigned char data[0x200], msk = 0x80;
	char *fname = "C:/Users/TeamET/Downloads/all/01.img";

	if ((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "\"%s\" can't open.\n", fname);
		exit(EXIT_FAILURE);
	}

	for (size_t cnt = 0; cnt < 20; cnt++)
	{
		system("PAUSE");
		fread(data, 0x200, 1, fp);

		for (size_t r = 0; r < 64; r++)
		{
			for (size_t c = 0; c < 8; c++)
			{
				msk = 0x80;
				for (size_t i = 0; i < 8; i++)
				{
					putchar(' ');
					if (data[r * 8 + c] & msk)	putchar('*');
					else	putchar('.');
					msk >>= 1;
				}
			}
			putchar('\n');
		}
		putchar('\n');
	}

	fclose(fp);

	return 0;
}
/*EOF*/