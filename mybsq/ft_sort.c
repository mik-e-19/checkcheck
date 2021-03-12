/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"

void	ft_swap_by(int *a, int *b, int mode);

int		ft_sort_cmp(t_map *p_m, int a, int b)
{
	int diff;

	diff = p_m->p_ob[a].x - p_m->p_ob[b].x;
	if (diff == 0)
		diff = p_m->p_ob[a].y - p_m->p_ob[b].y;
	return (diff);
}

void	ft_sort_bubble(t_map *p_m, int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < p_m->ob_sz - 1)
	{
		j = 0;
		while (j < p_m->ob_sz - i - 1)
		{
			if (ft_sort_cmp(p_m, tab[j], tab[j + 1]) > 0)
			{
				ft_swap_by(&tab[j], &tab[j + 1], 0);
			}
			++j;
		}
		++i;
	}
}
