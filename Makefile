# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 12:29:21 by mjouot            #+#    #+#              #
#    Updated: 2022/11/15 18:20:52 by mjouot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap

SRCS = mandatory/push_swap.c \
	   mandatory/ft_utils.c \
	   mandatory/ft_are_args_ok.c \
	   mandatory/ft_args_to_tab.c \
	   mandatory/ft_process_args.c \
	   mandatory/ft_moves.c \
	   mandatory/ft_init_sort.c \
	   mandatory/ft_normalize.c \
	   mandatory/ft_sort_utils.c

SRCS_BONUS = bonus/checker.c \
	 		 bonus/ft_double_moves.c \
			 bonus/ft_moves_checker.c \
			 mandatory/ft_utils.c \
			 mandatory/ft_are_args_ok.c \
			 mandatory/ft_args_to_tab.c \
			 mandatory/ft_process_args.c \
			 mandatory/ft_normalize.c \
			 mandatory/ft_sort_utils.c

CC = clang
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror -I ./libft/INCLUDES/ -ggdb3

$(NAME): $(OBJS)
		make extra -C libft
		$(CC) $(FLAGS) $^ -o $(NAME) libft/libft.a

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(OBJS_BONUS)
		make extra -C libft
		$(CC) $(FLAGS) $(OBJS_BONUS) -o checker libft/libft.a

clean:
	make clean -C libft
	rm -f $(OBJS_BONUS)
	rm -f $(OBJS)

fclean: clean
	rm -f checker
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all

.SILENT:
.PHONY: all clean fclean re
