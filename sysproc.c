#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"


int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getTicks(void)
{
  return getTicks();
}

int
sys_getProcInfo(void)
{
  return getProcInfo();
}

int
sys_thread_create(void)
{

  int stackptr = 0;
  if(argint(0, &stackptr) < 0) //to pass an integer value to a kernel level function
    return -1;
  return thread_create((void *)stackptr);
}

int
sys_thread_join(int input_pid)
{
  argint(0,&input_pid);
  return thread_join(input_pid);
}

int
sys_thread_id(void)
{
  return thread_id();
}

int
sys_getctime(void)
{
  int pid;
  argint(0, &pid);
  return (int)getctime(pid);
}

int
sys_getttime(void)
{
  int pid;
  argint(0, &pid);
  return getttime(pid);
}

int
sys_getrutime(void)
{
  int pid;
  argint(0, &pid);
  return getrutime(pid);
}

int
sys_getProcStatus(void){
    int type, pid;
    if(argint(0, &type) < 0 || argint(1, &pid) < 0)
        return -1;
    return getProcStatus(type, pid);
}

int
sys_getPriority(void){
  int pid;
  argint(0, &pid);
  return getPriority(pid);
}

int 
sys_setPriority(void)
{
  int priority, pid;
  argint(0, &priority);
  argint(1, &pid);
  return setPriority(priority, pid);
}

int
sys_changePolicy(void)
{
  int schedNum;
  argint(0, &schedNum);
  return changePolicy(schedNum);
}

int 
sys_changeTickets(void)
{
  int tickets, pid;
  argint(0, &tickets);
  argint(1, &pid);
  return changeTickets(tickets, pid);
}

/*
  this is the actual function being called from syscall.c
  @returns - pidof the terminated child process ‐ if successful
­             -1, upon failure
*/
int sys_wait2(void) {
  int *retime, *rutime, *stime;
  if (argptr(0, (void*)&retime, sizeof(retime)) < 0)
    return -1;
  if (argptr(1, (void*)&rutime, sizeof(retime)) < 0)
    return -1;
  if (argptr(2, (void*)&stime, sizeof(stime)) < 0)
    return -1;
  return wait2(retime, rutime, stime);
}
