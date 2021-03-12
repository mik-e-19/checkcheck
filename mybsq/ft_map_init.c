/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
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

void	ft_map_coord_init(t_coord cd[2], t_coord cs[2])
{
	cd[0].x = cs[0].x;
	cd[0].y = cs[0].y;
	cd[1].x = cs[1].x;
	cd[1].y = cs[1].y;
	ft_swap_by(&cd[0].x, &cd[1].x, 1);
	ft_swap_by(&cd[0].y, &cd[1].y, 1);
}

void	ft_map_init(t_map *p_m)
{
	p_m->p_ob = NULL;
	p_m->iox = NULL;
	p_m->ioy = NULL;
	p_m->p_m = NULL;
	p_m->p_am = NULL;
	p_m->ob_sz = 0;
}
