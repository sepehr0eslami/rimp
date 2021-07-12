# Dependencies
Before you start coding, you will need to install some dependencies:

## Windows

Download and Install the latest version of [Git](https://git-scm.com/downloads), [CMake](https://cmake.org/download/), and a C++ compiler of choice. 

> :warning: This Project heavily relies on features of C++17, so make sure you compiler support C++17 (or later).

## MacOS

```sh
brew install git cmake make
```

## Linux

### Ubuntu, Debian and derivatives

```sh
sudo apt-get install git cmake build-essential 
```

### Red Hat, Fedora, CentOS and derivatives

```sh
sudo yum groupinstall 'Development Tools'
sudo yum install git cmake gcc gcc-c++ make
```

### Arch, Manjaro and derivatives

```sh
sudo pacman -S git cmake base-devel
```


# Compilation
Now clone the source code and compile it following the usual CMake compilation steps:

```sh
git clone https://github.com/sepehr0eslami/rimp.git
cd rimp
cmake -S. -B.//build -DCMAKE_BUILD_TYPE=Release
cmake --build build 
```

# Installation
After building the source code, you can install `rimp` by running:

```sh
sudo cmake --install build
rimp # Run Rimp
```

# Code Style

This project follows Google C++ Style Guide:

https://google.github.io/styleguide/cppguide.html

And uses clang-format, clang-tidy and `cpplint.py` automatically to check potential the code issues.

In order to take advantage of those tools, install the following dependencies:

## Windows

Download and Install the latest version of [Clang-format](https://llvm.org/builds/), [Clang-tidy](https://llvm.org/builds/), and [Python2](https://www.python.org/downloads/release/python-2718/).

## MacOS

```sh
brew install clang-format python
```

## Linux

### Ubuntu, Debian and derivatives

```sh
sudo apt-get install clang-format clang-tidy python2
```

### Red Hat, Fedora, CentOS and derivatives

```sh
sudo yum install clang clang-tools-extra python2
```

### Arch, Manjaro and derivatives

```sh
sudo pacman -S clang python2
```

More information about `cpplint.py`:

https://google.github.io/styleguide/cppguide.html#cpplint

# Development environment

You can use any text editor or IDE. But, if like me, you are using Visual Studio Code, here are some
tips:

## C/C++ Extension

Install this extension for language support:

https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools

## CMake Tools

Install this extension for CMake integration:

https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools

## Code Spell Checker Extension

Install this extension to avoid typos:

https://marketplace.visualstudio.com/items?itemName=streetsidesoftware.code-spell-checker

## Apply format on save

The best way to follow the code style rules is to let Visual Studio Code apply them for you.
add the following configuration to your settings.json file by
pressing "Control + Shift + P" and typing "Preferences: Open Settings (JSON)":

```
"editor.formatOnSave": true
```

# Contact the developer:

If you want to report a bug or ask a question, you can do it in the official bug tracker:

https://github.com/sepehr0eslami/rimp/issues

Happy coding!