# Installation

SLAC doesn't have any precompiled binaries so you'll have to compile yourself, this is temporary in the future precompiled binaries will be providade.

## Dependecies
All you need to compile is the [GCC compiler](https://gcc.gnu.org/)

First thing you need to do is clone the github repository using the following command:
```bash
git clone https://github.com/YuBlum/slac
```

After cloning the repo `cd` into the *slac* directory. Now is more OS-specifc.

## Linux

Simply run the following command and it'll be compiled and installed into your system.
```bash
sudo make install
```

## Windows

For now SLAC uses only Makefiles for the installation, but in the future there will be a Windows specific installation.

