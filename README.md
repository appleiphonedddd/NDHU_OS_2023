![license](https://img.shields.io/github/license/DVLab-NTU/qsyn?style=plastic)
![stars](https://img.shields.io/github/stars/DVLab-NTU/qsyn?style=plastic)
![contributors](https://img.shields.io/github/contributors/DVLab-NTU/qsyn?style=plastic)
![release-date](https://img.shields.io/github/release-date-pre/DVLab-NTU/qsyn?style=plastic)
![pr-welcome](https://img.shields.io/badge/PRs-welcome-green?style=plastic)
![g++-10](https://img.shields.io/badge/g++-≥10-blue?style=plastic)
![clang++-16](https://img.shields.io/badge/clang++-≥16-blueviolet?style=plastic)

# NDHU_Operating_system_engineering_2023

---

## Introduction
`NDHU_Operating_system_engineering` project belongs to the 2023 Data Structures Lab at National Dong Hwa University. It encompasses various implementations and examples of data structures, aiming to assist students in better understanding and practicing data structures.

## Getting Started

### System Requirements

`NDHU_Operating_system_engineering` requires `c18` to build. We support `gcc` to complie. 

### Installation

Clone the repository to your local machine by running

```shell!
https://github.com/appleiphonedddd/NDHU_Operating_system_engineering_2023.git
cd NDHU_Operating_system_engineering_2023
```
Install QEMU

```shell!
sudo apt-het update
sudo apt-get install qemu-system-i386 -y
```

Setting environment path for QEMU

```shell!
vim ~/.bashrc
```

Add the context in last line

```shell!
export PATH=$PATH:/usr/bin
```

Apply path

```shell!
source ~/.bashrc
```

Go back to repository then complie Makefile

```shell!
make qemu-nox
```

