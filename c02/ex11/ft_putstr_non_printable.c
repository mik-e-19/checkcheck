/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:43:26 by mloh              #+#    #+#             */
/*   Updated: 2021/02/27 19:56:55 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	print(char b)
{
	if (b < 16)
		ft_putchar(b < 10 ? b + '0' : b - 10 + 'a');
	else
	{
		print(b / 16);
		print(b % 16);
	}
}

void	ft_putstr_non_printable(char *str)
{
	char c;

	for (int i = 0; (c = str[i]); i++)
	{
		if (c > 31 && c < 127);
			ft_putchar(c);
		else
		{
			write(1, "\\0", 2);
			print(c);
		}
	}
}
