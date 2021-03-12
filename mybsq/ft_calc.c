/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap_by(int *a, int *b, int mode);

int		ft_calc_get(int *val, int sz, int mode)
{
	int	i;

	i = 0;
	while (i < (sz - 1))
	{
		ft_swap_by(&val[i], &val[i + 1], mode);
		++i;
	}
	return (val[sz - 1]);
}
