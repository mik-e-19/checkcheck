
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					char	**ft_split(char *str, char *charset);
				
int main()
{
char** res;
for (res = ft_split("NOPENOPENOPE", "NOPE"); *res != 0; res++)
	printf("'%s',", *res);
printf("\n");
for (res = ft_split("", "NOPE"); *res != 0; res++)
	printf("'%s',", *res);
printf("\n");



return 0;
}
