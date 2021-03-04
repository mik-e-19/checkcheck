/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:57:09 by mloh              #+#    #+#             */
/*   Updated: 2021/03/04 17:13:41 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int g_i;
unsigned int g_j;
int g_size_backup;
unsigned int g_temp;
unsigned int g_n_to_copy;

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	g_i = 0;
	g_j = 0;
	g_size_backup = size;
	while (g_size_backup-- > 0 && dest[g_i])
		++g_i;
	while (src[g_j])
		++g_j;
	g_n_to_copy = size - g_i;
	if (g_n_to_copy == 0)
		return (g_i + g_j);
	g_j = 0;
	g_temp = g_i;
	while (src[g_j])
	{
		if (g_n_to_copy != 1)
		{
			dest[g_i] = src[g_j];
			++g_i;
			--g_n_to_copy;
		}
		++g_j;
	}
	dest[g_i++] = 0;
	return (g_temp + g_j);
}
