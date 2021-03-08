/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:42:00 by kolim             #+#    #+#             */
/*   Updated: 2021/03/08 02:24:00 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "buffer.h"

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_fill_info
{
	int		row;
	int		col;
	int		largest;
	int		end_pt;
}				t_fill_info;

typedef struct	s_map
{
	t_dym_buffer	dyb;
	char			sym[4];
	int				h;
	int				w;
	int				ob_sz;
	t_coord			*p_ob;
	int				*iox;
	int				*ioy;
	char			*p_m;
	t_fill_info		fi;
	t_coord			ac;
	int				amx;
	int				*p_am;
}				t_map;

#endif
