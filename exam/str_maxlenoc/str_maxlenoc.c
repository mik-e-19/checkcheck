#include <unistd.h>

static char	*ft_strstrn(char *str1, char *str2, int n)
{
	int		i;

	while (*str1)
	{
		i = 0;
		while (str2[i] && i < n && str1[i] == str2[i])
			i++;
		if (i == n)
			return (str1);
		str1++;
	}
	return (NULL);
}

static int		ft_len(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int		inside(char **strs, int count, char *s, int len)
{
	int		i;

	i = -1;
	while (++i < count)
		if (ft_strstrn(strs[i], s, len) == NULL)
			return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		len;

	len = (argc > 1) ? ft_len(argv[1]) : 0;
	while (len > 0)
	{
		i = 0;
		while (argv[1][i + len - 1])
		{
			if (inside(argv + 1, argc - 1, argv[1] + i, len))
			{
				write(1, argv[1] + i, len);
				break ;
			}
			i++;
		}
		if (argv[1][i + len - 1])
			break ;
		len--;
	}
	write(1, "\n", 1);
	return (0);
}
