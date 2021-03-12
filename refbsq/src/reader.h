/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:23:14 by gbeh              #+#    #+#             */
/*   Updated: 2021/03/09 13:51:51 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

int		slen(char *s);
char	*resize_arr(char *arr, int old_size, unsigned int buf_size);
int		**initialise_board(int rows);
int		*initialise_row(int size);
void	push_row(int **board, int *row);
int		ft_atoi(char **line);

#endif
