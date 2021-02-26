/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
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

void	ft_print_number(int nb, int n_lead_zero)
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
		ft_print_number(nb_p1, --n_lead_zero);
	}
	ch = '0' + nb_p2;
	write(1, &ch, 1);
}

void	ft_prn_comb2_re(int i_num_digit, int i_digit_pos, int i_ctr, int i_nb)
{
	int	nb;

	while (i_ctr <= 99)
	{
		nb = (i_nb * 100) + i_ctr;
		if (i_digit_pos == 1)
		{
			if (i_ctr >= i_num_digit)
			{
				write(1, ", ", 2);
			}
			ft_print_number(nb / 100, i_num_digit);
			write(1, " ", 1);
			ft_print_number(nb % 100, i_num_digit);
		}
		else
		{
			ft_prn_comb2_re(i_num_digit, i_digit_pos - 1, i_ctr + 1, nb);
		}
		i_ctr++;
	}
}

void	ft_print_comb2(void)
{
	ft_prn_comb2_re(2, 2, 0, 0);
}
