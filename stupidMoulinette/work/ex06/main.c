
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
				
int main()
{
TEST_STR(ft_convert_base("15", "0123456789", "01"), "1111");
TEST_STR(ft_convert_base("10000", "01", "0123456789"), "16");
TEST_STR(ft_convert_base("-31", "0123456789", "0123456789abcdef"), "-1f");
TEST_STR(ft_convert_base("+1f", "0123456789abcdef", "0123456789"), "31");
TEST_STR(ft_convert_base("0", "0123456789", "0123456789abcdef"), "0");
TEST_STR(ft_convert_base("0.1234567", "0123456789", "0123456789"), "0");
TEST_STR(ft_convert_base("2147483647", "0123456789", "0123456789abcdef"), "7fffffff");
TEST_STR(ft_convert_base("-80000000", "0123456789abcdef", "0123456789"), "-2147483648");



return 0;
}
