/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "buffer.h"
#include "list.h"
#include "map.h"

char	*ft_buffer_adj(t_dym_buffer *dyb, int sz);
void	ft_list_init(t_l_r *l_r);
void	ft_list_free(t_l_r *l_r);
int		ft_list_add(t_l_r *l_r, t_l_n *l_n);
int		ft_list_2a(t_map *p_m, t_l_r *l_r);

int		ft_map_read_1(t_dym_buffer *dyb, int fd)
{
	int	errno;

	errno = 0;
	dyb->len = 0;
	while (errno >= 0 && read(fd, &dyb->p[dyb->len], 1))
	{
		if (dyb->p[dyb->len] == '\n')
		{
			dyb->p[dyb->len] = 0;
			break ;
		}
		if (dyb->len >= dyb->sz)
			if (!ft_buffer_adj(dyb, dyb->sz * 2))
				errno = -1;
		if (errno == 0)
			++(dyb->len);
	}
	return (errno);
}

/*
**	Use v[0] = width, v[1] = heigh, v[2] = errno, v[3] = ch for reading
*/

void	ft_map_read_init(t_map *p_m, int v[4])
{
	p_m->w = 0;
	p_m->ob_sz = 0;
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
}

void	ft_map_read_prc_line(t_map *p_m, int v[4])
{
	if (p_m->w == 0)
		p_m->w = v[0] + 1;
	else if (p_m->w != (v[0] + 1))
		v[2] = 30;
	v[0] = 0;
	++(v[1]);
}

void	ft_map_read_prc_ch(t_map *p_m, int v[4], t_l_r *p_l_r, t_l_n *p_l_n)
{
	if (v[3] != p_m->sym[0] && v[3] != p_m->sym[1])
		v[2] = 31;
	if (v[3] == p_m->sym[1])
	{
		p_l_n->x = v[0];
		p_l_n->y = v[1];
		ft_list_add(p_l_r, p_l_n);
		++(p_m->ob_sz);
	}
	++(v[0]);
}

int		ft_map_read(t_map *p_m, int fd)
{
	t_l_r	l_r;
	t_l_n	l_n;
	int		v[4];

	ft_list_init(&l_r);
	ft_map_read_init(p_m, v);
	while (read(fd, &v[3], 1))
	{
		v[3] = (char)v[3];
		if (v[3] == '\n')
			ft_map_read_prc_line(p_m, v);
		else
			ft_map_read_prc_ch(p_m, v, &l_r, &l_n);
		if (v[2] != 0)
			break ;
	}
	if (v[2] == 0)
	{
		if (p_m->h != v[1])
			v[2] = 32;
		else
			ft_list_2a(p_m, &l_r);
	}
	ft_list_free(&l_r);
	return (v[2]);
}
