
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					char	*ft_concat_params(int size, char **strs, char *sep);
				
int main()
{
char* arr[3] = {"NO", "YES", NULL};
printf("%s", ft_concat_params(2, arr));



return 0;
}
