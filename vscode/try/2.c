#include <stdio.h>
#include <string.h>
int sp(char *string,int length);
int main(void)
{
    int length;
    char string[1000];
    gets(string);
    length=strlen(string);
    sp(string,length);
    printf("%s",string);
    return 0;
}
int sp(char *string,int length)
{
    char s[1000];
    for (int i=0;i<=length;i++)
    {
        s[i]=string[length-i];
    }
    for (int i=0;i<=length;i++)
    {
        string[i]=s[i];
    }
    return 0;
}