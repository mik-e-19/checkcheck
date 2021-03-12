CC = gcc
CFLAGS = -Wall -Werror -Wextra

ODIR = obj

NAME = bsq
SOURCES = ft_atoi.c ft_buffer.c ft_calc.c ft_list.c ft_list_2a.c ft_map_algo.c ft_map_chk.c ft_map_init.c ft_map_fill.c ft_map_free.c ft_map_prc.c ft_map_prc_in.c ft_map_prn.c ft_map_read.c ft_map_reset.c ft_map_validate.c ft_putnbr.c ft_sort.c ft_strlen.c ft_str_is_printable.c ft_strncpy.c ft_swap_by.c main.c
DEPS = buffer.h list.h map.h

OBJ = $(SOURCES:.c=.o)
OBJ_ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

norm: $(SOURCES) $(DEPS)
	norminette -R CheckForbiddenSourceHeader $^

.PHONY: clean

clean:
	rm -f *.o

test:
	./bsq sample1.txt
