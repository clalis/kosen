/* Pointer��p�������X�g�\���̎��� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

#define MAX_STATION 10			/* �ő�̉w�̐� */
#define ERROR NULL


typedef struct Station
{
	char name[20 + 1];			/* �w���͍ő�S�p10�����܂� */
	int  time;					/* �O�̉w����̏��v���� */
	struct Station *next_addr;	/* ���̃f�[�^�̃A�h���X */
}
STATION;

int menu(void);					/* ���j���[ */
void add(void);					/* �f�[�^�̒ǉ� */
void del(void);					/* �f�[�^�̍폜 */
void calc(void);				/* ���v���Ԃ̌v�Z */
void station_disp(void);		/* �H���f�[�^��\�� */
int read_data(void);			/* �f�[�^�t�@�C���̓ǂݍ��� */
int get_num(void);
STATION *check(char target[]);	/* ���͂��ꂽ�w�����X�g�ɑ��݂��Ă��邩�ǂ����̃`�F�b�N */

int station_num = 0;			/* �t�@�C������ǂݍ��񂾉w�̐� */

STATION station[MAX_STATION];	/* ���l�̓��͗p�z�� */
STATION head;

int main(void)
{
	int end = 0;
	end = read_data();

	while (!end)	end = menu();

	return 0;
}

int get_num(void)
{
	int  i;
	int  d = 0;
	int  c = 0;

	rewind(stdin);
	for (i = 0; (i < 5) && (c != '\n'); i++)	/* 5�P�^�܂� */
	{
		c = getchar();
		if (c == '\n')	break;
		d = d * 10 + c - '0';
	}
	rewind(stdin);

	return d;
}

int read_data(void)
{
	FILE *fp;
	int i;

	/* �L�����N�^�f�[�^�ǂݍ��� */
	if ((fp = fopen("station_data.txt", "r")) == NULL)	/* C:/Users/TeamET/Downloads/station_data.txt */
	{
		fprintf(stderr, "CANNOT OPEN station_data.txt\n");
		exit(EXIT_FAILURE);	//or return -1;
	}
	for (i = 0; i < MAX_STATION; i++, station_num++)
	{
		if (fscanf(fp, "%s\t%d", station[i].name, &station[i].time) != 2)	break;
		/* �܂��͓ǂݍ��񂾏��Ƀ��X�g���Ȃ� */
		station[i].next_addr = &station[i + 1];
	}

	fclose(fp);
	/* ���X�g�̐擪��head.next_addr�ɃZ�b�g */
	head.next_addr = &station[0];
	/* ���X�g�̍Ō��NULL�����Ă��� */
	station[station_num - 1].next_addr = NULL;

	return 0;
}

void station_disp(void)
{
	STATION *current_addr;
	current_addr = head.next_addr;

	while (1)
	{
		printf("|ADDR:%20d|\n", current_addr);
		printf("|NAME:%20s|\n", current_addr->name);
		printf("|TIME:%20d|\n", current_addr->time);
		printf("|NEXT:%20d|\n", current_addr->next_addr);
		putchar('\n');

		if (current_addr->next_addr == NULL)	break;
		current_addr = current_addr->next_addr;	/* current_addr���X�V */
	}
}

STATION *check(char target[])
{
	/* ���X�g�����ǂ��Ďw�肳�ꂽ�w���܂܂�Ă��邩�ǂ����m�F */
	STATION *current_addr;
	current_addr = head.next_addr;

	while (1)
	{
		if (!strcmp(target, current_addr->name))	return current_addr;	/* �w������v������ */
		if (current_addr->next_addr == NULL)	break;
		current_addr = current_addr->next_addr;	/* current_addr���X�V */
	}

	return ERROR;
}

