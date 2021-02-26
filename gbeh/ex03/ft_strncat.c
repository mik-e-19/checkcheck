/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:44:59 by gbeh              #+#    #+#             */
/*   Updated: 2021/02/26 18:29:15 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx_dest;
	unsigned int	idx_src;
	int				fill;
	unsigned int	len;

	idx_src = 0;
	idx_dest = 0;
	while (dest[idx_dest++] != '\0')
	{
	}
	idx_dest--;
	len = idx_dest;
	fill = 0;
	while (idx_dest < nb + len)
	{
		if (fill == 0 && src[idx_src] == '\0')
			fill = 1;
		dest[idx_dest++] = (fill ? '\0' : src[idx_src++]);
	}
	return (dest);
}
