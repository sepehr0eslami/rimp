# Changelog

## 1.1.1 - 2021-09-24

### Fixed

- **`list` Sub-command's malfunction:** Unexpected and random behavior of `list` sub-command to assume flags are present when they are not ([f1fe191](https://github.com/sepehr0eslami/rimp/commit/f1fe191))
- **Missing dependencies in `HACKING.md`:** It was forgotten to mention "SQLite" as a dependency ([2b3475f](https://github.com/sepehr0eslami/rimp/commit/2b3475f))

## 1.1.0 - 2021-09-17

### Added

- **`list` sub-command:** For pretty-printing the added Tags and the Path they point to ([15795ce](https://github.com/sepehr0eslami/rimp/commit/15795ce))
    - `--tags, -t` flag: Only show the stored Tags ([e5871d0](https://github.com/sepehr0eslami/rimp/commit/e5871d0))
    - `--paths, -p` flag: Only show the stored Paths ([67aa7cf](https://github.com/sepehr0eslami/rimp/commit/67aa7cf))
    - `--no-decorate, -d` flag: Avoid decorating the output ([b4bc93e](https://github.com/sepehr0eslami/rimp/commit/b4bc93e))
    - `--no-header, -e` flag: Avoid printing the Header row ([7148e5e](https://github.com/sepehr0eslami/rimp/commit/7148e5e))
    - `--format, -f` option: For pretty-printing the output in a custom format ([5b0b37b](https://github.com/sepehr0eslami/rimp/commit/5b0b37b))
    - `--column-separator, -c` and `--row-separator, -r` options: For using a different column/row separator for the output ([adf063d](https://github.com/sepehr0eslami/rimp/commit/adf063d))

- **Completion Scripts for the following Shells:**
    - `ZSH`: Tab Completion for Sub-commands, Tags, Paths, etc with description when possible ([2449ba3](https://github.com/sepehr0eslami/rimp/commit/2449ba3))
    - `Fish`: Tab Completion for Sub-commands, Tags, Paths, etc with description when possible ([3e70f6b](https://github.com/sepehr0eslami/rimp/commit/3e70f6b))
    - `Bash`: Tab Completion for Sub-commands, Tags, Paths, etc ([e385a22](https://github.com/sepehr0eslami/rimp/commit/e385a22))

## 1.0.0 - 2021-07-12

### added

- **the following sub-commands:**
    - `paste`: for pasting a file/folder ([1593ffe](https://github.com/sepehr0eslami/rimp/commit/1593ffe))
    - `add`: for adding a tag ([c9886a4](https://github.com/sepehr0eslami/rimp/commit/c9886a4))
    - `edit`: for editing an existing tag ([582d495](https://github.com/sepehr0eslami/rimp/commit/582d495))
    - `remove`: for removing an existing tag ([123c1c0](https://github.com/sepehr0eslami/rimp/commit/123c1c0))
        - `--force, -f` flag: to remove the file/folder in addition to the tag itself ([02d4d58](https://github.com/sepehr0eslami/rimp/commit/02d4d58))

- **help options:** `rimp --help` or `rimp subcommand --help` for help messages ([3fbd438](https://github.com/sepehr0eslami/rimp/commit/3fbd438))

- **relative path support:** support for relative paths as the input options ([867eb62](https://github.com/sepehr0eslami/rimp/commit/867eb62))
