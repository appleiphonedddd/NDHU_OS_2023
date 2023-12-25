#include "types.h"
#include "stat.h"
#include "user.h"

  
int totalTurnaround;
int totalWaiting;
int totalBurst;
int i[7];
int pp[7][6];

int get_tickets(int pid){
    for(int k =1; k <7; k++)
        for(int j=0; j < i[k]; j++)
            if(pp[k][j] == pid)
                return k;
    return 0;
}

int main(void){
  int pid;
  int retime;
  int rutime;
  int stime;
  changePolicy(3);
  printf(1, "priority Test \n");

  for(int n=0; n<30; n++){
      pid = fork();
      if(pid < 0)
        break;
      if(pid != 0){
        if(n < 5){
            changeTickets(30, pid);
            pp[6][i[6]++] = pid;
        }
        if(n >= 5 && n < 10){
            changeTickets(25, pid);
            pp[5][i[5]++] = pid;
        }
        if(n >= 10 && n < 15){
            changeTickets(20, pid);
            pp[4][i[4]++] = pid;

        }
        if(n >= 15 && n < 20){
            changeTickets(15, pid);
            pp[3][i[3]++] = pid;

        }
        if(n >= 20 && n < 25){
            changeTickets(10, pid);
            pp[2][i[2]++] = pid;

        }
        if(n >= 25){
            changeTickets(5, pid);
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
        int waitingTime = retime;
        int sleeping = stime;
        int cpuBurst = rutime;
        int turnAround = waitingTime + sleeping + cpuBurst;
        totalTurnaround += turnAround;
        totalWaiting += waitingTime;
        totalBurst += cpuBurst;

        printf(1, "PID: %d | Tickests: %d | Turnaround Time: %d | Waiting Time: %d"
                  " | CPU Burst Time: %d | Sleeping Time: %d\n", pid, 5*get_tickets(pid), turnAround, waitingTime, cpuBurst, sleeping);
    }


    totalTurnaround = totalTurnaround / 30;
    totalWaiting = totalWaiting / 30;
    totalBurst = totalBurst / 30;
    
    printf(1, "average turnaround: %d waiting: %d burst: %d \n", totalTurnaround, totalWaiting, totalBurst);

    
    exit();
}
