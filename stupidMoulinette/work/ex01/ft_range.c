/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 21:02:53 by mloh              #+#    #+#             */
/*   Updated: 2021/03/06 16:16:55 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *arr;
	int i;

	if (min >= max)
		return (0);
	arr = malloc((max - min) * sizeof(int));
	if (arr == NULL)
		return (arr);
	i = 0;
	while (min < max)
	{
		arr[i++] = min;
		++min;
	}
	return (arr);
}
