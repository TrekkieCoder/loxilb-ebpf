[![eBPF Emerging Project](https://img.shields.io/badge/ebpf.io-Emerging--Project-success)](https://ebpf.io/projects#loxilb) ![gpl](https://img.shields.io/badge/license-GPL-blue.svg)  ![bsd](https://img.shields.io/badge/license-BSD-blue.svg)
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FTrekkieCoder%2Floxilb-ebpf.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2FTrekkieCoder%2Floxilb-ebpf?ref=badge_shield)

## This README is here for anyone who wants to build loxilb ebpf only modules

## Install Dependencies

sudo apt install clang llvm libelf-dev gcc-multilib libpcap-dev  
sudo apt install linux-tools-$(uname -r)  
sudo apt install elfutils dwarves  

## Build libbpf

cd libbpf/src  
sudo make install  
sudo ldconfig  

## Build loxilb ebpf

cd -   
make  


## License
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FTrekkieCoder%2Floxilb-ebpf.svg?type=large)](https://app.fossa.com/projects/git%2Bgithub.com%2FTrekkieCoder%2Floxilb-ebpf?ref=badge_large)