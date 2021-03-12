/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "buffer.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_buffer_init(t_dym_buffer *dyb, int sz)
{
	dyb->sz = sz;
	dyb->p = malloc(sz * sizeof(char));
	return (dyb->p);
}

char	*ft_buffer_adj(t_dym_buffer *dyb, int sz)
{
	char	*p;

	p = malloc(sz * sizeof(char));
	if (p)
	{
		if (dyb->p)
		{
			ft_strncpy(p, dyb->p, dyb->sz);
			free(dyb->p);
		}
		dyb->sz = sz;
		dyb->p = p;
	}
	return (p);
}

void	ft_buffer_free(t_dym_buffer *dyb)
{
	if (dyb->p)
	{
		free(dyb->p);
		dyb->p = NULL;
	}
	dyb->sz = 0;
}
