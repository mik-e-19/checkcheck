#include <stdlib.h>
 
int     delta(int d)
{
	if (d < 0)
		return (-d);
	return (d);
}
 
int     *ft_rrange(int start, int end)
{
	int size;
	int *range;
	int val;
	int i;

	size = delta(end - start) + 1;
	range = malloc(sizeof(int) * size);

	if (start > end)
		val = 1;
	else
		val = -1;

	i = 0;
	while (i < size)
	{
		range[i] = end;
		end += val;
		++i;
	}
	return (range);
}
