/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:59:35 by mloh              #+#    #+#             */
/*   Updated: 2021/03/08 22:00:21 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *root;
	t_list *node;
	t_list *next;

	root = *begin_list;
	node = *begin_list;
	while (root)
	{
		next = (*root).next;
		if ((cmp)(root->data, data_ref) == 0)
		{
			if (root == *begin_list)
			{
				*begin_list = next;
			}
			node->next = next;
			free(root);
		}
		node = root;
		root = next;
	}
}
