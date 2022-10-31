/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:58:54 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/31 11:46:41 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"
#include <stdlib.h>
#include <limits.h>

#include <stdio.h>

int main(int argc, char **argv)
{
	char **splitted;
	t_stack	*stack;

	if (argc < 2)
		ft_error();
	stack = ft_calloc(1, sizeof(t_stack));
	ft_are_args_ok(argc, argv);
	splitted = ft_process_args(argc, argv, stack);
	ft_printf_strs(splitted);
	stack->tab = ft_args_to_tab(splitted, stack);
	ft_printf_tab(stack->tab, stack->size);
	free(stack->tab);
	free(stack);
	return (0);
}
