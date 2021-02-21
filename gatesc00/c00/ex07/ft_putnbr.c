/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 03:45:55 by gatan             #+#    #+#             */
/*   Updated: 2021/02/21 12:08:15 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		digit_count(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void	ft_putnbr(int nb)
{
	int digit_store[digit_count(nb)];
	int count;

	count = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		digit_store[count] = nb % 10;
		nb = nb / 10;
		count++;
	}
	ft_putchar(nb + 48);
	while (count != 0)
	{
		ft_putchar(digit_store[count - 1] + 48);
		count--;
	}
}
