/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:53:26 by mloh              #+#    #+#             */
/*   Updated: 2021/03/08 21:55:00 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"



void	ft_list_reverse(t_list **begin_list)
{
	t_list *root;
	t_list *node;
	t_list *next;

	root = *begin_list;
	node = 0;
	while (root)
	{
		next = (*root).next;
		(*root).next = node;
		node = root;
		root = next;
	}
	*begin_list = node;
}
