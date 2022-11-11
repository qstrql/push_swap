# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 12:29:21 by mjouot            #+#    #+#              #
#    Updated: 2022/11/11 23:41:17 by mjouot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
allo
NAME = push_swap

SRCS = push_swap.c \
	   ft_utils.c \
	   ft_are_args_ok.c \
	   ft_args_to_tab.c \
	   ft_process_args.c \
	   ft_moves.c \
	   ft_double_moves.c \
	   ft_init_sort.c \
	   ft_normalize.c \
	   ft_lowest_move_cost.c \
	   ft_sort_utils.c \
	   ft_exec_moves.c \
	   \
	   ft_printf_stack.c \
	   ft_printf_target.c 

CC = gcc
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -ggdb3 -I ./libft/INCLUDES/

$(NAME): $(OBJS)
		make extra -C libft
		$(CC) $(FLAGS) $^ -o $(NAME) libft/libft.a

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all

.SILENT:
.PHONY: all clean fclean re
