//利用指针遍历数组
//当P+5时输出的是0
#include <stdio.h>
int main()
{
    int a[5]={0,1,2,3,4};
    int *p = a;
    int i = 0;
    for(i=0;i<5;i++)
    {
        printf("%d ",*(p+i));
    }
    return 0;
}