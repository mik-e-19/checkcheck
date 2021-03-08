/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_chk.c                                       :+:      :+:    :+:   */
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

int		ft_map_chk_bd(t_map *p_m, int mode, int *ioxy, t_coord co[3])
{
	if (mode == 1)
		return (p_m->p_ob[ioxy[0]].x - co[1].x);
	else
		return (p_m->p_ob[ioxy[0]].y - co[1].y);
}

int		ft_map_chk_xy(t_map *p_m, t_coord co[3], int *ix, int mode)
{
	int	i;

	i = 0;
	while (i < p_m->ob_sz && ft_map_chk_bd(p_m, mode, &ix[i], co) <= 0)
	{
		if (p_m->p_ob[ix[i]].y >= co[0].y && p_m->p_ob[ix[i]].y <= co[1].y)
			if (p_m->p_ob[ix[i]].x >= co[0].x && p_m->p_ob[ix[i]].x <= co[1].x)
			{
				co[2].x = p_m->p_ob[ix[i]].x;
				co[2].y = p_m->p_ob[ix[i]].y;
				break ;
			}
		++i;
	}
	if (i < p_m->ob_sz && co[2].x != -1)
		return (1);
	return (0);
}

/*
**	mode = 1 (use iox), else use ioy
*/

int		ft_map_chk(t_map *p_m, t_coord i_co[3], int mode)
{
	t_coord	co[3];
	int		*p;

	ft_map_coord_init(co, i_co);
	co[2].x = -1;
	co[2].y = -1;
	if (mode == 1)
		p = p_m->iox;
	else
		p = p_m->ioy;
	if (ft_map_chk_xy(p_m, co, p, mode))
	{
		i_co[2].x = co[2].x;
		i_co[2].y = co[2].y;
		return (1);
	}
	return (0);
}
