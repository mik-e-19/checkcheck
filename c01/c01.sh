curl https://gitlab.com/Beh_____/scripts/-/raw/master/test_c.sh --output test_c.sh
cd ex00
sh ../test_c.sh "void ft_ft(int *nbr);" \
	"int a=5; ft_ft(&a); printf(\"%d\", a);"
cd ../ex01
sh ../test_c.sh "void ft_ultimate_ft(int *********a);" \
	"int a = 4; int *p1 = &a; int **p2 = &p1; int ***p3 = &p2; int ****p4 = &p3; int *****p5 = &p4; int ******p6 = &p5; int *******p7 = &p6; int ********p8 = &p7; int*********p9 = &p8; ft_ultimate_ft(p9); printf(\"%d\", *********p9);"
cd ../ex02
sh ../test_c.sh "void ft_swap(int *a, int *b);" \
	"int a=2147483646; int b=2144; ft_swap(&a, &b); printf(\"%d %d\",a, b);"
cd ../ex03
sh ../test_c.sh "void ft_div_mod(int a, int b, int *div, int *mod);" \
	"int a=120, b=23; int div = 42, mod = 42; ft_div_mod(a, b, &div, &mod); printf(\"a=%d b=%d div=%d mod=%d\", a, b, div, mod);"
cd ../ex04
sh ../test_c.sh "void ft_ultimate_div_mod(int *a, int *b);" \
	"int a=120, b=23; printf(\"a=%d b=%d\", a, b); ft_ultimate_div_mod(&a, &b); printf(\"a=%d b=%d\", a, b);"
cd ../ex05
sh ../test_c.sh "void ft_putstr(char *str);" \
	"char *str = \"abcdefg\"; ft_putstr(str);"
cd ../ex06
sh ../test_c.sh "int ft_strlen(char *str);" \
	"char *str = \"123456789\"; printf(\"Length of %s is %d.\", str, ft_strlen(str));"
cd ../ex07
sh ../test_c.sh "void ft_rev_int_tab(int *tab, int size);" \
	"int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; ft_rev_int_tab(a, 10); int i=-1; while(++i < 10){printf(\"%d, \", a[i]);}"
cd ../ex08
sh ../test_c.sh "void ft_sort_int_tab(int *tab, int size);" \
	"int a[10] = {8, 6, 4, 2, 0, 1, 3, 9, 7, 5}; ft_sort_int_tab(a, 10); int i=-1; while(++i < 10){printf(\"%d, \", a[i]);}"
echo "Finished running tests for c01..."
echo "DISCLAIMER: Tests may not cover all possible cases, evaluators still need to discuss logical structure of program"
rm ../test_c.sh
