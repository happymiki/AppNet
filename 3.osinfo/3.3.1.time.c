/*************************************************************************
	> File Name: 3.3.1.time.c
	> Author:miki 
	> Mail: 
	> Created Time: Wed 22 Nov 2017 08:14:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>

int main(void)
{
    
    time_t tNow = 0;
    
    tNow = time(NULL);
    
    if (tNow < 0)
    {
        perror("time");
        return -1;
    }
    printf("time: %ld.\n",tNow);


    return 0;
}
