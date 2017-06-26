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
    while(i>0)
    {
        //semaphore_wait(FULL);
        mutex_lock(FULL);
        printf("Consumer :%d has consumed\n",ConsumidorID);
        mutex_unlock(EMPTY);
        //semaphore_post(EMPTY);
        i--;
    }
    
 }
