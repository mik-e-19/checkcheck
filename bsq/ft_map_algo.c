/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_algo.c                                      :+:      :+:    :+:   */
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

int		ft_calc_get(int *val, int sz, int mode);
void	ft_putnbr(int nb, int fd);

void	ft_map_prn_algo(t_map *p_m)
{
	int	i;
	int j;

	if (p_m->p_am)
	{
		i = 0;
		while (i < p_m->h)
		{
			j = 0;
			while (j < p_m->w)
			{
				if (j > 0)
					write(1, ":", 1);
				ft_putnbr(p_m->p_am[(i * p_m->w) + j], 1);
				++j;
			}
			write(1, "\n", 1);
			++i;
		}
	}
}

int		ft_map_algo_get_calc_val(t_map *p_m, int v[3][2])
{
	int	val[3];

	val[0] = p_m->p_am[((v[0][0] - 1) * v[1][1]) + v[1][0] - 1];
	val[1] = p_m->p_am[((v[0][0] - 1) * v[1][1]) + v[1][0]];
	val[2] = p_m->p_am[(v[0][0] * v[1][1]) + v[1][0] - 1];
	return (ft_calc_get(val, 3, -1));
}

void	ft_map_algo_calc(t_map *p_m, int v[3][2])
{
	int	val;

	if (v[0][0] == 0 || v[1][0] == 0)
		p_m->p_am[(v[0][0] * v[1][1]) + v[1][0]] = 1;
	else
	{
		val = ft_map_algo_get_calc_val(p_m, v) + 1;
		p_m->p_am[(v[0][0] * v[1][1]) + v[1][0]] = val;
		if (val > p_m->amx)
		{
			p_m->amx = val;
			p_m->ac.x = v[1][0];
			p_m->ac.y = v[0][0];
		}
	}
}

void	ft_map_algo_re(t_map *p_m, int v[3][2], int l)
{
	if (l == 0 || l == 1)
	{
		v[l][0] = 0;
		while (v[l][0] < v[l][1])
		{
			ft_map_algo_re(p_m, v, l + 1);
			++(v[l][0]);
		}
	}
	else
	{
		if (v[0][0] == p_m->p_ob[v[l][0]].y && v[1][0] == p_m->p_ob[v[l][0]].x)
		{
			p_m->p_am[(v[0][0] * v[1][1]) + v[1][0]] = 0;
			if (v[l][0] < p_m->ob_sz)
				++(v[l][0]);
		}
		else
			ft_map_algo_calc(p_m, v);
	}
}

int		ft_map_algo(t_map *p_m)
{
	int	ctr[3][2];

	if ((p_m->w * p_m->h) > 0)
	{
		p_m->p_am = malloc((p_m->w * p_m->h) * sizeof(int));
		if (!p_m->p_am)
			return (-1);
		ctr[0][1] = p_m->h;
		ctr[1][1] = p_m->w;
		ctr[2][1] = p_m->ob_sz;
		ctr[2][0] = 0;
		p_m->amx = 0;
		ft_map_algo_re(p_m, ctr, 0);
	}
	return (0);
}
