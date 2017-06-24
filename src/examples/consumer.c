#include <stdio.h>
#include <syscall.h>
#include <stdlib.h>

 int main(int argc UNUSED,char * argv[])
 {
    unsigned int value;
    int ConsumidorID = atoi(argv[1]);
    int FULL = 0;
    int EMPTY = 1;
    int i = 100;
    int j = 10000000;
    while(i>0)
    {
        semaphore_wait(FULL);
        printf("Consumer :%d has consumed\n",ConsumidorID);
        while(j>0)
        j--;

        semaphore_post(EMPTY);
        i--;
    }
    
 }
