# XV6 Project 

## Introduction
### What is xv6?
Xv6 is a teaching operating system developed in the summer of 2006 for MIT's operating systems course. 
For many years, MIT had no operating systems course. In the fall of 2002, one was created to teach operating systems engineering. In the course lectures, the class worked through Sixth Edition Unix (aka V6) using John Lions's famous commentary. In the lab assignments, students wrote most of an exokernel operating system, eventually named Jos, for the Intel x86. Exposing students to multiple systems–V6 and Jos–helped develop a sense of the spectrum of operating system designs.
V6 presented pedagogic challenges from the start. Students doubted the relevance of an obsolete 30-year-old operating system written in an obsolete programming language (pre-K&R C) running on obsolete hardware (the PDP-11). Students also struggled to learn the low-level details of two different architectures (the PDP-11 and the Intel x86) at the same time. By the summer of 2006, MIT had decided to replace V6 with a new operating system, xv6, modeled on V6 but written in ANSI C and running on multiprocessor Intel x86 machines. Xv6's use of the x86 makes it more relevant to students' experience than V6 was and unifies the course around a single architecture. Adding multiprocessor support requires handling concurrency head on with locks and threads (instead of using special-case solutions for uniprocessors such as enabling / disabling interrupts) and helps relevance. Finally, writing a new system allowed MIT to write cleaner versions of the rougher parts of V6, like the scheduler and file system. 6.828 substituted xv6 for V6 in the fall of 2006. <br />
For more information use link below : <br />
https://pdos.csail.mit.edu/6.828/2012/xv6.html
### Why xv6? 
Xv6 operating system is used as a programming project in most of the well-known universities such as MIT, Columbia, etc… . 
But the main reason we chose xv6 is that we want students to engage with kernel programming and we want them to learn how to develop an operating system so that if you start working in a team, developing operating system you would probably know the ups and downs. Another reason for choosing xv6 is that, what is taught throughout the course can be used to make some crucial modifications in this operating system and that is what we want you to do.


#### This project is divided into three phases: 

- In the first phase we added some system calls in order to understand how system calls are implemented in xv6 operating system.
- The second phase was about working with threads and realizing it's difference verses processes.
- The third phase was much more complicated which was based on CPU scheduling, we implemented RR (Round Robin) algorithm ,preemptive priority scheduling algorithm ,preemptive multilevel queue scheduling algorithm and lottery algorithm in xv6 operating system.


#### Instructor: 
[Dr.Seyyed Ahmad Javadi](https://github.com/sajavadi) <br />

#### Implemented by: 
 - [Hosna Oyarhosseini](https://github.com/hosnahoseini) <br />
 - [Samin Mahdipour](https://github.com/precioux) <br />

#### Spring 2022 - Amirkabir University of Technology
