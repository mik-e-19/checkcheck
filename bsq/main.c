/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/06 21:42:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "map.h"

char	*ft_buffer_init(t_dym_buffer *p_dyb, int sz);
void	*ft_buffer_free(t_dym_buffer *p_dyb);
void	ft_map_init(t_map *p_m);
void	ft_map_free(t_map *p_m);
int		ft_map_prc_in(t_map *p_m, int fd);
int		ft_strlen(char *str);

void	ft_prn_err_main(int errno)
{
	if (errno == -1)
		write(2, "Error in alloc memory for dymamic buffer!\n", 42);
	if (errno == 1)
		write(2, "Error in open input file!\n", 26);
	if (errno == 2)
		write(2, "Error in closing input file!\n", 30);
}

void	header(char *p_name)
{
	write(1, "########## ", 11);
	write(1, p_name, ft_strlen(p_name));
	write(1, " ##########\n", 12);
}

int		prc(t_map *p_m, int argc, char *argv[])
{
	int		var[3];

	var[2] = 0;
	if (argc <= 1)
		var[0] = 0;
	else
		var[0] = open(argv[1], O_RDONLY);
	var[1] = 2;
	while (var[0] >= 0)
	{
		var[2] = ft_map_prc_in(p_m, var[0]);
		if (var[0] > 2)
			if (close(var[0]))
				var[2] = 2;
		if (var[2] < 0 || var[1] >= argc)
			break ;
		var[0] = open(argv[(var[1])++], O_RDONLY);
		if (var[0] > 2)
			write(1, "\n", 1);
	}
	return (var[2]);
}

int		main(int argc, char *argv[])
{
	t_map	map;
	int		errno;

	errno = 0;
	ft_map_init(&map);
	if (!ft_buffer_init(&map.dyb, 80))
	{
		errno = -1;
	}
	else
	{
		errno = prc(&map, argc, argv);
	}
	if (errno < 0)
		ft_prn_err_main(errno);
	ft_buffer_free(&map.dyb);
	ft_map_free(&map);
	return (errno);
}
