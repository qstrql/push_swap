/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:56:32 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/11 23:22:37 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/INCLUDES/ft_printf.h"
#include "push_swap.h"
#include "libft/INCLUDES/libft.h"

void	ft_exec_rotate(t_stack *sa, t_stack *sb)
{
	while (sb->cost_a > 0)
	{
		rotate(sa, 'a');
		sb->cost_a--;
	}
	while (sb->cost_b > 0)
	{
		rotate(sb, 'b');
		sb->cost_b--;
	}
	if (sa->tab[sa->size - 1] > sb->tab[sb->size - 1])
		rotate(sa, 'a');
}

void	ft_exec_reverse(t_stack *sa, t_stack *sb)
{
	while (sb->cost_a < 0)
	{
		reverse(sa, 'a');
		sb->cost_a++;
	}
	while (sb->cost_b < 0)
	{
		reverse(sb, 'b');
		sb->cost_b++;
	}
	if (sa->tab[sa->size - 1] > sb->tab[sb->size - 1])
		rotate(sa, 'a');
}

void	ft_exec_rr(t_stack *sa, t_stack *sb)
{
	while (sb->cost_a > 0 || sb->cost_b > 0)
	{
		ft_printf("rr\n");
		rr(sa, sb);
		sb->cost_a--;
		sb->cost_b--;
	}
}

void	ft_exec_rrr(t_stack *sa, t_stack *sb)
{
	while (sb->cost_a < 0 || sb->cost_b < 0)
	{
		ft_printf("rrr\n");
		rrr(sa, sb);
		sb->cost_a++;
		sb->cost_b++;
	}
}

void	ft_exec_moves(t_stack *sa, t_stack *sb)
{
	// if (sb->cost_a > 0 && sb->cost_b > 0)
		// ft_exec_rr(sa, sb);
	// else if (sb->cost_a < 0 && sb->cost_b < 0)
		// ft_exec_rrr(sa, sb);	
	ft_exec_rotate(sa, sb);
	ft_exec_reverse(sa, sb);
	push_a(sa, sb);
}
