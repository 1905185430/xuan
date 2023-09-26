#include <stdio.h>
int main()
{
	int a, b, floor, s1, s2,time=0;
	int p1, p2;
	floor = 1;
	a = 0;
	b = 0;
	printf(" 请输入乘客A的初始楼层与目标楼层\n");
	scanf("%d   %d", &s1, &p1);
	printf(" 请输入乘客B的初始楼层与目标楼层\n");
	scanf("%d   %d", &s2, &p2);
	printf("\n");
	for (int i = 1; i <= 10; i++)
	{
		int x1;
		x1=(floor>=s1-1)&&(floor>=s2-1)&&(floor>=p1-1)&&(floor>=p2-1);
		time++;
		if (floor == s1&&s1-p1<=0) a = 1;//a=1表示A在电梯上，B同理
		if (floor == s2&&s2-p2<=0) b = 1;
		if (floor == a * p1)	a = 0;
		if (floor == b * p2)	b = 0;
		printf("%d 电梯层数%d   总人数%d \n",time, floor, a + b);
		if(x1==1) break;
		floor=floor+1;
	}
	time++;
	floor=floor+1;
	if (floor == a * p1)	a = 0;
	if (floor == b * p2)	b = 0;
	if (floor == s1&&s1-p1>=0) a = 1;
    if (floor == s2&&s2-p2>=0) b = 1;
    printf("%d 电梯层数%d   总人数%d \n",time, floor, a + b);
    floor=floor-1;
	for (int n = 1;n <= 10; n++)
	{
		time++;
		if (floor == s1&&s1-p1>=0) a = 1;
		if (floor == s2&&s2-p2>=0) b = 1;
		if (floor == a * p1)	a = 0;
		if (floor == b * p2)	b = 0;	
      	printf("%d 电梯层数%d   总人数%d \n",time, floor, a + b);
      	if (floor == 1) break;
      	floor=floor-1;
	}
	printf("wwww");
	return 0;
}