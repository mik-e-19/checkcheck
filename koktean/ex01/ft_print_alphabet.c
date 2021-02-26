/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 00:00:00 by kolim             #+#    #+#             */
/*   Updated: 2021/02/25 20:00:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char ch;

	ch = 'a';
	while (ch <= 'z')
	{
		write(1, &ch, 1);
		ch++;
	}
}
