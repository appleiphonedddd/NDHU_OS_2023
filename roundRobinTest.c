#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
      changePolicy(0);
      int children = 0;
      int retime;
      int rutime;
      int stime;
    for (int i = 0; i <10 ; i++) {
        int pid = fork();
        if ( pid == 0) {
            for (int i = 0; i < 1000; i++) {
                printf(1, "/%d/ : /%d/\n", getpid(), i);
            }
            sleep(2000);
            exit();
        }
        else children= children +1;
    }

    int sumTurnaround = 0;
    int sumWaiting = 0;
    int sumBurst = 0;


    for (int i = 0; i <10 ; i++) {
        int pid = wait2(&retime, &rutime, &stime);
        int waitingTime = stime;
        int sleeping = retime;
        int cpuBurst = rutime;
        int turnAround = waitingTime + sleeping+cpuBurst;
        sumTurnaround += turnAround;
        sumWaiting += waitingTime;
        sumBurst += cpuBurst;
        printf(1, "pid: %d, ", pid);
        printf(1, "turnaround time = %d, ", turnAround);
        printf(1, "waiting time = %d, ", waitingTime);
        printf(1, "sleeping time = %d, ", sleeping);
        printf(1, "cpu burst = %d, ", cpuBurst);
        printf(1,"\n");
        

    }
   
    int avgTurnaround =  sumTurnaround / 10;
    int avgWaiting =  sumWaiting / 10;
    int avgCBT = sumBurst / 10;
    printf(1, "\naverage turnaround time: %d\n",avgTurnaround);
    printf(1, "average waiting time: %d\n",avgWaiting);
    printf(1, "average cpu burst time: %d\n",avgCBT);
    exit();
}