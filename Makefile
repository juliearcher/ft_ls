# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/09/04 08:59:18 by jarcher      #+#   ##    ##    #+#        #
#    Updated: 2019/09/04 09:05:17 by jarcher     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
#
NAME=	ft_ls
LIB=	libft/libft.a

INCLUDES=	include/ft_ls.h

SRCS=	src/directory.c		\
		src/display.c		\
		src/errors.c		\
		src/init.c			\
		src/main.c			\
		src/options.c		\
		src/print_options.c	\
		src/sort.c

OBJS= $(SRCS:.c=.o)

RM= rm -f

CFLAGS= -Iinclude -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	make -C libft
	gcc $(OBJS) -o $(NAME) -Llibft -lft

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIB) $(NAME)

re: fclean all

.PHONY: all clean fclean re
