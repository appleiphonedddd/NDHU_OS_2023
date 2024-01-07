# NDHU_Operating_system_engineering_2023

`NDHU_Operating_system_engineering_2023` project belongs to the Operating system engineering at National Dong Hwa University. The purpose of this project is to compile source code then create a Linux Operating system in QEMU system emulator, finally you can input linux command line in terminal

## Contents

- [Getting Started](#Getting-Started)
  - [Requirements](#Requirements)
  - [Installation](#Installation)
- [Directory Structure](#Directory-Structure)
- [Deployment](#Deployment)
- [Frameworks Used](#Frameworks-Used)
- [Author](#Author)


### Getting Started

###### Requirements

1. C18
2. Ubuntu 22.04
3. QEMU

###### **Installation**

1. Upgrade package

```sh
sudo apt-het update
```

2. Install QEMU

```sh
sudo apt-get install qemu-system-i386 -y
```

3. Setting environment path for QEMU

```sh
vim ~/.bashrc
```

4. Add the context in last line

```sh
export PATH=$PATH:/usr/bin
```

5. Save and quit vim then apply path

```sh
source ~/.bashrc
```

6. Clone the repo and enter repo folder

```sh
git clone https://github.com/appleiphonedddd/NDHU_Operating_system_engineering_2023.git
cd NDHU_Operating_system_engineering_2023
```

### Directory Structure

```
filetree 
├── asm.h
├── bio.c
├── bootasm.S
├── bootmain.c
├── buf.h
├── BUGS
├── cat.c
├── console.c
├── cuth
├── date.h
├── defs.h
├── dot-bochsrc
├── echo.c
├── elf.h
├── entryother.S
├── entry.S
├── exec.c
├── fcntl.h
├── file.c
├── file.h
├── forktest.c
├── fs.c
├── fs.h
├── gdbutil
├── getProcInfoTest.c
├── getTicksTest.c
├── grep.c
├── ide.c
├── init.c
├── initcode.S
├── ioapic.c
├── kalloc.c
├── kbd.c
├── kbd.h
├── kernel.ld
├── kill.c
├── lapic.c
├── LICENSE
├── ln.c
├── log.c
├── lotteryTest.c
├── ls.c
├── main.c
├── Makefile
├── memide.c
├── memlayout.h
├── mkdir.c
├── mkfs.c
├── mmu.h
├── mp.c
├── mp.h
├── multiLevelTest.c
├── Notes
├── param.h
├── picirq.c
├── pipe.c
├── printf.c
├── printpcs
├── prioritySchedTest.c
├── proc.c
├── proc.h
├── pr.pl
├── README.md
├── rm.c
├── roundRobinTest.c
├── runoff
├── runoff1
├── runoff.list
├── runoff.spec
├── sh.c
├── show1
├── sign.pl
├── sleep1.p
├── sleeplock.c
├── sleeplock.h
├── spinlock.c
├── spinlock.h
├── spinp
├── stat.h
├── stressfs.c
├── string.c
├── swtch.S
├── syscall.c
├── syscall.h
├── sysfile.c
├── sysproc.c
├── thread_creator.c
├── threadsTest1.c
├── threadsTest2.c
├── threadsTest3.c
├── toc.ftr
├── toc.hdr
├── trapasm.S
├── trap.c
├── traps.h
├── TRICKS
├── types.h
├── uart.c
├── ucalloc.c
├── ulib.c
├── umalloc.c
├── user.h
├── usertests.c
├── usys.S
├── vectors.pl
├── vm.c
├── wc.c
├── x86.h
└── zombie.c
```

### Deployment

Compile Makefile then you can input linux command line in terminal

```sh
make qemu-nox
```

### Frameworks Used

- [QEMU](https://www.qemu.org/)
- [MIT XV6](https://github.com/mit-pdos/xv6-riscv)
- [MIT XV6 official](https://pdos.csail.mit.edu/6.828/2023/xv6.html)
- [Multiprocessor Specification](https://github.com/x86-8/x86-8-docs/blob/master/SPEC/intel/24201606-Multiprocessor%20Specification.pdf)
- [IOAPIC](https://web.archive.org/web/20161130153145/http://download.intel.com/design/chipsets/datashts/29056601.pdf)
- [Other source code](https://github.com/kishanpatel22/xv6-kernel-threads/tree/master)

### Author

zozo5120@outlook.com

Name:Egor Lee
