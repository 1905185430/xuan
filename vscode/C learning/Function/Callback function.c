#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int random(void)
{
    return rand() % 100;
}

int get_array ( int *array, size_t arraySize, int (*choose_value)(void))
{
    for (size_t i=0 ; i < arraySize ; i++ )
    {
        array[i] = choose_value();
    }
}

int main(void)
{
    int array[10];
    size_t myarraysize = sizeof(array) / sizeof(array[0]);
    get_array(array,myarraysize,random);
    printf("array字符串长度为%d\n",myarraysize);

    for (int i=0 ; i < myarraysize ; i++)
    {
        printf("%d\t",array[i]);
    }
    printf("%d\n",array[10]);

    return 0; 
}