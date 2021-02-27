/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:21:00 by mloh              #+#    #+#             */
/*   Updated: 2021/02/27 20:22:17 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	char1;
	unsigned char	char2;
	unsigned int	ix;

	ix = 0;
	while ((s1[ix] != '\0' || s2[ix] != '\0') && ix < n)
	{
		char1 = s1[ix];
		char2 = s2[ix++];
		if ((char1 - char2) != 0)
			return (char1 - char2);
	}
	return (0);
}
