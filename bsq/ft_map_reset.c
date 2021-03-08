/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"

void	ft_map_reset(t_map *p_m)
{
	int	i;
	int j;

	i = 0;
	while (i < p_m->h)
	{
		j = 0;
		while (j < p_m->w)
		{
			if (p_m->p_m[(i * p_m->w) + j] == 2)
				p_m->p_m[(i * p_m->w) + j] = 0;
			++j;
		}
		++i;
	}
}
