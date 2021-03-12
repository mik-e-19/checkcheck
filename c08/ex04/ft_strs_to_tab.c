/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:36:56 by mloh              #+#    #+#             */
/*   Updated: 2021/03/10 18:57:40 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strcpy(char *str, int size)
{
	char	*c;
	int		i;

	c = NULL;
	c = malloc(sizeof(char) * (size + 1));
	i = 0;
	while (str[i])
	{
		c[i] = str[i];
		i += 1;
	}
	c[i] = 0;
	return (c);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strcpy(av[i], tab[i].size);
		i += 1;
	}
	tab[i].size = 0;
	tab[i].str = 0;
	tab[i].copy = 0;
	return (tab);
}
