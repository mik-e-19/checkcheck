/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:23:12 by mloh              #+#    #+#             */
/*   Updated: 2021/02/27 20:24:16 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int ix_dest;
	int ix_src;

	ix_dest = -1;
	while (dest[++ix_dest] != '\0')
	{
	}
	ix_src = -1;
	while (src[++ix_src] != '\0')
	{
		dest[ix_dest++] = src[ix_src];
	}
	dest[ix_dest] = '\0';
	return (dest);
}
