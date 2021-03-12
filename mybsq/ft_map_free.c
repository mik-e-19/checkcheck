/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_free.c                                      :+:      :+:    :+:   */
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

void	ft_map_free_1(void **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}

void	ft_map_free(t_map *p_m)
{
	ft_map_free_1((void **)&p_m->p_ob);
	ft_map_free_1((void **)&p_m->iox);
	ft_map_free_1((void **)&p_m->ioy);
	ft_map_free_1((void **)&p_m->p_m);
	ft_map_free_1((void **)&p_m->p_am);
	p_m->ob_sz = 0;
}
