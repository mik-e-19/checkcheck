/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:41:57 by mloh              #+#    #+#             */
/*   Updated: 2021/02/27 19:43:01 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;
	int j;
	int size_temp;

	i = 0;
	j = 0;
	size_temp = size;
	while (size > 1 && (dest[i] = src[i]) != 0)
	{
		dest[i] = src[i];
		--size;
		++i;
	}
	if (size_temp != 0)
	{
		dest[i] = '\0';
		while (src[j])
			++j;
	}
	return (j);
}
