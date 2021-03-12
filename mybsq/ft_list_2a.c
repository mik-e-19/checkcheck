/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_2a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "list.h"
#include "map.h"

t_l_n	*ft_list_get(t_l_r *l_r, t_l_n *l_n);
void	ft_sort_bubble(t_map *p_m, int *tab);

int		ft_list_2a_ixy(t_map *p_m)
{
	int	i;

	p_m->iox = malloc(p_m->ob_sz * sizeof(int));
	if (!p_m->iox)
		return (-1);
	p_m->ioy = malloc(p_m->ob_sz * sizeof(int));
	if (!p_m->ioy)
		return (-1);
	i = 0;
	while (i < p_m->ob_sz)
	{
		p_m->iox[i] = i;
		p_m->ioy[i] = i;
		++i;
	}
	return (0);
}

void	ft_map_2a_re(t_map *p_m, int c[3][2], int l)
{
	if (l == 0 || l == 1)
	{
		c[l][0] = 0;
		while (c[l][0] < c[l][1])
		{
			ft_map_2a_re(p_m, c, l + 1);
			++(c[l][0]);
		}
	}
	else
	{
		if (c[0][0] == p_m->p_ob[c[l][0]].y && c[1][0] == p_m->p_ob[c[l][0]].x)
		{
			p_m->p_m[(c[0][0] * c[1][1]) + c[1][0]] = 1;
			if (c[l][0] < p_m->ob_sz)
				++(c[l][0]);
		}
		else
			p_m->p_m[(c[0][0] * c[1][1]) + c[1][0]] = 0;
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

int		ft_list_2a(t_map *p_m, t_l_r *p_l_r)
{
	t_l_n	*p_l_n;
	int		errno;
	int		i;

	if (p_m->ob_sz > 0)
	{
		p_m->p_ob = malloc(p_m->ob_sz * sizeof(t_coord));
		if (!p_m->p_ob)
			return (-1);
		p_l_n = NULL;
		i = 0;
		while ((p_l_n = ft_list_get(p_l_r, p_l_n)) != NULL)
		{
			p_m->p_ob[i].x = p_l_n->x;
			p_m->p_ob[i].y = p_l_n->y;
			++i;
		}
		if ((errno = ft_list_2a_ixy(p_m)) != 0)
			return (errno);
		ft_sort_bubble(p_m, p_m->iox);
		if ((errno = ft_map_2a(p_m)) != 0)
			return (errno);
	}
	return (0);
}
