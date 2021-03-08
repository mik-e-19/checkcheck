/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"

void	ft_map_coord_init(t_coord cd[2], t_coord cs[2]);

void	ft_map_fill_re(t_map *p_m, int c[3][2], t_coord co[2], int l)
{
	if (l == 0 || l == 1)
	{
		c[l][0] = 0;
		while (c[l][0] < c[l][1])
		{
			ft_map_fill_re(p_m, c, co, l + 1);
			++(c[l][0]);
		}
	}
	else
	{
		if (c[0][0] >= co[0].y && c[0][0] <= co[1].y)
			if (c[1][0] >= co[0].x && c[1][0] <= co[1].x)
			{
				p_m->p_m[(c[0][0] * c[1][1]) + c[1][0]] = 2;
			}
	}
}

int		ft_map_fill(t_map *p_m, t_coord i_co[2])
{
	t_coord	co[2];
	int		ctr[3][2];

	ft_map_coord_init(co, i_co);
	ctr[0][1] = p_m->h;
	ctr[1][1] = p_m->w;
	ft_map_fill_re(p_m, ctr, co, 0);
	return (0);
}
