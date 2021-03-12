/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:28:00 by mloh              #+#    #+#             */
/*   Updated: 2021/03/10 18:49:23 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H

# define FT_BOOLEAN_H
# define TRUE 1
# define FALSE 0
# define EVEN(x) ((x) % 2 == 0)
# define SUCCESS 0
# define ODD_MSG "I have an odd number of arguments.\n"
# define EVEN_MSG "I have an even number of arguments.\n"

# include <unistd.h>

typedef int	t_bool;

#endif
