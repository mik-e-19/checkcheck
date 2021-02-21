/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:52:04 by gatan             #+#    #+#             */
/*   Updated: 2021/02/21 02:18:16 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	update_digit(char *num, int pos, int size)
{
	char	temp;

	temp = num[pos - 1] + 1;
	if (temp > '9' - size + pos && pos != 1)
	{
		update_digit(num, pos - 1, size);
		temp = num[pos - 2] + 1;
	}
	num[pos - 1] = temp;
}

void	print(char *num, int j)
{
	int		count;

	count = 0;
	while (count < j)
	{
		ft_putchar(num[count]);
		count++;
	}
}

void	ft_print_combn(int n)
{
	int		count;
	char	numlen[n];

	count = 0;
	while (count < n)
	{
		numlen[count] = count + 48;
		count++;
	}
	while (numlen[0] < '9' - n + 1)
	{
		print(numlen, n);
		ft_putchar(',');
		ft_putchar(' ');
		update_digit(numlen, n, n);
	}
	print(numlen, n);
}
