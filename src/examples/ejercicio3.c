#include <stdio.h>
#include <syscall.h>
 
 int main(int argc UNUSED,char * argv[] UNUSED)
 {
    int i;
    int pid[4];

    semaphore_init(0, 1); //READER_SEMA
    semaphore_init(1, 1); //CONTROL TO DB

    pid[0] = exec("writer 1");
    pid[1] = exec("writer 2");
    pid[2] = exec("reader 3");
    pid[3] = exec("reader 4");
    

    for(i=0;i<4;i++)
        wait(pid[i]);
    
 }