void add(void)	/* �f�[�^�̒ǉ� */
{
	STATION *current_addr;
	char targetChar[16];    // �ǉ�����w�̒��O�̉w�����i�[
	int a_point; /* �z��Ƃ��Ă̒ǉ��ʒu */
	int i;    /* �����I�ɂ͍Ō�ɒǉ����� */

	current_addr = head.next_addr;
	a_point = station_num++;

	printf("NAME = ");
	fgets(station[a_point].name, 16, stdin);
	for (i = 0; (station[a_point].name[i] != '\n') && (i != 15); i++);
	station[a_point].name[i] = '\0';
	/* �������s�R�[�h���폜���邽�߂̏��� */

	printf("TIME = ");
	station[a_point].time = get_num();

	station_disp();

	do
	{
		printf("�ǂ̉w�̌�ɒǉ����܂���?\nNAME = ");
		fgets(targetChar, 16, stdin);
		for (i = 0; targetChar[i] != '\n' && i != 15; i++);
		targetChar[i] = '\0';
		/* �����s�R�[�h���폜���邽�߂̏��� */
	} while (check(targetChar) == ERROR);

	/* �f�[�^�̒ǉ��i���X�g���Ȃ��j */
	station[a_point].next_addr = current_addr->next_addr;
	current_addr->next_addr = &station[a_point];

	station_disp();
}

void del(void)	/* �f�[�^�̍폜 */
{
	int i;
	STATION *forDel; // �폜�������v�f���i�[����|�C���^
	STATION *current_addr;
	char targetChar[16];

	station_disp();

	do
	{
		printf("�ǂ̉w���폜���܂���?\nNAME = ");
		fgets(targetChar, 16, stdin);
		for (i = 0; (targetChar[i] != '\n') && (i != 15); i++);
		targetChar[i] = '\0';
		/* �����s�R�[�h���폜���邽�߂̏��� */
	} while (check(targetChar) == ERROR);

	current_addr = head.next_addr;

	while (1)	/* �c��P�������炻��ȏ�����Ȃ� */
	{
		if (!strcmp(current_addr->name, targetChar) && (current_addr == head.next_addr))
		{
			/* �擪���폜�������ꍇ */
			head.next_addr = current_addr->next_addr;
			break;
		}
		if (current_addr->next_addr == NULL)	break;
		if (!strcmp(current_addr->next_addr->name, targetChar))
		{
			/* �擪�ȊO���폜�������ꍇ */
			current_addr->next_addr = current_addr->next_addr->next_addr;
			break;
		}

		current_addr = current_addr->next_addr;	/* current_addr���X�V */
	}

	station_disp();
}

void calc(void)	/* ���v���Ԃ̌v�Z */
{
	int sum = 0, i;

	STATION *current_addr, *from, *to;
	char targetFrom[16], targetTo[16];

	printf("�ǂ�����ǂ��܂ł̏��v���Ԃ��v�Z���܂����H\n");
	do
	{
		printf("FROM(Station Name) = ");
		fgets(targetFrom, 16, stdin);
		for (i = 0; (targetFrom[i] != '\n') && (i != 15); i++);
		targetFrom[i] = '\0';
		/* �����s�R�[�h���폜���邽�߂̏��� */
	} while ((from = check(targetFrom)) == ERROR);

	do
	{
		printf("TO(Station Name) = ");
		fgets(targetTo, 16, stdin);
		for (i = 0; (targetTo[i] != '\n') && (i != 15); i++);
		targetTo[i] = '\0';
		/* �����s�R�[�h���폜���邽�߂̏��� */
	} while ((to = check(targetTo)) == ERROR);

	printf("%s����%s�܂łł��ˁB\n", targetFrom, targetTo);
	while (1)
	{
		/* ���v���Ԃ��v�Z���� */
		from = from->next_addr;
		sum += from->time;
		if (from == to)	break;
	}
	printf("���v���Ԃ�%d�ł��B\n", sum);
}

int menu(void)	/* ���j���[ */
{
	int c;

	while (1)
	{
		printf("1.�\\��\n");   // �\�Ǝ��̊Ԃ�"\"�͂��܂��Ȃ��i�O���Ƃǂ��Ȃ邩�A�����Ă݂Ă��悢
		printf("2.�ǉ�\n");
		printf("3.�폜\n");
		printf("4.���v����\n");
		printf("5.�I��\n");
		c = get_num();
		if ((c >= 1) && (c <= 5))	break;
		else	printf("1~5�܂ł̐�������͂��Ă�������\n");
	}

	switch (c)
	{
	case 1:
		station_disp();
		break;
	case 2:
		add();
		break;
	case 3:
		del();
		break;
	case 4:
		calc();
		break;
	case 5:
		return 1;
	default:
		break;
	}

	return 0;
}
