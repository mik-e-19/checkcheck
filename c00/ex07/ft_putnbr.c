/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:30:42 by mloh              #+#    #+#             */
/*   Updated: 2021/02/25 15:37:46 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 10 && nb >= 0)
		ft_putchar(nb + '0');
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
		if (nb < 0)
			ft_putchar('-');
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
}
