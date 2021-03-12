/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_prc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"

int		ft_map_chk(t_map *p_m, t_coord i_co[3], int mode);
int		ft_map_fill(t_map *p_m, t_coord i_co[2]);
void	ft_map_prn_ob(t_map *p_m);
void	ft_map_prn_obixy(t_map *p_m, int mode);
void	ft_map_prn(t_map *p_m);
void	ft_map_reset(t_map *p_m);
void	ft_map_prn_coord(t_coord *co);
void	ft_map_algo(t_map *p_m);

void	ft_map_prc_debug(t_coord *p_c, int step)
{
	if (step == 1)
	{
		write(1, "From Coord: ", 12);
		ft_map_prn_coord(&p_c[0]);
		write(1, " to Coord: ", 11);
		ft_map_prn_coord(&p_c[1]);
	}
	if (step == 2)
	{
		write(1, "Found obstacle: ", 16);
		ft_map_prn_coord(&p_c[2]);
	}
	if (step == 3)
	{
		write(1, "; Fill Map: ", 12);
		ft_map_prn_coord(&p_c[0]);
		ft_map_prn_coord(&p_c[1]);
		write(1, "\n", 1);
	}
}

int		ft_map_prc(t_map *p_m)
{
	t_coord	co[3];

	ft_map_algo(p_m);
	co[0].x = p_m->ac.x - p_m->amx + 1;
	co[0].y = p_m->ac.y - p_m->amx + 1;
	co[1].x = p_m->ac.x;
	co[1].y = p_m->ac.y;
	if (!ft_map_chk(p_m, co, 1))
		ft_map_fill(p_m, co);
	ft_map_prn(p_m);
	return (0);
}
