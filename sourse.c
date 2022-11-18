#include<stdio.h>
int year, month, day;			//定义全局变量年月日
int calendar_1[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };		//分别定义闰年和平年的日历
int calendar_2[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int isleap(int a)				//定义函数isleap来区分闰年
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

int main()						//定义主函数
{
	printf("输入年月日（空格隔开）：");
	scanf_s("%d%d%d", &year, &month, &day);		//输入年月日数据
	int sum(int a, int b,int c);				//声明调用函数sum
	if (isleap(year) == 1)		//调用函数isleap判断是否为闰年
	{
		printf("\n 这是run年!");
		if (day > calendar_1[month - 1] || day <= 0 || month <= 0 || month > 12)	//纠正错误输入
			printf("\n离谱，这天是你生日吗？");
		else
			printf("这是该年的第%d天", sum(year, month, day));			//调用函数sum输出该日是第几天
	}
	else
	{
		printf("\n 这不是run年!");
		if (day > calendar_2[month - 1] || day <= 0 || month <= 0 || month > 12)
			printf("\n离谱，这天是你生日吗？");
		else
			printf("这是该年的第%d天", sum(year, month, day));			//调用函数sum输出该日是第几天
	}
	return 0;
}

int sum(int a, int b,int c)		//定义函数sum
{
	int all=0, i;
	if (isleap(year) == 1)		//再次判断是否为闰年
		for (i = 0; i+1 < b;i++)
			all = all + calendar_1[i];
	else
		for (i = 0; i+1 < b; i++)
			all = all + calendar_2[i];
	return all+c;				//all为输入年份开始到输入月份开始的日子，还需要加上该月已经过的日子即加上函数c
}