#include <stdio.h>
int main(void)
{
	int all[105][6];//定义总储存all，1:初始、2：目标、3：在elevator 1、4：在elevator 2、5：是否完成
	int usedspace = 1;
	int capacity;
	for (int i1 = 1; i1 <= 100; i1++)
	{
		for (int i2 = 1; i2 <= 6; i2++)
		{
			all[i1][i2] = 0;
		}
	}//all储存初始化
	int f1, f2;
	int up1, up2, down1, down2;
	int sum1, sum2;
	int time = 0;
	printf("现在进行电梯的初始化配置\n");
	printf("请输入电梯的容量\n");
	scanf_s("%d", &capacity);
	capacity = capacity - 1;//该句为下面数据调整服务
	printf("请输入电梯1 和电梯2 的初始楼层\n\n");
	scanf_s("%d %d", &f1, &f2);
	int comein;
	while (usedspace >= 1)
	{
		printf("请输入要坐电梯的人数\n\n");
		scanf_s("%d", &comein);
		int a[100][2];//变量comein非常量，直接把长度设为100
		printf("请依次输入他们的起始楼层和目标楼层\n\n");
		for (int i = 1; i <= comein; i++)
		{
			printf("起始");
			scanf_s("%d", &a[i][1]);
			printf("目标");
			scanf_s("%d", &a[i][2]);
			if (a[i][1] == a[i][2])
			{
				printf("数据重复，已删除\n");// 小提示
			}
		}//数据输入“内存a”
		for (int n = 1; n <= comein; n++)
		{
			if (a[n][1] == a[n][2]) {}//对输入目标楼层与起始楼层相同的数据组删除，提高程序容错
			else
			{
				for (int m = 1; m <= 100; m++)
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
			}
		}//数据从a转如all储存
		for (int i1 = 1; i1 <= 100; i1++)
		{
			if (all[i1][5] == 1)
			{
				if (all[i1][2] == f1 && all[i1][3] == 1)
				{
					all[i1][3] = 0;
					all[i1][5] = 0;
				}//电梯1下客
				if (all[i1][2] == f2 && all[i1][4] == 1)
				{
					all[i1][4] = 0;
					all[i1][5] = 0;
				}//电梯2下客
			}
		}//电梯下客
		sum1 = 0;
		sum2 = 0;
		for (int t = 1; t <= 100; t++)
		{
			if (all[t][5] == 1)
			{
				sum1 = sum1 + all[t][3];
				sum2 = sum2 + all[t][4];
			}
		}//计算下乘客后的总人数
		for (int j = 1; j <= 100; j++)
		{
			if (sum1 <= capacity)//限载4人
			{
				if (all[j][5] == 1)
				{
					if (all[j][1] == f1 && all[j][3] == 0 && all[j][4] == 0)
					{
						all[j][3] = 1;
						sum1 = sum1 + 1;
						//printf("w");
					}
				}
			}
		}//上乘客数据更新
		for (int j = 1; j <= 100; j++)
		{
			if (sum2 <= capacity)
			{
				if (all[j][5] == 1)
				{
					if (all[j][1] == f2)
					{
						if (all[j][3] == 0)
						{
							if (all[j][4] == 0)
							{
								all[j][4] = 1;
								sum2 = sum2 + 1;
								// printf("w");
							}
						}
					}
				}
			}
		}
		usedspace = 0;
		for (int g = 1; g <= 100; g++)
		{
			usedspace = usedspace + all[g][5];
		}//计算已使用内存
		time++;
		printf("时间%d             电梯1的位置%d          人数%d\n", time, f1, sum1);
		printf("时间%d             电梯2的位置%d          人数%d\n", time, f2, sum2);
		printf("已使用内存%d\n", usedspace);
		//制作图视
		int p[11][3];//1，2表是上下行人数
		for (int y = 1; y <= 10; y++)
		{
			p[y][1] = 0;
			p[y][2] = 0;
		}
		for (int c = 1; c <= 10; c++)
		{
			for (int g = 1; g <= 100; g++)
			{
				if (all[g][5] == 1)
				{
					if (all[g][1] == c && all[g][3] == 0 && all[g][4] == 0)
					{
						if (all[g][1] - all[g][2] < 0)
						{
							p[c][1] = p[c][1] + 1;
						}
						if (all[g][1] - all[g][2] > 0)
						{
							p[c][2] = p[c][2] + 1;
						}

					}
				}
			}
		}//得出每层楼的数据
		for (int t = 1; t <= 10; t++)
		{
			int e;
			e = 11 - t;
			if (f1 == e)
			{
				printf("一%d", sum1);
			}
			if (f2 == e)
			{
				printf("二%d", sum2);
			}
			printf("楼层%d   上%d  下%d\n", e, p[e][1], p[e][2]);
		}
		//使用高峰期，防止电梯上下无限抖动优化,正在进行项目！！！
		//人多需要加强电梯方向不变的执行力
		up1 = 0;
		up2 = 0;
		down1 = 0;
		down2 = 0;
		for (int h = 1; h <= 100; h++)
		{
			if (all[h][5] == 1)
			{
				int a1, a2, b1, b2;
				a1 = f1 - all[h][1] < 0 && all[h][3] == 0;
				a2 = f1 - all[h][2] < 0 && all[h][3] == 1;
				b1 = f1 - all[h][1] > 0 && all[h][3] == 0;
				b2 = f1 - all[h][2] > 0 && all[h][3] == 1;//对电梯一数据处理
				up1 = up1 + a1 + 3 * a2;//优先送电梯内乘客
				down1 = down1 + b1 + 3 * b2;
				a1 = f2 - all[h][1] < 0 && all[h][4] == 0;
				a2 = f2 - all[h][2] < 0 && all[h][4] == 1;
				b1 = f2 - all[h][1] > 0 && all[h][4] == 0;
				b2 = f2 - all[h][2] > 0 && all[h][4] == 1;//对电梯二数据处理
				up2 = up2 +  a1 + 3 * a2;//优先送电梯内乘客
				down2 = down2 + b1 + 3 * b2;
			}
		}//计算上下行系数
		int k = 2;
		if (k * up1 >= down1)//定义电梯一为优先上行电梯
		{
			f1 = f1 + 1;
		}
		if (k * up1 < down1)
		{
			f1 = f1 - 1;
		}
		if (up2 >= k * down2)//定义电梯二为优先下行电梯
		{
			f2 = f2 + 1;
		}
		if (up2 < k * down2)
		{
			f2 = f2 - 1;
		}
	}
	return 0;
}