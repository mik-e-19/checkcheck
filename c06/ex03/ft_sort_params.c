/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:28:52 by mloh              #+#    #+#             */
/*   Updated: 2021/03/04 18:59:24 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strcmp(char const *s1, char const *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

void	ft_swap(int *a, int *b)
{
	int c;

	if (a && b)
	{
		c = *a;
		*a = *b;
		*b = c;
	}
}

void	ft_print_arg(char const *c)
{
	int j;

	j = 0;
	while (c[j])
	{
		ft_putchar(c[j]);
		++j;
	}
	ft_putchar('\n');
}

int		main(int argc, char const *argv[])
{
	int i;
	int j;
	int k;
	int arg[argc];

	i = 1;
	while (i < argc)
	{
		arg[i] = i;
		++i;
	}
	j = 1;
	while (j < argc)
	{
		k = j;
		while (k < argc)
		{
			if (ft_strcmp(argv[arg[j]], argv[arg[k]]) > 0)
				ft_swap(&arg[j], &arg[k]);
			++k;
		}
		ft_print_arg(argv[arg[j++]]);
	}
	return (0);
}
