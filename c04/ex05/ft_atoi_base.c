/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 23:36:57 by mloh              #+#    #+#             */
/*   Updated: 2021/03/04 00:18:05 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_size_base = 0;

int		check_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
		{
			return (i);
		}
		++i;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int n;
	int x;
	int sign;

	i = -1;
	n = 0;
	x = 0;
	sign = 1;
	while (base[g_size_base] != '\0')
		++g_size_base;
	if (str[0] == '-')
	{
		sign = -1;
		++str;
	}
	while (str[++i])
	{
		x = check_in_base(str[i], base);
		if (x >= 0)
		{
			n = (n * g_size_base) + x;
		}
	}
	return (n * sign);
}
