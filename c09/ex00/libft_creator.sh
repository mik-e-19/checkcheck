gcc -Wall -Wextra -Werror ft_putchar.c -o a.o ;
gcc -Wall -Wextra -Werror ft_swap.c -o b.o;
gcc -Wall -Wextra -Werror ft_putstr.c -o c.o;
gcc -Wall -Wextra -Werror ft_strlen.c -o d.o;
gcc -Wall -Wextra -Werror ft_strcmp.c -o e.o;
ar ruv libft.a a.o b.o c.o d.o e.o;
ranlib libft.a;
