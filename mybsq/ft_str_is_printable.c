/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:00:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/03 00:00:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_printable(char ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	return (0);
}

int		ft_str_is_printable(char *str)
{
	if (str[0] == 0)
		return (1);
	if (ft_is_printable(str[0]))
		return (ft_str_is_printable(&str[1]));
	return (0);
}
