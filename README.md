# wsl2-linux-kernel

## Kernel Version

Using linux-msft-wsl-5.15.146.1.tar.gz

## Build

```
make KCONFIG_CONFIG=Microsoft/config-wsl
```
Output in:
> arch/x86/boot/bzImage


## Install

1. In Windows user directory: add file .wslconfig
2. Insert path in .wslconfig
	```
	[wsl2]
	kernel=C:\\Users\\Dima\\bzimage
	```
3. In Windows cmd:
	```
	wsl --shutdown
	```
4. Run wsl


Full instructions at
https://learn.microsoft.com/en-us/windows/wsl/wsl-config#wslconfig




