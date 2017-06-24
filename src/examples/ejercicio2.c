#include <stdio.h>
#include <syscall.h>

#define filosofos 5
 
 int main(int argc UNUSED,char * argv[] UNUSED)
 {
    int i;
    int pid[filosofos];
    semaphore_init(0,0); //LOCK

    for(i=1;i<filosofos+1;i++) //FILOSOFOS 1 - 5
        semaphore_init(i,0);

    pid[0] = exec("philosopher 1");
    pid[1] = exec("philosopher 2");
    pid[2] = exec("philosopher 3");
    pid[3] = exec("philosopher 4");
    pid[4] = exec("philosopher 5");

    for(i=0;i<filosofos;i++)
        wait(pid[i]);
    
 }