/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "map.h"

void	ft_map_2a_re(t_map *p_m, int v[3][2], int l)
{
	if (l == 0 || l == 1)
	{
		v[l][0] = 0;
		while (v[l][0] < v[l][1])
		{
			ft_map_2a_re(p_m, v, l + 1);
			++(v[l][0]);
		}
	}
	else
	{
		if (v[0][0] == p_m->p_ob[v[l][0]].y && v[1][0] == p_m->p_ob[v[l][0]].x)
		{
			p_m->p_m[(v[0][0] * v[1][1]) + v[1][0]] = 1;
			if (v[l][0] < p_m->ob_sz)
				++(v[l][0]);
		}
		else
			p_m->p_m[(v[0][0] * v[1][1]) + v[1][0]] = 0;
	}
}

int		ft_map_2a(t_map *p_m)
{
	int	ctr[3][2];

	if ((p_m->w * p_m->h) > 0)
	{
		p_m->p_m = malloc((p_m->w * p_m->h) * sizeof(char));
		if (!p_m->p_m)
			return (-1);
		ctr[0][1] = p_m->h;
		ctr[1][1] = p_m->w;
		ctr[2][1] = p_m->ob_sz;
		ctr[2][0] = 0;
		ft_map_2a_re(p_m, ctr, 0);
	}
	return (0);
}
