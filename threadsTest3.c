#include "types.h"
#include "stat.h"
#include "user.h"
int base, limit;

void function(void *args){
    base ++;
    printf(1, "Base = %d, Limit = %d\n", base, limit);

    if(base >= limit){
        exit();
    }else{
        int argument = 0x0F01;
        int thread_id = thread_creator(&function, (void *)&argument);
        int result = thread_join(thread_id);
        
        if(result == -1)
            printf(1, "[ID] %d => [Failed] -1\n", thread_id);
        else
            printf(1, "[ID] %d => [Success] 0\n", thread_id);
    }
}

int main(void){    
    int argument = 0x0F01;
    limit = 7;
    int id =thread_creator(&function, (void *)&argument);
    thread_join(id);
    printf(1, "Done! \nBase = %d, Limit = %d\n", base, limit);

    exit();
}