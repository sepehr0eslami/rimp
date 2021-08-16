#compdef rimp

I="--help -h --version -v"

(( $+functions[_rimp_paste] )) ||
function _rimp_paste() {
    local paste_args
    paste_args=(
        "1:Available Tags:(($TAGS))"
        "2:Destination:_files"
        "(- *)"{--help,-h}"[Print help message and exit]"
    )
    _arguments $paste_args[@]
}

(( $+functions[_rimp_add] )) ||
function _rimp_add() {
    local add_args
    add_args=(
        "1: :()"
        "2:Source File/Folder:_files"
        "(- *)"{--help,-h}"[Print help message and exit]"
    )
    _arguments $add_args[@]
}

(( $+functions[_rimp_edit] )) ||
function _rimp_edit() {
    local edit_args
    edit_args=(
        "1:Available Tags:(($TAGS))"
        "2:New Source File/Folder:_files"
        "(- *)"{--help,-h}"[Print help message and exit]"
    )
    _arguments $edit_args[@]
}

(( $+functions[_rimp_remove] )) ||
function _rimp_remove() {
    local remove_args
    remove_args=(
        "1:Available Tags:(($TAGS))"
        "(- *)"{--help,-h}'[Print help message and exit]'
        "($I)"{--force,-f}"[Cause the remove subcommand to delete the file associated with TAG in adition to TAG itself]"
    )
    _arguments $remove_args[@]
}

(( $+functions[_rimp_list] )) ||
function _rimp_list() {
    local list_args
    # TODO: Add message for these options
    # TODO: Fix the issue of the format placeholders completion
    list_args=(
        "(- *)"{--help,-h}"[Print help message and exit]"
        "($I --paths -p --format -f)"{--tags,-t}"[Only show the stored Tags]"
        "($I --tags -t --format -f)"{--paths,-p}"[Only show the stored Paths]"
        "($I --format -f)"{--no-decorate,-d}"[Do not decorate the output at all]"
        "($I)"{--no-header,-e}"[Do not print the Header]"
        "($I)"{--column-separator,-c}"[Use the given TEXT as the column separator instead of the default (two spaces)]"
        "($I)"{--row-separator,-r}"[Use the given TEXT as the row separator instead of the default (new-line)]"
        "($I --tags -t --paths -p --no-decorate -d)"{--format,-f}"[Pretty-print the stored data in the given format, where the format can contain any letter and some placeholders]:Placeholders:((%t\:'Current Tag' %p\:'Current Path' %i\:'Current Index' %n\:'New-line' %b\:'Tab' %c\:'Column Seperator (Default\: Two spaces)' %r\:'Row Seperator (Default\: New-line)'))"
    )
    _arguments $list_args[@]
}

function _rimp() {
    integer ret=1
    local line main_args
    TAGS="$(rimp list -ef '%t\:"%p" ' 2> /dev/null)"
    # TODO: Stop offering Subcommands when --help or --version are available
    main_args=(
        "(- *)"{--help,-h}"[Print help message and exit]"
        "(- *)"{--version,-v}"[Display program version information and exit]"
        "1:Main Subcommands:((paste\:'Insert the file associated with TAG in [DEST]' add\:'Attach the given TAG to SOURCE' edit\:'Detach TAG from its source and attach it to NEW_SOURCE' remove\:'Remove TAG from stored tags' list\:'List stored Tags and the Path they point to'))"
        "*::arg:->args"
    )
    _arguments -C $main_args[@] && ret=0

    case $line[1] in
        paste)
            _rimp_paste
        ;;
        add)
            _rimp_add
        ;;
        edit)
            _rimp_edit
        ;;
        remove)
            _rimp_remove
        ;;
        list)
            _rimp_list
        ;;
    esac

    return ret
}

_rimp
