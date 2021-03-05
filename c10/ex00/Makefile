# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 23:15:45 by mloh              #+#    #+#              #
#    Updated: 2021/03/05 23:15:52 by mloh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
C_FILES = display_file.c

.PHONY: all clean fclean

all:
	@gcc -Wall -Wextra -Werror -o $(NAME) $(C_FILES)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
