##
## EPITECH PROJECT, 2020
## functional_test
## File description:
## project_name:
##

#!/bin/sh

##install figlet before
#figlet -c ##project_name
#figlet -c FUNCTIONAL TESTS

################################################################################
#                               COMPILATION                                    #
################################################################################

make re > /dev/null 2>&1

##explanation
#command > /dev/null: redirects the output of command(stdout) to /dev/null
#2>&1: redirects stderr to stdout, so errors (if any) also goes to /dev/null

################################################################################
#                         BASH FORMATING AND COLORS                            #
################################################################################

source tests/functional_tests/scripts_bash/bash_formating_and_colors.sh

################################################################################
#                          VARIABLE INITIALISATION                             #
################################################################################

pass=0
fail=0
total=0

################################################################################
#                              CREATE TESTS                                    #
################################################################################

source tests/functional_tests/scripts_bash/create_tests.sh

################################################################################
#                             RUNNING TESTS                                    #
################################################################################

source tests/functional_tests/scripts_bash/diff_tests.sh

################################################################################
#                      NUMBER OF TESTS PASSED OR FAILED                        #
################################################################################

echo -e "\\$DEFAULT [i]\\$LIGHT_MAGENTA TOTAL:\\$RESET_ALL"
echo -e "\\$LIGHT_BLUE Tested: $total\\$LIGHT_GREEN Passing: $pass\\$LIGHT_RED Failling: $fail\n\\$RESET_ALL"

################################################################################
#                               CLEAN REPO                                     #
################################################################################

cl > /dev/null 2>&1