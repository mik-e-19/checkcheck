/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:05:01 by mloh              #+#    #+#             */
/*   Updated: 2021/03/08 22:07:08 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	int		here;
	t_list	*root;
	t_list	*node;

	here = 0;
	node = ft_create_elem(data);
	root = *begin_list;
	if (root)
	{
		while (root->next && (cmp(root->next->data, data) <= 0))
			root = root->next;
		node->next = root->next;
		root->next = node;
	}
	else
		*begin_list = node;
}
