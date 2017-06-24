#include <stdio.h>
#include <syscall.h>
#include <stdlib.h>
 
 int main(int argc UNUSED,char * argv[])
 {
    int WRITERID = atoi(argv[1]);
    int DATABASE = 1;
    int i = 100;
    while(i>0)
    {  
        printf("Writer %d is trying to enter the file\n", WRITERID);
        semaphore_wait(DATABASE);
        printf("Writer %d is writing the file\n", WRITERID);
        semaphore_post(DATABASE);
        i--;
    }
 }