/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 23:36:57 by mloh              #+#    #+#             */
/*   Updated: 2021/03/04 16:50:19 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_size_base = 0;

int	rep_check(char *base)
{
	int i;
	int j;
	int valid;

	valid = 1;
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				valid = 0;
			j++;
		}
		i++;
	}
	return (valid);
}

int	base_check(char *base)
{
	int i;
	int valid;

	valid = 1;
	valid = rep_check(base);
	if (base == 0 || g_size_base <= 1)
		valid = 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			valid = 0;
		i++;
	}
	return (valid);
}

int		check_in_base(char c, char *base)
{
	int i;

	i = 0;
	if (base_check(base) == 1)
	{
		while (base[i])
		{
			if (base[i] == c)
				return (i);
			i++;
		}
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int n;
	int x;
	int sign;

	i = 0;
	n = 0;
	sign = 1;
	while (base[g_size_base])
		++g_size_base;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((x = check_in_base(str[i], base)) != -1)
	{
		n = (n * g_size_base) + x;
		i++;
	}
	return (n * sign);
}
