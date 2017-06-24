#include <stdio.h>
#include <syscall.h>
#include <stdlib.h>
 
 #define filosofos 5

 int main(int argc UNUSED,char * argv[]){
    int LOCK = 0;
    int pensando = 0;
    unsigned int value = 0;
    int filosofoID = atoi(argv[1]);
    while(1){
    
        if(!pensando){
            semaphore_wait(LOCK);
            semaphore_wait(filosofoID);
            int palilloDos = (filosofoID+1) % filosofos;
            if(palilloDos == 0)
                palilloDos = filosofos;
            semaphore_wait(palilloDos);
            printf("Filosofo %d agarro los palillo %d y %d\n", filosofoID, filosofoID ,palilloDos);
            printf("Filosofo %d esta Comiendo\n", filosofoID);
            semaphore_post(filosofoID);
            semaphore_post(palilloDos);
            semaphore_post(LOCK);
            pensando = 1;
        }else{
            printf("Filosofo %d esta pensando\n", filosofoID);
            value = random_uint();
            while(value > 0){
                value--;
            }
            printf("Filosofo %d tiene Hambre\n", filosofoID);
            pensando = 0;
        }

    }

 }