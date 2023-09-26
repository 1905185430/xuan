//随机生成指定长度的字符串
//malloc()和 free()的用法
//不懂
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int len;
    char *buffer=NULL;
    srand(time(0));
    printf("你想要多长的字符串");
    scanf("%d",&len);
    buffer = (char*) malloc(len+1);
    if(buffer == NULL) exit (1);

    for(int i=0;i<len;i++)
         buffer[i] = rand() % 26 + 'a';
    buffer[len] = '\0';

    printf("%s\n",buffer);
    free(buffer);
     
    return 0;
}