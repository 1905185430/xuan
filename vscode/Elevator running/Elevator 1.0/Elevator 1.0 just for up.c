#include <stdio.h>
int main(void)
{
	int a, b, floor, s1, s2;
	int p1, p2;
	floor = 1;
	a = 0;
	b = 0;
	s1 = 3;
	s2 = 6;
	p1 = 5;
	p2 = 7;
	//printf(" 请输入乘客A的初始楼层与目标楼层\n");
	//scanf("%d   %d", &s1, &p1);
	//printf(" 请输入乘客B的初始楼层与目标楼层\n");
	//scanf("%d   %d", &s2, &p2);
	for (int i = 1; i <= 10; i++)
	{
		if (floor = s1)
		{
			a = 1;//a=1表示A在电梯上，B同理

		}
		if (floor = s2)
		{
			b = 1;
		}
		if (floor =(a * p1) )
		{
			a = 0;
		}
		if (floor = (b * p2))
		{
			b = 0;
		}
		printf("%d %d \n", floor, a + b);
		floor = floor + 1;
	}
	return 0;
}