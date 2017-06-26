#include <stdio.h>
#include <syscall.h>
#include <stdlib.h>
 
 int main(int argc UNUSED,char * argv[])
 {
     unsigned int value;
     int ProducerID = atoi(argv[1]);
     int FULL = 0;
     int EMPTY = 1;
     int i = 100;
    while(i>0)
    {
        //semaphore_wait(EMPTY);
        mutex_lock(EMPTY);
        printf("Producer :%d is producing\n", ProducerID);
        mutex_unlock(FULL);
        //semaphore_post(FULL);
        i--;
    }
 }