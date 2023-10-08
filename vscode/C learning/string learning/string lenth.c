#include <stdio.h>
int length (char *string)
int main()
{
    int m;
    char a[20];
    gets(a);
    m=length(a);
    printf("The length of string a is %d\n",m);
    return 0;
}
    


int length (char *string)
{
    int i=0;
    while (string[i]!='\0')
    {
        i++;
    }
    return(i);
}