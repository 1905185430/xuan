#include <stdio.h>
#include <string.h>
int main(void)
{
    char string[66];
    char *p;
    p=string;
    int length;
    gets(string);
    length=strlen(string);
    for (int i=0;i<=length;i++)
    {
        printf("%c",*(p+length-i));
    }
    return 0;
}