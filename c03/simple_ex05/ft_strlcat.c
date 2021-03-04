/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeo <zyeo@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:42:19 by zyeo              #+#    #+#             */
/*   Updated: 2021/03/04 00:01:47 by zyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int m;
	unsigned int n;

	m = 0;
	while (dest[m])
		m++;
	n = 0;
	while (src[n] && m + n + 1 < size)
	{
		dest[m + n] = src[n];
		n++;
	}
	if (m + n < size)
		dest[m + n] = 0;
	while (src[n])
		n++;
	if (size < m)
		return (n + size);
	else
		return (m + n);
}
