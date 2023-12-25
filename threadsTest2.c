#include "types.h"
#include "stat.h"
#include "user.h"
void childPrint(void *args){
    printf(1, "hi, childs function executed properly with argument: %d\n", *(int *) args);
    return;
}
int main(void){
    int argument = 0x0F01;
    int thread_id = thread_creator(&childPrint, (void *)&argument);
  
    if(thread_id < 0){
        printf(1, "thread_creator failed\n");
    }else{
        if(thread_id > 0){
            int c = thread_join(thread_id);
            printf(1, "child thread with id %d i done (join returns: %d)\n", thread_id, c);
        }
    }


    exit();
}