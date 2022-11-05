/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:09:38 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/05 15:10:32 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"
static int	count = 0;

void	swap(t_stack *stack, char c)
{
	int	tmp;

	tmp = 0;
	count++;
	//ft_printf("count : %d -- ", count);
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
	tmp = stack->tab[stack->size - 1];
	stack->tab[stack->size - 1] = stack->tab[stack->size - 2];
	stack->tab[stack->size - 2] = tmp;
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	count++;
	//ft_printf("count : %d -- ", count);
	ft_printf("pa\n");
    stack_a->size += 1;
	stack_b->size -= 1;
	stack_a->tab[stack_a->size - 1] = stack_b->tab[stack_b->size];
	stack_b->tab[stack_b->size] = '\0';
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	count++;
	//ft_printf("count : %d -- ", count);
	ft_printf("pb\n");
    stack_b->size += 1;
	stack_a->size -= 1;
	stack_b->tab[stack_b->size - 1] = stack_a->tab[stack_a->size];
	stack_a->tab[stack_a->size] = '\0';
}

void	reverse(t_stack *stack, char c)
{
	int	tmp;

	tmp = stack->tab[0];
	count++;
	//ft_printf("count : %d -- ", count);
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
	ft_memmove(stack->tab, stack->tab + 1, stack->size * sizeof(int));
	stack->tab[stack->size - 1] = tmp;
}

void	rotate(t_stack *stack, char c)
{
	int	tmp;

	tmp = stack->tab[stack->size - 1];
	count++;
	//ft_printf("count : %d -- ", count);
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
	ft_memmove(stack->tab + 1, stack->tab, stack->size * sizeof(int));
	stack->tab[0] = tmp;
}
