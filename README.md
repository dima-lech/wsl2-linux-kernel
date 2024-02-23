# wsl2-linux-kernel

## Kernel Version

Using linux-msft-wsl-5.15.146.1.tar.gz

## Build

```
make KCONFIG_CONFIG=Microsoft/config-wsl
```


## Install

In Windows user directory:
1. Add file .wslconfig
2. Insert path in .wslconfig
	```
	[wsl2]
	kernel=C:\\Users\\Dima\\bzimage
	```

Full instructions at
https://learn.microsoft.com/en-us/windows/wsl/wsl-config#wslconfig




