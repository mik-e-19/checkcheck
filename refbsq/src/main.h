/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:46:47 by gbeh              #+#    #+#             */
/*   Updated: 2021/03/09 02:53:48 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>

void	solve_board(int **board);
int		is_valid_board(int **board);
void	print_board(int **board, char *chrset);
void	free_board(int **board);
int		**read_map(int fd, char **chrset);
int		**read_map_file(char *filename, char **charset);

#endif
