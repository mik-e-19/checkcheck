/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 00:00:00 by kolim             #+#    #+#             */
/*   Updated: 2021/02/25 20:00:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ft_print_number
** - use long to cater for int (4-bytes) value range (-2147483648, 2147483647)
*/

void	ft_print_number(int nb, int fd, int n_lead_zero)
{
	long	l_nb;
	int		nb_p1;
	int		nb_p2;
	char	ch;

	l_nb = nb;
	if (l_nb < 0)
	{
		write(1, "-", 1);
		l_nb = l_nb * -1;
	}
	nb_p1 = l_nb / 10;
	nb_p2 = l_nb % 10;
	if (nb_p1 > 0 || n_lead_zero > 1)
	{
		ft_print_number(nb_p1, fd, --n_lead_zero);
	}
	ch = '0' + nb_p2;
	write(fd, &ch, 1);
}

void	ft_putnbr(int nb, int fd)
{
	ft_print_number(nb, fd, 0);
}
