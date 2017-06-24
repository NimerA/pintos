#include <stdio.h>
#include <syscall.h>
 
 int main(int argc UNUSED,char * argv[] UNUSED)
 {
    int i;
    int pid[4];

    semaphore_init(0, 1); //FULL
    semaphore_init(1, 1); //EMPTY

    pid[0] = exec("producer 1");
    pid[1] = exec("producer 2");
    pid[2] = exec("consumer 3");
    pid[3] = exec("consumer 4");

    for(i=0;i<4;i++)
        wait(pid[i]);
    
 }