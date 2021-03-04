#!/bin/sh

[[ -z $1 ]] && { echo >&2 "\$TEST_PROJECT has not been provided! Use cXX where XX is the project number."; exit 1; }
[[ -z $2 ]] && { echo >&2 "\$QN_NUMBER has not been provided! Use exXX where XX is the question number."; exit 1; }

norminette -R CheckForbiddenSourceHeader $2/*.c
curl "https://gitlab.com/Beh_____/scripts/-/raw/master/c_general/tests/$1/$2main.c" --output $2/main.c
gcc -Wall -Wextra -Werror $2/*.c -o $2/a.out
echo "-START OUTPUT-"
./$2/a.out | cat -e
rm $2/a.out
echo "-END OUTPUT-"
echo "DISCLAIMER: Tests may not cover all possible cases, evaluators still need to discuss logical structure of program"
[ ! -z $3 ] && { echo "main template generated"; exit 0; }
rm "$2/main.c"
