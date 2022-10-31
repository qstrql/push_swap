/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:09:38 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/31 22:07:26 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"

void	swap(t_stack *stack, char c)
{
	int	tmp;

	tmp = 0;
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
	tmp = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp;
}
/*
void	push(t_stack *stack_a, t_stack *stack_b, char c)
{
	if (c == 'a')
		ft_printf("pa\n");
	if (c == 'b')
		ft_printf("pb\n");
}
*/
void	rotate(t_stack *stack, char c)
{
	int	tmp;

	tmp = stack->tab[0];
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
	ft_memmove(stack->tab, stack->tab + 1, stack->size * sizeof(int));
	stack->tab[stack->size - 1] = tmp;
}

void	reverse(t_stack *stack, char c)
{
	int	tmp;

	tmp = stack->tab[stack->size - 1];
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
	ft_memmove(stack->tab + 1, stack->tab, stack->size * sizeof(int));	
	stack->tab[0] = tmp;
}
