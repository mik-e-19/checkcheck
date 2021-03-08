/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:01:08 by mloh              #+#    #+#             */
/*   Updated: 2021/03/08 22:01:33 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *root;

	root = *begin_list1;
	if (root == 0)
		*begin_list1 = begin_list2;
	else
	{
		while (root->next)
			root = root->next;
		root->next = begin_list2;
	}
}
