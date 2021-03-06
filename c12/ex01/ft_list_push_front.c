/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:57:53 by mloh              #+#    #+#             */
/*   Updated: 2021/03/06 11:58:19 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *node;

	if (*begin_list == NULL)
		*begin_list = ft_create_elem(data);
	else
	{
		node = ft_create_elem(data);
		(*node).next = (*begin_list);
		*begin_list = node;
	}
}
