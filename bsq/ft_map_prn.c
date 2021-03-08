/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_prn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"

void	ft_map_prn_algo(t_map *p_m);
void	ft_putnbr(int nb, int fd);

void	ft_map_prn_coord(t_coord *co)
{
	write(1, "(", 1);
	ft_putnbr(co->x, 1);
	write(1, ", ", 2);
	ft_putnbr(co->y, 1);
	write(1, ")", 1);
}

void	ft_map_prn_ob(t_map *p_m)
{
	int i;

	i = 0;
	while (i < p_m->ob_sz)
	{
		if (i > 0)
			write(1, ", ", 2);
		ft_map_prn_coord(&p_m->p_ob[i]);
		++i;
	}
	write(1, "\n", 1);
}

/*
**	mode = 1 (use iox), else use ioy
*/

void	ft_map_prn_obixy(t_map *p_m, int mode)
{
	int	i;
	int	*p;

	if (mode == 1)
		p = p_m->iox;
	else
		p = p_m->ioy;
	i = 0;
	while (i < p_m->ob_sz)
	{
		if (i > 0)
			write(1, ", ", 2);
		ft_map_prn_coord(&p_m->p_ob[p[i]]);
		++i;
	}
	write(1, "\n", 1);
}

void	ft_map_prn_full(t_map *p_m)
{
	int	i;
	int j;

	i = 0;
	while (i < p_m->h)
	{
		j = 0;
		while (j < p_m->w)
		{
			write(1, &p_m->sym[(int)p_m->p_m[(i * p_m->w) + j]], 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}

void	ft_map_prn(t_map *p_m)
{
	ft_map_prn_full(p_m);
}
