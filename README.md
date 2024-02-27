# wsl2-linux-kernel

Building the WSL kernel is not required to work in WSL, however it could be considered an intro exercise to kernel building in general.

Default kernel supplied with WSL is somewhat limited, for example loading kernel modules is not supported. Rebuilding the kernel as specified below will add this feature.

***NOTES***:
* Files provided in this repository are only examples for scripts, configurations and sources for implementing the instructions below. Their usage is not required. It is **very recommended** to follow the instructions here and perform each step manually.
* WSL**2** is required.


## Kernel Version

WSL kernel versions can be obtained from:
> https://github.com/microsoft/WSL2-Linux-Kernel/releases
> 
These instructions were tested with version: linux-msft-wsl-5.15.146.1.tar.gz

## Retrieve sources
Download sources
```
wget https://github.com/microsoft/WSL2-Linux-Kernel/archive/refs/tags/linux-msft-wsl-5.15.146.1.tar.gz
```
Extract archive using `tar` command
* *x* = extract
* *v* = verbose
* *f* = file
```
tar -xvf linux-msft-wsl-5.15.146.1.tar.gz
```
Change into directory
```
cd WSL2-Linux-Kernel-linux-msft-wsl-5.15.146.1
```

## Build

Run `make` command
* *KCONFIG_CONFIG* chooses wsl-specific settings
* *-j* = number of concurrent jobs
* *\`nproc\`* = returns number of processor cores for optimal build time, for example substitutes it with *8*
```
make KCONFIG_CONFIG=Microsoft/config-wsl -j`nproc`
```

Install modules and headers
```
sudo make modules_install headers_install
```

Output image will be located in:
> arch/x86/boot/bzImage


## Install

1. In Windows user directory: add file *.wslconfig*
2. Copy *bzImage* output to the same user directory: Linux files can be accessed in Windows via the following path
> \\\\wsl$

3. Insert path to *bzImage* in *.wslconfig* (**make sure to keep double slashes and not have extra spaces!**)
	```
	[wsl2]
	kernel=C:\\Users\\UserName\\bzimage
	```
4. To close all wsl instances, run in **Windows** cmd as administrator:
	```
	wsl --shutdown
	```
5. Run wsl


Full instructions can be found here:
> https://learn.microsoft.com/en-us/windows/wsl/wsl-config#wslconfig


## More Advanced Topics

### Kernel Configuration

Kernel can be configured as needed to add or remove features.

To open kernel configuration menu, perform in kernel source directory:
```
make KCONFIG_CONFIG=Microsoft/config-wsl menuconfig
```
Navigate through menu and make custom selections, then save config and exit. Afterward perform **Build** and **Install** according to instructions above.

#### Example: Set Custom Version Name

In menu, navigate to:
> General setup --> Local version - append to kernel release
<img src="img/kernel-config-name1.png" alt="drawing" width="600"/>

Enter custom string:

<img src="img/kernel-config-name2.png" alt="drawing" width="600"/>

Save configuration and exit

Build and install the kernel

Verify version using:
```
uname -r
```
<img src="img/kernel-config-name3.png" alt="drawing" width="300"/>


### Kernel Module Build

Kernel module can be used to add a specific feature into the kernel, for example: implement a device driver.

In WSL case, to build a kenel module execute the following in source code directory:
```
make -C path/to/WSL2-Linux-Kernel-linux-msft-wsl-5.15.146.1 M=$(pwd) modules
```

