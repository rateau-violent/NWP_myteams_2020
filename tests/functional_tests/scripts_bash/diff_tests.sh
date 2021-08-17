##
## EPITECH PROJECT, 2020
## diff_tests
## File description:
## project_name:
##

#!/bin/sh

################################################################################
#                                DIFF TESTS                                    #
################################################################################

echo -e "\\$DEFAULT [i]\\$LIGHT_MAGENTA RUNNING DIFF:\n\\$RESET_ALL"

echo -e "\\$LIGHT_YELLOW Diff tests\\$LIGHT_GREEN [OK]\n\\$RESET_ALL"

###########
#test help#
###########

# diff tests/functional_tests/help tests/functional_tests/expected/help_expected

# if (($? == 0))
# then
#     ((pass++))
#     ((total++))
# else
#     echo -e "\\$BLINK \\$LIGHT_RED /!\ Test help failed /!\ \n\\$RESET_ALL"
#     ((fail++))
#     ((total++))
# fi

# rm tests/functional_tests/output/help

#############
#normal test#
#############

##exemple
#diff tests/functional_tests/test_n°1 tests/functional_tests/expected/test_n°1_expected

# if (($? == 0))
# then
#     ((pass++))
#     ((total++))
# else
#     echo -e "\\$BLINK \\$LIGHT_RED /!\ Test n°$total failed /!\ \n\\$RESET_ALL"
#     ((fail++))
#     ((total++))
# fi

# rm tests/functional_tests/output/test_n°1



#################
#if no help test#
#################

# if (($? == 0))
# then
#     ((pass++))
#     ((total++))
# else
#     ((fail++))
#     ((total++))
#     echo -e "\\$BLINK \\$LIGHT_RED /!\ Test n°$total failed /!\ \n\\$RESET_ALL"
# fi

# rm tests/functional_tests/output/test_n°1