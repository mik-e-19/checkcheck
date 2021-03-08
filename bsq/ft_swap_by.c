/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_by.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**	mode = 1 (swap if not asc), mode = 2 (swap if not desc)
*/

void	ft_swap_by(int *a, int *b, int mode)
{
	int nb;

	if (mode < 0 && *a > *b)
		return ;
	if (mode > 0 && *a < *b)
		return ;
	nb = *a;
	*a = *b;
	*b = nb;
}
