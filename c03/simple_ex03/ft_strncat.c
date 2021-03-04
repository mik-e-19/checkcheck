/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeo <zyeo@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:40:20 by zyeo              #+#    #+#             */
/*   Updated: 2021/03/03 17:32:16 by zyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int m;
	unsigned int n;

	m = 0;
	while (dest[m])
		m++;
	n = 0;
	while (src[n] && n < nb)
	{
		dest[m + n] = src[n];
		n++;
	}
	dest[m + n] = 0;
	return (dest);
}
