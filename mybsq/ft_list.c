/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
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

void	ft_list_init(t_l_r *l_r)
{
	l_r->sz = 0;
	l_r->l = NULL;
	l_r->n = NULL;
}

void	ft_list_free(t_l_r *l_r)
{
	t_l_n	*p;
	t_l_n	*n;

	p = l_r->n;
	while (p != NULL)
	{
		n = p->n;
		free(p);
		p = n;
	}
	ft_list_init(l_r);
}

int		ft_list_add(t_l_r *l_r, t_l_n *l_n)
{
	t_l_n	*n;

	n = malloc(sizeof(t_l_n));
	if (n == NULL)
		return (-1);
	n->x = l_n->x;
	n->y = l_n->y;
	n->n = NULL;
	if (l_r->sz == 0)
		l_r->n = n;
	else
		l_r->l->n = n;
	l_r->l = n;
	++(l_r->sz);
	return (0);
}

t_l_n	*ft_list_get(t_l_r *l_r, t_l_n *l_n)
{
	t_l_n	*n;

	if (l_n == NULL)
	{
		return (l_r->n);
	}
	n = l_n;
	while (n != NULL && n != l_n->n)
	{
		n = n->n;
	}
	return (n);
}
