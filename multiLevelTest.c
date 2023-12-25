#include "types.h"
#include "stat.h"
#include "user.h"

#define N  60

void callPriority(int priority[]){
   for(int n=0;n<60;n++){
            if(n < 10){
                priority[n]=6;
            }
            if(n >= 10 && n < 20){
                priority[n]=5;
            }
            if(n >= 20 && n < 30){
                priority[n]=4;
            }
            if(n >= 30 && n < 40){
                priority[n]=3;
            }
            if(n >= 40 && n < 50){
                priority[n]=2;
            }
            if(n >= 60){
                priority[n]=1;
            }
   }
}

int main(void){
  int n, pid;
  int size[] = {60, 10, 10, 10, 10, 10, 10};
  int priority[N];
  int retime;
  int rutime;
  int stime;
  callPriority(priority);
  changePolicy(2);
  printf(1, "Multi Level Test\n");

  for(n=0; n<N; n++){
        pid = fork();
        if(pid < 0)
            break;
        if(pid == 0){
            if(n < 10){
                setPriority(1, pid);
            }
            if(n >= 10 && n < 20){
                setPriority(2, pid);
            }
            if(n >= 20 && n < 30){
                setPriority(3, pid);
            }
            if(n >= 30 && n < 40){
                setPriority(4, pid);
            }
            if(n >= 40 && n < 50){
                setPriority(5, pid);
            }
            if(n >= 50){
                setPriority(6, pid);
            }
            for(int i=0 ; i<20 ; i++){
                printf(1, "/%d/ : /%d/ \n", pid, i+1);
            }
            sleep(3500);
            exit();
        }
    }
    int totalTurnaround[7];
    int totalWaiting[7];
    int totalBurst[7];


    for (int i = 0; i <60 ; ++i) {
        int pid = wait2(&retime, &rutime, &stime);
        int waitingTime = stime;
        int sleeping = retime;
        int cpuBurst = rutime;
        int turnAround = waitingTime+sleeping+cpuBurst;
        totalTurnaround[0] += turnAround;
        totalWaiting[0] += waitingTime;
        totalBurst[0] += cpuBurst;

        totalTurnaround[priority[i]] += turnAround;
        totalWaiting[priority[i]] += waitingTime;
        totalBurst[priority[i]] += cpuBurst;
        printf(1, "%d - PID: %d | Turnaround Time: %d | Waiting Time: %d"
                  " | CBT: %d | Sleeping Time: %d | Priority: %d\n",i+1, pid, turnAround, waitingTime, cpuBurst, sleeping,priority[i]);
    }

    for (int i = 0; i <7 ; ++i) {
        totalTurnaround[i] = totalTurnaround[i] / size[i];
        totalWaiting[i] = totalWaiting[i] / size[i];
        totalBurst[i] = totalBurst[i] / size[i];
    }
    printf(1, "average turnaround: %d waiting: %d burst: %d \n", totalTurnaround[0], totalWaiting[0], totalBurst[0]);
    for (int i=1;i<7;i++){
        printf(1, "priority: %d average turnaround: %d  waiting: %d  burst: %d \n",
               i, totalTurnaround[i], totalWaiting[i], totalBurst[i]);
    }
    exit();
}
