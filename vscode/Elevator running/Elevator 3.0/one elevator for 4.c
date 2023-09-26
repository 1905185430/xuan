#include <stdio.h>
int main()
{
	int a[4][4];//1代表初始位置，2代表目标位置，3代表在不在电梯（1表示在） ,4为结束系数（0表示结束） 
	int b[4];//等于上行下行运算参数 
	int over=0;//over为判断电梯是否结束运行的系数，“over值计算有bug” 
	int floor;
	int sum;//sum为电梯总人数 
	printf("请输入电梯的起始位置\n");
	scanf("%d",&floor);
	int up,down;//up down为电梯上下行判断系数 
	printf("请输入ABCD四名乘客的起始位置\n");
	for(int i1=1;i1<=4;i1++)
	{
		scanf("%d",&a[1][i1]);
		a[3][i1]=0; 
		a[4][i1]=1; 
	}
	printf("请输入ABCD四名乘客的目标位置\n");
	for(int i2=1;i2<=4;i2++)
	{
		scanf("%d",&a[2][i2]);
	}
	for(int n=1;n<=10;n++)
	{
		
		for(int i4=1;i4<=4;i4++)//先上下乘客 
		{ 
			if(floor==a[1][i4]&&a[3][i4]==0&&a[4][i4]==1)//该循环表示乘客上 
			{
				a[3][i4]=1;
				printf("%d\n",a[3][i4]);
			}
		}//上电梯没问题 
		for(int i5=1;i5<=4;i5++)
		{
			if(floor==a[2][i5])
			{
				if(a[3][i5]==1)
				{
					a[3][i5]=0;
					a[4][i5]=0;
					printf("w\n");
				}
			}
		} 
		
		
		over=a[4][1]+a[4][2]+a[4][3]+a[4][4];
	    
		sum=a[3][1]+a[3][2]+a[3][3]+a[3][4];
		
	    printf("%d  楼层%d    总人数%d   over值%d\n",n,floor,sum,over);
	    
	    up=0;down=0;
	    for(int i3=1;i3<=4;i3++)//up down电梯上下行判断系数的计算 
	    {
	    b[i3]=((floor-a[2][i3])<=0&&a[3][i3]==1)+((floor-a[1][i3]<=0)&&(a[3][i3]==0)&&(a[4][i3]==1));
	    up=up+b[i3];
	    b[i3]=((floor-a[2][i3])>=0&&a[3][i3]==1)+((floor-a[1][i3]>=0)&&(a[3][i3]==0)&&(a[4][i3]==1));
	    down=down+b[i3]; 
	    } 
	    printf("上 %d  下  %d\n",up,down);
	    
		if(up<down)
		{
			floor=floor-1;
		}
		else
		{
			floor=floor+1;
			
		}
	}
	return 0;
} 