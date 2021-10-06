# --------------------------- Available Subcommands -------------------------- #
SUBCMDS="paste add edit remove list"
# ------------------------------ General Options ----------------------------- #
I="--help -h --version -v" 
# ------------------------- Helper Function's Result ------------------------- #
FIND_WORD_RES=()

function __rimp_find_word {
    FIND_WORD_RES=()
    local str=( ${COMP_WORDS[@]} )
    if [[ $# -eq 0 ]]; then
        return
    else 
        local words=( $1 )
    fi

    for i in $(seq 0 $((${#str[@]}-1))); do
        for j in $(seq 0 $((${#words[@]}-1))); do
            if [[ ${str[$i]} = ${words[$j]} ]]; then
                FIND_WORD_RES+=( ${words[$j]} )
            fi
        done
    done
}

function _rimp_paste {
    local paste_args="--help -h"
    if [[ $cur == -* ]]; then
        COMPREPLY=( $(compgen -W "$paste_args" -- $cur) )
    else
        __rimp_find_word "$TAGS"
        if [[ $FIND_WORD_RES == "" ]]; then
            COMPREPLY=( $(compgen -W "$TAGS" -- $cur) )
        fi
    fi
}

function _rimp_add {
    local add_args="--help -h"
    if [[ $cur == -* ]]; then
        COMPREPLY=( $(compgen -W "$add_args" -- $cur) )
    fi
}

function _rimp_edit {
    local edit_args="--help -h"
    if [[ $cur == -* ]]; then
        COMPREPLY=( $(compgen -W "$edit_args" -- $cur) )
    else
        __rimp_find_word "$TAGS"
        if [[ $FIND_WORD_RES == "" ]]; then
            COMPREPLY=( $(compgen -W "$TAGS" -- $cur) )
        fi
    fi
}

function _rimp_remove {
    local remove_args="--help -h --force -f"
    if [[ $cur == -* ]]; then
        COMPREPLY=( $(compgen -W "$remove_args" -- $cur) )
    else
        __rimp_find_word "$TAGS"
        if [[ $FIND_WORD_RES == "" ]]; then
            COMPREPLY=( $(compgen -W "$TAGS" -- $cur) )
        fi
    fi
}

function _rimp_list {
    local list_args="--help -h --tags -t --paths -p --no-decorate -d --no-header -e --column-separator= -c --row-separator= -r --format= -f"
    if [[ $cur == -* ]]; then
        COMPREPLY=( $(compgen -W "$list_args" -- $cur) )
    fi

    __rimp_find_word "--format -f"
    if [[ $FIND_WORD_RES != "" ]]; then
        COMPREPLY=( $(compgen -W "%t %p %i %n %b %c %r" -- $cur) )
    fi
}

function _rimp() {
    local cur="$2"
    TAGS=$(rimp list -det 2>/dev/null)
    COMPREPLY=()

    __rimp_find_word "$SUBCMDS"
    if [[ $FIND_WORD_RES == "" ]]; then
        if [[ $cur == -* ]]; then
            COMPREPLY=( $(compgen -W "$I" -- $cur}) )
        else 
            COMPREPLY=( $(compgen -W "$SUBCMDS" -- $cur) )
        fi
    else
        case $FIND_WORD_RES in
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
    fi 
}

complete -o default -F _rimp rimp
