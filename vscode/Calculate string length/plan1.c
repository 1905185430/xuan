#include <stdio.h>
int length (char *string);
int main(void)
{
    int m;
    char a[20];
    gets(a);
    m=length(a);//a是一个字符型指针
    printf("The length of string is %d",m);
    return 0;
}

int length (char *string)
{
    int i=0;
    while (string[i]!='\0')
    i++;
    return (i);
}