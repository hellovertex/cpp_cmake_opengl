cmake_minimum_required(VERSION 3.16)
# todo write function and call it
# This function prints each element in ARGV on a new line
function(print_list)
    set(result "")
    foreach (element in ${ARGV})
        list(APPEND result "${element}\n")
    endforeach ()
    message(${result})
endfunction()

# This function prints all defined cmake commands, one per line
function(print_commands)
    get_cmake_property(commands COMMANDS)
    print_list(${commands})
endfunction()

