/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:32:43 by mloh              #+#    #+#             */
/*   Updated: 2021/03/03 23:04:49 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i++])
	{
		j++;
	}
	return (j);
}
