/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_prc_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"

int		ft_map_read_1(t_dym_buffer *dyb, int fd);
int		ft_map_read(t_dym_buffer *dyb, int fd);
int		ft_map_validate(t_map *p_m);
int		ft_map_prc(t_map *p_m);
void	ft_putnbr(int nb, int fd);

/*
**  errno = 0 - to suppress error atm, as spec say print map error
**	errno = -ve ; use for memory error
**	errno = 10 - 19 ; generate by ft_map_prc_in
**	errno = 20 - 29 ; generate by ft_map_validate
**			20 - first line length < 4
**			21 - duplicate symbols
**			22 - non-printable symbols
**			23 - invalid no-of-lines
**	errno = 30 - 39 ; generate by ft_map_read
**			30 - different map line width
**			31 - symbols not as per config in line-1
**			32 - no-of-lines not as per config in line-1
*/

void	ft_prn_err_prc(int errno)
{
	errno = 0;
	write(2, "map error\n", 9);
}

int		ft_map_prc_in(t_map *p_m, int fd)
{
	int		errno;

	if (!(errno = ft_map_read_1(&p_m->dyb, fd)))
		errno = ft_map_validate(p_m);
	if (errno)
		ft_prn_err_prc(errno);
	else
	{
		p_m->w = 0;
		if ((errno = ft_map_read(&p_m->dyb, fd)))
		{
			ft_prn_err_prc(errno);
		}
		else
		{
			errno = ft_map_prc(p_m);
		}
	}
	return (errno);
}
