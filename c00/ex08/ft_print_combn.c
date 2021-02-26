/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:38:31 by mloh              #+#    #+#             */
/*   Updated: 2021/02/26 09:51:14 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	up_dig(char *num, int pos, int size)
{
	char temp;

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
	int count;

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
	char	numln[n];

	count = 0;
	while (count < n)
	{
		numln[count] = count + 48;
		count++;
	}
	while (numln[0] < '9' - n + 1)
	{
		print(numln, n);
		ft_putchar(',');
		ft_putchar(' ');
		up_dig(numln, n, n);
	}
	print(numlen, n);
}
