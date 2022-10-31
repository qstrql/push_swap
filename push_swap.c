/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:58:54 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/31 19:34:35 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	**splitted;
	t_stack	*stack_a;
	t_stack *stack_b;

	if (argc < 2)
		ft_error();
	ft_are_args_ok(argc, argv);
	stack_a = ft_calloc(1, sizeof(t_stack));
	stack_b = ft_calloc(1, sizeof(t_stack));
	splitted = ft_process_args(argc, argv, stack_a);
	stack_a->tab = ft_args_to_tab(splitted, stack_a);
	stack_b->tab = ft_calloc(stack_a->size + 1, sizeof(int));
	if (stack_b->tab == NULL)
		return (NULL);
	ft_printf_tab(stack_a->tab, stack_a->size);
	ft_init_sort(stack_a, stack_b);
	ft_printf_tab(stack_a->tab, stack_a->size);
	free_stacks(stack_a, stack_b);
	return (0);
}
