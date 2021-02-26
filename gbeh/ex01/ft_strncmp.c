/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:27:37 by gbeh              #+#    #+#             */
/*   Updated: 2021/02/26 18:02:48 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	c1;
	unsigned char	c2;
	unsigned int	idx;

	idx = 0;
	while ((s1[idx] != '\0' || s2[idx] != '\0') && idx < n)
	{
		c1 = s1[idx];
		c2 = s2[idx++];
		if ((c1 - c2) != 0)
			return (c1 - c2);
	}
	return (0);
}
