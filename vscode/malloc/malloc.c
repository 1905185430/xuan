#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int len;
    char *buffer = NULL;
    srand(time(0));
    printf("你想要多长的字符串？");
    scanf("%d",&len);

    buffer = (char*) malloc(len+1);
    /*在C语言中，'buffer＝（char）malloc（len+1）'这行代码是动态分配内存的意思。
    'malloc'函数会为len+1字节的内存分配空间，并返回指向这块内存的指针。这里把返
    回的指针强制转换为'char'类型，然后赋值给变量'buffer'。这样，'buffer'就指向
    了新分配的内存区域。注意，新分配的内存区域的大小是len+1，是为了在C语言中存储
    一个以NULL结尾的字符串（C字符串）。*/

    /*（char）是C语言中的类型转换操作，它把malloc函数返回的void指针转换为char指
    针。在C语言中，void指针可以理解为能够指向任何类型数据的指针，但如果你想直接用
    printf函数打印这个指针的值，或者想对它进行一些特定的操作，就需要把它转换为具
    体的类型，比如这里的'char'。*/

    if(buffer == NULL) exit (1);

    /*在C语言中，'exit(1)'是终止程序运行的函数调用。这个函数属于stdlib.h头文件
    。exit函数接受一个整数参数，通常用于返回程序执行的状态。在多数系统中，0表
    示成功，非0值表示错误。参数1通常用于表示程序异常终止或出现错误。*/

    for (int i = 0; i < len ; i++)
    buffer[i] = rand() % 26 + 'a';

    /*这段代码在C语言中表示生成一个随机的ASCII字符。rand() % 26会生成一个介于0
    到25之间的随机整数（包含0和25）。然后，这个随机数被加到字符'a'的ASCII值上。
    因此，最终的结果是一个介于'a'（ASCII值为97）和'z'（ASCII值为122）之间的随
    机字符。*/

    buffer[len] = '\0';

    printf("随机串：%s\n",buffer);
    free(buffer);

    return 0;
    
}