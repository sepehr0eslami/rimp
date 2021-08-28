# Install Completion Scripts for available Shells

include("${PROJECT_SOURCE_DIR}/cmake/folders.cmake")


if(NOT CMAKE_SYSTEM_NAME STREQUAL "Windows")
    file(STRINGS "/etc/shells" SHELLS
        REGEX "^[^#]"
    )

    string(FIND "${SHELLS}" "zsh" ZSH_FOUND)
    string(FIND "${SHELLS}" "fish" FISH_FOUND)
    string(FIND "${SHELLS}" "bash" BASH_FOUND)

    if(NOT ${ZSH_FOUND} EQUAL -1)
        set(ZSH_COMP_PATH "/usr/share/zsh/site-functions")
        find_program(ZSH_PATH "zsh")
        message(STATUS "Found ZSH: ${ZSH_PATH}")
        install(FILES "${scripts_dir}/completion/rimp_completion.zsh"
            DESTINATION "${ZSH_COMP_PATH}"
            RENAME _rimp
        )
    endif()
    if(NOT ${FISH_FOUND} EQUAL -1)
        set(FISH_COMP_PATH "/usr/share/fish/completions")
        find_program(FISH_PATH "fish")
        message(STATUS "Found Fish: ${FISH_PATH}")
        install(FILES "${scripts_dir}/completion/rimp_completion.fish"
            DESTINATION "${FISH_COMP_PATH}"
            RENAME rimp.fish
        )
    endif()
    if(NOT ${BASH_FOUND} EQUAL -1)
        set(BASH_COMP_PATH "/usr/share/bash-completion/completions")
        find_program(BASH_PATH "bash")
        message(STATUS "Found Bash: ${BASH_PATH}")
        install(FILES "${scripts_dir}/completion/rimp_completion.bash"
            DESTINATION "${BASH_COMP_PATH}"
            RENAME rimp
        )
    endif()
endif()
