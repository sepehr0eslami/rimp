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

`rimp` is a Cross-Platform command-line tool which makes working with files/folders you need regularly much easier, by allowing you to tag and access them in the future only by their tags.


## :thinking: Why?
I wanted a tool that allows you to:

- Tag files/folders using the command line 

- Paste those files/folders elsewhere with one simple command

- Remove or update an existing tag

# Installation

## Windows

To run this application, you just need SQLite3. [Download](https://www.sqlite.org/download.html) the latest version of SQLite3 for Windows, then extract it and move `sqlite3.dll` to `C:\System32`.

Now, create a folder called `Rimp` in `C:\Program Files(x86)`. Then simply [Download](https://github.com/sepehr0eslami/rimp/releases/latest) `rimp` for Windows (**rimp-win64.zip**), extract it and move the `rimp.exe` file to the previously created folder. Finally, add that folder to the Path Environment Variable (You can google how to do it or get help from this [Link](https://www.c-sharpcorner.com/article/add-a-directory-to-path-environment-variable-in-windows-10/)).

> :warning: You need to replace the Drive Letter Windows is installed on in the path to the `System32` and `Program File(86)` folder, in case it is not 'C'

## MacOS

First, [Download](https://github.com/sepehr0eslami/rimp/releases/latest) `rimp` for MacOS (**rimp-macos.tar.gz**). Then open a terminal and extract it by running:

```sh
tar -xf rimp-macos.tar.gz --one-top-level
```

Now you have a folder called `rimp-macos` containing the `rimp` executable. Move it to somewhere in `$PATH` using the command below:

```sh
sudo cp rimp-macos/rimp $(echo $PATH | awk -F ":" '{print $1}')
```

Close your terminal and open it again. Make sure `rimp` is correctly installed by running:

```sh
$ rimp --version

Rimp X.X.X.
```

## Linux

First, [Download](https://github.com/sepehr0eslami/rimp/releases/latest) `rimp` for Linux (**rimp-linux64.tar.gz**). Then open a terminal and extract it by running:

```sh
tar -xf rimp-linux64.tar.gz --one-top-level
```

Now you have a folder called `rimp-linux64` containing the `rimp` executable. Move it to somewhere in `$PATH` using the command below:

```sh
cp rimp-linux64/rimp $(echo $PATH | awk -F ":" '{print $1}')
```

Close your terminal and open it again. Make sure `rimp` is correctly installed by running:

```sh
$ rimp --version

Rimp X.X.X.
```

# Usage
`rimp` is used through multiple sub-commands that each does a special task; exactly like `git` and `apt`.

```sh
Usage: rimp [OPTIONS] SUBCOMMAND

Options:
  -h,--help                   Print this help message and exit
  -v,--version                Display program version information and exit

Subcommands:
  paste TAG [DEST]            Insert the file associated with TAG in [DEST].
  add TAG SOURCE              Attach the given TAG to SOURCE.
  edit TAG NEW_SOURCE         Detach TAG from its source and attach it to NEW_SOURCE
  remove TAG                  Remove TAG from stored tags

Enclosing in Square Brackets("[]") means optional.
See rimp SUBCOMMAND --help to read about a specific subcommand.
```

# Roadmap

- Tab Completion for sub-commands and tags

- A new sub-command to run shell commands on File/Folders associated with a Tag

- UNICODE Support for Tag names

- Easy to use Installer in addition to compiled binaries
