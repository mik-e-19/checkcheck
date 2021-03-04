#include <stdio.h>
#include <string.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main()
{
	char a[10] = "bro";
	char b[] = "Hello";
	unsigned int i = 8;
	printf("%u\n", ft_strlcat(a, b, i));
	printf("%s\n", a);
	printf("%s\n", b);
}
