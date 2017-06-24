#include <stdio.h>
#include <syscall.h>
#include <stdlib.h>
 
 int main(int argc UNUSED,char * argv[])
 {
     int READERID = atoi(argv[1]);
     int READER_COUNT = 0;
     int READER_SEMA = 0;
     int DATABASE = 1;
     int i = 100;
    while(i>0){ 

        printf("Reader %d is trying to read the file\n", READERID);
        semaphore_wait(READER_SEMA);
        READER_COUNT++;
        if(READER_COUNT == 1){
            semaphore_wait(DATABASE);
        }
        semaphore_post(READER_SEMA);
        /*CRITICAL SECTION START */
        printf("Reader %d is reading\n", READERID);
        /*CRITICAL SECTION END */
        semaphore_wait(READER_SEMA);
        READER_COUNT--;
        if(READER_COUNT == 0){
            semaphore_post(DATABASE);
        }
        semaphore_post(READER_SEMA);
        i--;
    }
 }