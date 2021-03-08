/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 00:00:00 by kolim             #+#    #+#             */
/*   Updated: 2021/02/27 00:00:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

short	get_sym_stat(char c, short n_stat)
{
	const char	a_list[] = {"\r\n\t -+"};
	const short	a_val[] = {0, 0, 0, 0, 1, 2};
	int			ctr;

	ctr = 0;
	while (ctr < (int)sizeof(a_list) && a_list[ctr] != c)
		++ctr;
	if (ctr >= (int)sizeof(a_list))
		return (-1);
	else
	{
		if (a_val[ctr] > 0 && n_stat > 0)
			return (-1);
		else
			return (a_val[ctr]);
	}
}

int		ft_atoi(const char *str)
{
	int		nb;
	short	n_stat;
	int		ctr;

	nb = 0;
	n_stat = 0;
	ctr = 0;
	while (n_stat >= 0 && str[ctr] != 0)
	{
		if (str[ctr] >= '0' && str[ctr] <= '9')
			nb = nb * 10 + (str[ctr] - '0');
		else
			n_stat = get_sym_stat(str[ctr], n_stat);
		++ctr;
	}
	if (n_stat == 1 && nb > 0)
	{
		nb = nb * -1;
	}
	return (nb);
}
