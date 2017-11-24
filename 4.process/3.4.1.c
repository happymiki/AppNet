/*************************************************************************
	> File Name: 3.4.1.c
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Nov 2017 10:48:53 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
void func1(void)
{
    printf("func1.\n");

}

int main(void)
{
    printf("hello world.\n");


	// 当进程被终止时，系统会自动调用这里注册的func1执行
    atexit(func1);
	//atexit(func2);
	
	printf("my name id limei hanmeime.\n");

    return 0;
}
