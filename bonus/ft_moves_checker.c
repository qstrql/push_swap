/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:49:57 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/16 11:00:07 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../libft/INCLUDES/libft.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = 0;
	tmp = stack->tab[stack->size - 1];
	stack->tab[stack->size - 1] = stack->tab[stack->size - 2];
	stack->tab[stack->size - 2] = tmp;
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size < 1)
		return ;
	stack_a->size += 1;
	stack_b->size -= 1;
	stack_a->tab[stack_a->size - 1] = stack_b->tab[stack_b->size];
	stack_b->tab[stack_b->size] = '\0';
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 1)
		return ;
	stack_b->size += 1;
	stack_a->size -= 1;
	stack_b->tab[stack_b->size - 1] = stack_a->tab[stack_a->size];
	stack_a->tab[stack_a->size] = '\0';
}

void	reverse(t_stack *stack)
{
	int	tmp;

	if (stack->size < 1)
		return ;
	tmp = stack->tab[0];
	ft_memmove(stack->tab, stack->tab + 1, stack->size * sizeof(int));
	stack->tab[stack->size - 1] = tmp;
}

void	rotate(t_stack *stack)
{
	int	tmp;

	if (stack->size < 1)
		return ;
	tmp = stack->tab[stack->size - 1];
	ft_memmove(stack->tab + 1, stack->tab, stack->size * sizeof(int));
	stack->tab[0] = tmp;
}
