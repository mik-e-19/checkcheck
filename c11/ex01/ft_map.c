/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:19:40 by mloh              #+#    #+#             */
/*   Updated: 2021/03/05 23:20:25 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *results;
	int i;

	i = 0;
	results = (int *)malloc(length * sizeof(int));
	while (i < length)
	{
		results[i] = (*f)(tab[i]);
		++i;
	}
	return (results);
}
