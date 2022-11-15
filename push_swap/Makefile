# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 12:29:21 by mjouot            #+#    #+#              #
#    Updated: 2022/11/15 14:15:07 by mjouot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap

SRCS = push_swap.c \
	   ft_utils.c \
	   ft_are_args_ok.c \
	   ft_args_to_tab.c \
	   ft_process_args.c \
	   ft_moves.c \
	   ft_init_sort.c \
	   ft_normalize.c \
	   ft_sort_utils.c

SRCS_BONUS = ../checker/checker.c \
			 ../checker/ft_double_moves.c

CC = clang
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -I ../libft/INCLUDES/ -I ../checker/checker.h

ifdef VAR_BONUS
	make -C ../checker
endif

$(NAME): $(OBJS)
		make extra -C ../libft
		$(CC) $(FLAGS) $^ -o $(NAME) ../libft/libft.a

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(OBJS)
	@make VAR_EXTRA=true

clean:
	make clean -C ../libft
	rm -f $(OBJS)

fclean: clean
	rm -f ../libft/libft.a
	rm -f $(NAME)

re: fclean all

.SILENT:
.PHONY: all clean fclean re
