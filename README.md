<p align="center">
    <a href="https://github.com/sepehr0eslami/rimp"><img alt="Rimp Logo" src=".github/images/rimp_logo.png" height="120"></a>
    <p align="center">Command-Line File/Folder Tagging tool for Lazy people</p>
    <p align="center">
        <a href="LICENSE.md"><img alt="Software License" src="https://img.shields.io/badge/License-GPL%20v3-blue"></a>
        <a href="https://github.com/sepehr0eslami/rimp/actions/workflows/build.yml"><img alt="Build Status" src="https://github.com/sepehr0eslami/rimp/actions/workflows/build.yml/badge.svg"></a>
        <a href="https://github.com/sepehr0eslami/rimp"><img alt="Supported Platforms" src="https://img.shields.io/badge/Platforms-Windows%20|%20MacOS%20|%20Linux-red"></a>
    </p>
</p>

---

# Rimp(Reimplementer)

`rimp` is a Cross-Platform command-line tool which makes working with files/folders you need regularly much easier, by allowing you to tag and access them in the future using only their tags.


## Why?

I wanted a tool that allows you to:

- Tag files/folders using the command line.

- Paste those files/folders elsewhere with one simple command.

- Remove or update an existing tag.

- List previously added Tags and the Path they point to, prettily formatted.

- Use proper Tab Completion in any modern Shell

# Installation

## Windows

To run this application, you just need SQLite3. [Download](https://www.sqlite.org/download.html) the latest version of SQLite3 for Windows, then extract it and move `sqlite3.dll` to `C:\System32`.

Now, create a folder called `rimp`, containing another folder called `bin`, in `C:\Program Files(x86)`. Then simply [Download](https://github.com/sepehr0eslami/rimp/releases/latest) `rimp` for Windows (**rimp-win64.zip**), extract it and move the `rimp.exe` file to the `bin` folder. Finally, add that folder to the Path Environment Variable (You can google how to do it or get help from this [Link](https://www.c-sharpcorner.com/article/add-a-directory-to-path-environment-variable-in-windows-10/)).

> ⚠️ You need to replace the Drive Letter Windows is installed on in the path to the `System32` and `Program File(86)` folder, in case it is not 'C'

## MacOS

First, [Download](https://github.com/sepehr0eslami/rimp/releases/latest) `rimp` for MacOS (**rimp-macos.tar.gz**). Then open a terminal and extract it by running:

```sh
tar -xf rimp-macos.tar.gz 
```

Now you have a folder called `rimp-macos` containing the `rimp` executable. Install it using the command below:

```sh
sudo install rimp-macos/rimp /usr/local/bin
```

Close your terminal and open it again. Make sure `rimp` is correctly installed by running:

```sh
$ rimp --version

Rimp X.X.X.
```

## Linux

First, [Download](https://github.com/sepehr0eslami/rimp/releases/latest) `rimp` for Linux (**rimp-linux64.tar.gz**). Then open a terminal and extract it by running:

```sh
tar -xf rimp-linux64.tar.gz
```

Now you have a folder called `rimp-linux64` containing the `rimp` executable. Install it using the command below:

```sh
sudo install rimp-linux64/rimp /usr/local/bin
```

Close your terminal and open it again. Make sure `rimp` is correctly installed by running:

```sh
$ rimp --version

Rimp X.X.X.
```

## From Source

You can compile the source code yourself by following the instructions available in the [HACKING.md](https://github.com/sepehr0eslami/rimp/blob/master/HACKING.md) file.

## Completion Scripts

Currently, completion scripts are available for the following shells:

| Shell | Script                                                                                                            |
| ----- | ----------------------------------------------------------------------------------------------------------------- |
| ZSH   | [rimp_completion.zsh](https://github.com/sepehr0eslami/rimp/blob/master/scripts/completion/rimp_completion.zsh)   |
| Fish  | [rimp_completion.fish](https://github.com/sepehr0eslami/rimp/blob/master/scripts/completion/rimp_completion.fish) |
| Bash  | [rimp_completion.bash](https://github.com/sepehr0eslami/rimp/blob/master/scripts/completion/rimp_completion.bash) |

> Since Powershell doesn't support Programmable Completions (or at least I don't know how), Tab-Completion isn't available on Windows.

### ZSH

The completion system needs to be activated. If you’re using something like `oh-my-zsh` then this is already taken care of, otherwise you’ll need to add the following to your `.zshrc`

```sh
autoload -U compinit
compinit
```
Then, simply run the command below to download and install `rimp`'s completion script:

```sh
curl -o "_rimp" "https://raw.githubusercontent.com/sepehr0eslami/rimp/master/scripts/completion/rimp_completion.zsh" && sudo install -D -m '0644' _rimp $(echo $FPATH | awk -F ':' '{print $2"/_rimp"}') && rm _rimp
```

### Fish

Just run the command below to download and install `rimp`'s completion script:

```sh
curl -o "rimp.fish" "https://raw.githubusercontent.com/sepehr0eslami/rimp/master/scripts/completion/rimp_completion.fish" && sudo install -D -m '0644' rimp.fish /usr/share/fish/completions/rimp.fish && rm rimp.fish
```

### Bash

First, run the command below to download and install `rimp`'s completion script:

```sh
curl -o "rimp" "https://raw.githubusercontent.com/sepehr0eslami/rimp/master/scripts/completion/rimp_completion.bash" && sudo install -D -m '0644' rimp /usr/share/bash-completion/completions/rimp && rm rimp
```

Then add the following line to your `.bashrc` to load the script at shell startup:

```sh
[ -r /usr/share/bash-completion/completions/rimp ] && source /usr/share/bash-completion/completions/rimp
```

# Usage

`rimp` is used through multiple sub-commands that each does a special task; exactly like `git` and `apt`.

```sh
Usage: rimp [OPTIONS] SUBCOMMAND

Options:
  -h,--help                   Print this help message and exit
  -v,--version                Display program version information and exit

Subcommands:
  paste TAG [DEST]            Insert the file associated with TAG in [DEST]
  add TAG SOURCE              Attach the given TAG to SOURCE
  edit TAG NEW_SOURCE         Detach TAG from its source and attach it to NEW_SOURCE
  remove TAG                  Remove TAG from stored tags
  list                        List stored Tags and the Path they point to

Enclosing in Square Brackets("[]") means optional.
See rimp SUBCOMMAND --help to read about a specific subcommand.
```

## Tab-Completion

Just hit Tab while typing a sub-command, tag name, option, or path and the shell environment will automatically complete what you’re typing or suggest options to you.

# Roadmap

- A new sub-command to run shell commands on File/Folders associated with a Tag

- UNICODE Support for Tag names

- Easy to use Installer in addition to compiled binaries

# License

[GPL v3](https://opensource.org/licenses/GPL-3.0)
