/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_atoi(const char *str);
int		ft_str_is_printable(char *str);

int		ft_chk_dup(char *ch, int sz)
{
	int	i;
	int	j;

	i = 0;
	while (i < sz)
	{
		j = i + 1;
		while (j < sz)
		{
			if (ch[i] == ch[j])
				break ;
			++j;
		}
		if (j < sz)
			break ;
		++i;
	}
	if (i < sz)
		return (1);
	return (0);
}

int		ft_map_validate(t_map *p_m)
{
	int	errno;

	errno = 0;
	if (p_m->dyb.len < 4)
		errno = 20;
	else
	{
		ft_strncpy(p_m->sym, &p_m->dyb.p[p_m->dyb.len - 3], 4);
		p_m->dyb.p[p_m->dyb.len - 3] = 0;
		if (ft_chk_dup(p_m->sym, 3))
			errno = 21;
		else if (!ft_str_is_printable(p_m->sym))
			errno = 22;
		else
		{
			p_m->h = ft_atoi(p_m->dyb.p);
			if (p_m->h <= 0)
				errno = 23;
		}
	}
	return (errno);
}
