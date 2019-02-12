# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/12 07:03:03 by jarcher      #+#   ##    ##    #+#        #
#    Updated: 2019/02/12 07:08:15 by jarcher     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME =	ft_ls

NAMELIB =	libft/libft.a

SRCS =	create_list.c	\
		get_arguments.c	\
		main.c			\
		print_file.c	\
		read_directory.c

OBJS =	$(SRCS:.c=.o)

RM =	rm -f

CFLAGS =	-Wall -Wextra -Werror -Ilibft

all:	$(NAMELIB) $(NAME)

$(NAMELIB):
	make -C libft

$(NAME):	$(OBJS)
	gcc $(OBJS) -o $(NAME) -lft -Llibft

clean:
		$(RM) $(OBJS)
		make clean -C libft

fclean: clean
		$(RM) $(NAME)
		$(RM) $(NAMELIB)

re: fclean all

.PHONY: all clean fclean re
