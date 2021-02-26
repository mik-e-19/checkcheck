/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:33:41 by mloh              #+#    #+#             */
/*   Updated: 2021/02/24 23:45:31 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_alphabet(void)
{
	int	letter;

	letter = 'z';
	while (letter >= 'a')
	{
		write(1, &c, 1);
		letter--;
	}
}
