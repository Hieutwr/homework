#include<stdio.h>
int year, month, day;			//����ȫ�ֱ���������
int calendar_1[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };		//�ֱ��������ƽ�������
int calendar_2[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int isleap(int a)				//���庯��isleap����������
{
	int something;
	if (a % 4 == 0)
	{
		if (a % 100 == 0)
		{
			if (a % 400 == 0)
				something = 1;
			else
				something = 0;
		}
		else
			something = 1;
	}
	else
		something = 0;
	return something;
}

int main()						//����������
{
	printf("���������գ��ո��������");
	scanf_s("%d%d%d", &year, &month, &day);		//��������������
	int sum(int a, int b,int c);				//�������ú���sum
	if (isleap(year) == 1)		//���ú���isleap�ж��Ƿ�Ϊ����
	{
		printf("\n ����run��!");
		if (day > calendar_1[month - 1] || day <= 0 || month <= 0 || month > 12)	//������������
			printf("\n���ף���������������");
		else
			printf("���Ǹ���ĵ�%d��", sum(year, month, day));			//���ú���sum��������ǵڼ���
	}
	else
	{
		printf("\n �ⲻ��run��!");
		if (day > calendar_2[month - 1] || day <= 0 || month <= 0 || month > 12)
			printf("\n���ף���������������");
		else
			printf("���Ǹ���ĵ�%d��", sum(year, month, day));			//���ú���sum��������ǵڼ���
	}
	return 0;
}

int sum(int a, int b,int c)		//���庯��sum
{
	int all=0, i;
	if (isleap(year) == 1)		//�ٴ��ж��Ƿ�Ϊ����
		for (i = 0; i+1 < b;i++)
			all = all + calendar_1[i];
	else
		for (i = 0; i+1 < b; i++)
			all = all + calendar_2[i];
	return all+c;				//allΪ������ݿ�ʼ�������·ݿ�ʼ�����ӣ�����Ҫ���ϸ����Ѿ��������Ӽ����Ϻ���c
}