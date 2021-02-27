/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:16:41 by mloh              #+#    #+#             */
/*   Updated: 2021/02/27 20:20:05 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	char1;
	unsigned char	char2;
	int				ix;

	ix = -1;
	while (s1[++ix] != '\0' || s2[ix] != '\0')
	{
		char1 = s1[ix];
		char2 = s2[ix];
		if ((char1 - char2) != 0)
			return (char1 - char2);
	}
	return (0);
}
