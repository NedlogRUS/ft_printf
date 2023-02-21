NAME = libftprintf.a
SRC = ft_printf.c ft_printdics.c ft_printpoint.c ft_printxu.c

OBJ = $(SRC:%.c=%.o)
AR = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re 