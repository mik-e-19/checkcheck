/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:02:07 by mloh              #+#    #+#             */
/*   Updated: 2021/03/08 22:02:43 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*i;
	t_list	*j;
	void	*temp_data;

	i = *begin_list;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if ((*cmp)(i->data, j->data) > 0)
			{
				temp_data = i->data;
				i->data = j->data;
				j->data = temp_data;
			}
			j = j->next;
		}
		i = i->next;
	}
}
