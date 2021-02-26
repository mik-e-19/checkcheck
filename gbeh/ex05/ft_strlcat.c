/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:44:59 by gbeh              #+#    #+#             */
/*   Updated: 2021/02/26 18:42:59 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *s)
{
	unsigned int	size;

	size = 0;
	while (s[size++] != '\0')
	{
	}
	return (size - 1);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	const unsigned int	dest_len = ft_strlen(dest);
	unsigned int		idx_dest;
	int					idx_src;
	int					fill;

	idx_dest = 0;
	while (dest[idx_dest] != '\0')
	{
		idx_dest++;
	}
	idx_src = 0;
	fill = 0;
	while (idx_dest < size)
	{
		if (fill == 0 && src[idx_src] == '\0')
			fill = 1;
		dest[idx_dest++] = fill ? '\0' : src[idx_src++];
	}
	if (size > dest_len)
		dest[idx_dest - 1] = '\0';
	return (dest_len + ft_strlen(src));
}
