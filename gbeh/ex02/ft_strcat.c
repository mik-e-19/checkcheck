/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:08:37 by gbeh              #+#    #+#             */
/*   Updated: 2021/02/25 15:49:20 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Assumes that dest will contain enough buffer space
** in accordance with man strcat specifications
*/

char	*ft_strcat(char *dest, char *src)
{
	int idx_dest;
	int idx_src;

	idx_dest = -1;
	while (dest[++idx_dest] != '\0')
	{
	}
	idx_src = -1;
	while (src[++idx_src] != '\0')
	{
		dest[idx_dest++] = src[idx_src];
	}
	dest[idx_dest] = '\0';
	return (dest);
}
