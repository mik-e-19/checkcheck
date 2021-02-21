#!/bin/bash

FN_NAME="ft_print_combn";
touch main.c
echo "#include <unistd.h>" > main.c
echo "#include \"$FN_NAME.c\"" >> main.c
echo "int main(){" >> main.c
echo "$FN_NAME(2);" >> main.c
echo "return 0;}" >> main.c
gcc -Wall -Wextra -Werror main.c
./a.out
rm main.c ./a.out
