#include <stdio.h>

int	ft_atoi(char *str)
{
	int num;
	int i;

	i = 0;
	num = 0;
	if (str)
	{
		if (str[0] == '-' && str[1] >= '0' && str[1] <= '9')
		{
			num = ft_atoi(++str);
			return (num * -1);
		}
		else if (str[0] != '-')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				num = (num * 10) + (str[i] - '0');
				++i;
			}
		}
	}
	return (num);
}
