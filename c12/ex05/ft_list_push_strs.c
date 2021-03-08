/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:42:39 by mloh              #+#    #+#             */
/*   Updated: 2021/03/08 21:45:34 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*elem;
	t_list	*elem2;
	int		i;
	if (size <= 0)
		return (0);
	elem = ft_create_elem(strs[0]);
	i = 0;
	while (++i < size)
	{
		elem2 = ft_create_elem(strs[i]);
		elem2->next = elem;
		elem = elem2;
	}
	return (elem);
}

