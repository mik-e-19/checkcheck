#include <unistd.h>
#include <stdio.h>

void	count_alpha(char *str, int i, int letter, int count)
{
	int		temp;
	char	c;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (letter++ > 0)
				printf(", ");
			c = str[i];
			temp = i;
			count = 0;
			while (str[temp])
			{
				if (str[temp] == c)
				{
					str[temp] = ' ';
					count++;
				}
				temp++;
			}
			printf("%d%c", count, c);
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] += ' ';
			i++;
		}
		count_alpha(av[1], 0, 0, 0);
	}
	printf("\n");
	return (0);
}
