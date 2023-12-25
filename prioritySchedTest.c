#include "types.h"
#include "stat.h"
#include "user.h"

  
int totalTurnaround[7];
int totalWaiting[7];
int totalBurst[7];
int i[7];
int pp[7][6];

int get_priority(int pid){
    for(int k =1; k <7; k++)
        for(int j=0; j < i[k]; j++)
            if(pp[k][j] == pid)
                return k;
    return 0;
}

int main(void){
  int pid;
  int size[] = {30, 5, 5, 5, 5, 5, 5};
  int retime;
  int rutime;
  int stime;
  changePolicy(1);
  printf(1, "priority Test \n");

  for(int n=0; n<30; n++){
      pid = fork();
      if(pid < 0)
        break;
      if(pid != 0){
        if(n < 5){
            setPriority(6, pid);
            pp[6][i[6]++] = pid;
        }
        if(n >= 5 && n < 10){
            setPriority(5, pid);
            pp[5][i[5]++] = pid;
        }
        if(n >= 10 && n < 15){
            setPriority(4, pid);
            pp[4][i[4]++] = pid;

        }
        if(n >= 15 && n < 20){
            setPriority(3, pid);
            pp[3][i[3]++] = pid;

        }
        if(n >= 20 && n < 25){
            setPriority(2, pid);
            pp[2][i[2]++] = pid;

        }
        if(n >= 25){
            setPriority(1, pid);
            pp[1][i[1]++] = pid;

        }
      }
        if(pid==0){
            for(int i=0 ; i<250 ; i++){
                printf(1, "/%d/ : /%d/ \n", getpid(), i+1);
            }
            sleep(3500);
            exit();
        }
      }
      

    for (int i = 0; i <30 ; ++i) {
        // int pid = wait();
        int pid = wait2(&retime, &rutime, &stime);
        int waitingTime = stime;
        int sleeping = retime;
        int cpuBurst = rutime;
        int turnAround = waitingTime + sleeping + cpuBurst;
        totalTurnaround[0] += turnAround;
        totalWaiting[0] += waitingTime;
        totalBurst[0] += cpuBurst;
        // printf(1, "pid:%d, get priority: %d , %d\n", pid, get_priority(pid),getPriority(pid));
        totalTurnaround[get_priority(pid)] += turnAround;
        totalWaiting[get_priority(pid)] += waitingTime;
        totalBurst[get_priority(pid)] += cpuBurst;
        printf(1, "PID: %d | Priority: %d | Turnaround Time: %d | Waiting Time: %d"
                  " | CPU Burst Time: %d | Sleeping Time: %d\n", pid, get_priority(pid), turnAround, waitingTime, cpuBurst, sleeping);
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
