#include <stdio.h>
int main(void)
{
	int all[101][6];//100为all的总储存量,1:初始、2：目标、3：在不在电梯（1表示在）、4：是否完成（1代表完成）、5：储存状态（0表示空储存）
	int usedspace=1;//内存使用情况
	for (int i1 = 1; i1 <= 100; i1++)
	{
		for (int i2 = 1; i2 <= 5; i2++)
		{
			all[i1][i2] = 0;
		}
	}//all储存初始化
	int up, down;
	int time = 0;
	int sum;//sum为电梯内总人数
	int floor;
	printf("请输入电梯初始楼层\n\n");
	scanf_s("%d", &floor);
	int comein;
	while (usedspace>=1)
	{
		printf("请输入要坐电梯的人数\n\n");
		scanf_s("%d", &comein);
		int a[100][4];//变量comein非常量，直接把长度设为100
		printf("请依次输入他们的起始楼层和目标楼层\n\n");
		for (int i = 1; i <= comein; i++)
		{
			printf("起始");
			scanf_s("%d", &a[i][1]);
			printf("目标");
			scanf_s("%d", &a[i][2]);
		}//数据输入“内存a”
		for (int n = 1; n <= comein; n++)
		{
			for(int m=1;m<=100;m++)
			{
				if (all[m][5] == 0)
				{
					all[m][1] = a[n][1];
					all[m][2] = a[n][2];
					all[m][3] = 0;
					all[m][4] = 0;
					all[m][5] = 1;
					m = 101;
				}
			}
		}//数据从a转如all储存
		for (int j1 = 1; j1 <= 100; j1++)
		{
			if (all[j1][5] == 1)
			{
				if (all[j1][2] == floor && all[j1][3] == 1 && all[j1][4] == 0)
				{
					all[j1][3] = 0;
					all[j1][4] = 1;
					all[j1][5] = 0;
				}
			}
		}//下乘客后数据更新
		sum = 0;
		for (int t = 1; t <= 100; t++)
		{
			if (all[t][5] == 1)
			{
				sum = sum + all[t][3];
			}
		}//计算下乘客后的总人数
		for (int j2 = 1; j2 <= 100 ; j2++)
		{
			if (sum <= 3)//限载
			{
				if (all[j2][5] == 1)
				{
					if (all[j2][1] == floor && all[j2][3] == 0 && all[j2][4] == 0)
					{
						all[j2][3] = 1;
						sum = sum + 1;
						printf("w");
					}
				}
			}
		}//上乘客数据更新
		usedspace = 0;
		for (int g = 1; g <= 100; g++)
		{
			usedspace = usedspace + all[g][5];
		}//计算已使用内存
		time++;
		printf("时间%d    楼层%d    总人数%d    内存已用%d\n\n", time, floor, sum, usedspace);
		up = 0;
		down = 0;
		for (int h = 1; h <= 100; h++)
		{
			if (all[h][5] == 1)
			{
				int a1, b1, a2, b2;
				a1 = floor - all[h][1] < 0 && all[h][3] == 0;
				a2 = floor - all[h][2] < 0 && all[h][3] == 1;
				b1 = floor - all[h][1] > 0 && all[h][3] == 0;
				b2 = floor - all[h][2] > 0 && all[h][3] == 1;
				up = up + a1 + a2;
				down = down + b1 + b2;
			}
		}
		if (up >= down)
		{
			floor = floor + 1;
		}
		if (up < down)
		{
			floor = floor - 1;
		}
	}
	return 0;
}