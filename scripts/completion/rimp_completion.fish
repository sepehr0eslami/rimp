set -l I "not __fish_seen_subcommand_from --help -h --version -v"
set -l TAGS "(rimp list -det 2>/dev/null)"
set -l TAGS_DESC "(rimp list -dec \t 2>/dev/null)"
set -l SUBCMDS "paste add edit remove list"
set -l SUBCMDS_DESC "paste\t'Insert the file associated with TAG in [DEST]'" \
                    "add\t'Attach the given TAG to SOURCE'" \
                    "edit\t'Detach TAG from its source and attach it to NEW_SOURCE'" \
                    "remove\t'Remove TAG from stored tags'" \
                    "list\t'List stored Tags and the Path they point to'" 

# General
complete -fc rimp -n "not __fish_seen_subcommand_from $SUBCMDS" -a "$SUBCMDS_DESC"
complete -fc rimp -n "not __fish_seen_subcommand_from $SUBCMDS; and $I" -s v -l version -d "Display program version information and exit"
complete -fc rimp -n "$I" -s h -l help -d "Print this help message and exit"

# Paste
complete -fc rimp -n "__fish_seen_subcommand_from paste; and not __fish_seen_subcommand_from $TAGS" -a "$TAGS_DESC"
complete -fc rimp -n "__fish_seen_subcommand_from paste; and __fish_seen_subcommand_from $TAGS" -a "(__fish_complete_directories)"

# Add
complete -Fc rimp -n "__fish_seen_subcommand_from add"

# Edit
complete -fc rimp -n "__fish_seen_subcommand_from edit; and not __fish_seen_subcommand_from $TAGS" -a "$TAGS_DESC"
complete -Fc rimp -n "__fish_seen_subcommand_from edit; and __fish_seen_subcommand_from $TAGS"

# Remove
complete -fc rimp -n "__fish_seen_subcommand_from remove; and not __fish_seen_subcommand_from $TAGS" -a "$TAGS_DESC"
complete -fc rimp -n "__fish_seen_subcommand_from remove; and not __fish_seen_subcommand_from --force -f; and $I" -s f -l force -d "Cause the remove subcommand to delete the file associated with TAG in adition to TAG itself"

# List
complete -fc rimp -n "__fish_seen_subcommand_from list; and not __fish_seen_subcommand_from --tags -t --paths -p --format -f; and $I" -l tags -s t -d "Only show the stored Tags"
complete -fc rimp -n "__fish_seen_subcommand_from list; and not __fish_seen_subcommand_from --paths -p --tags -t --format -f; and $I" -l paths -s p -d "Only show the stored Paths"
complete -fc rimp -n "__fish_seen_subcommand_from list; and not __fish_seen_subcommand_from --no-decorate -d --format -f;and $I" -l no-decorate -s d -d "Do not decorate the output at all"
complete -fc rimp -n "__fish_seen_subcommand_from list; and not __fish_seen_subcommand_from --no-header -e; and $I" -l no-header -s e -d "Do not print the Header"
complete -xc rimp -n "__fish_seen_subcommand_from list; and not __fish_seen_subcommand_from --column-separator -c; and $I" -l column-separator -s c -d "Use the given TEXT as the column separator instead of the default (two spaces)"
complete -xc rimp -n "__fish_seen_subcommand_from list; and not __fish_seen_subcommand_from --row-separator -r; and $I" -l row-separator -s r -d "Use the given TEXT as the row separator instead of the default (new-line)"
complete -xc rimp -n "__fish_seen_subcommand_from list; and not __fish_seen_subcommand_from --format -f --tags -t --paths -p --no-decorate -d; and $I" -l format -s f -d "Pretty-print the stored data in the given format, where the format can contain any letter and some placeholders"
complete -fc rimp -n "__fish_seen_subcommand_from list; and __fish_seen_subcommand_from --format -f" -ka "%t\t'Current Tag' %p\t'Current Path' %i\t'Current Index' %n\t'New-line' %b\t'Tab' %c\t'Column Seperator (Default: Two spaces)' %r\t'Row Seperator (Default: New-line)'"


