#!/bin/bash

cd WSL2-Linux-Kernel-linux-msft-wsl-5.15.146.1 && make -j6 KCONFIG_CONFIG=Microsoft/config-wsl 
