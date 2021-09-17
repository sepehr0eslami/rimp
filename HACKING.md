# Dependencies
Before you start coding, you will need to install some dependencies:

## Windows

Download and Install the latest version of [Git](https://git-scm.com/downloads), [CMake](https://cmake.org/download/), and a C++ compiler of choice. 

> ⚠️ This Project heavily relies on features of C++17, so make sure you compiler support C++17 (or newer).

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
## Compilation flags

In addition to the default CMake flags, this compilation option is available too:

### cmake -DCOMP_INSTALL=[ON|OFF]

Determine whether to install Shell Completion scripts alongside rimp executable or not. These scripts will enable tab-completion for the subcommands, tag names, paths, etc.

By default this flag is set to `ON`, i.e., Completion scripts will be installed.

# Installation
After building the source code, you can install `rimp` by running:

## Windows
Run CMD or Powershell as Administrator and then run the following command:

```sh
cmake --install build --config Release
```

Now all you have to do is adding the Installation Folder (`C:\Program Files(x86)\rimp\bin`)to the PATH environment variable (You can google how to do it or get help from this [Link](https://www.c-sharpcorner.com/article/add-a-directory-to-path-environment-variable-in-windows-10/)). Now close your terminal and open it again and make sure `rimp` is correctly installed by running:

```sh
$ rimp --version

Rimp X.X.X.
```

## MacOS and Linux

```sh
sudo cmake --install build --config Release

$ rimp --version

Rimp X.X.X.
```

# Tab-Completion

After the Installation, Completion scripts are installed for available shells on your computer. Available shells are read from `/etc/shells` file.

> Since Powershell doesn't support Programmable Completions (or at least I don't know how), Tab-Completion isn't available on Windows.

**ZSH**: The completion system needs to be activated. If you’re using something like `oh-my-zsh` then this is already taken care of, otherwise you’ll need to add the following to your `.zshrc`

```sh
autoload -U compinit
compinit
```
**Fish**: Just reload your shell and you are good to go.

**Bash**: Add the following line to your `.bashrc` to load the script at shell startup:

```sh
[ -r /usr/share/bash-completion/completions/rimp ] && source /usr/share/bash-completion/completions/rimp
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
